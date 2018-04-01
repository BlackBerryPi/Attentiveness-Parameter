#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BaudRateSpinBox->setValue(9600);

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->serialPortComboBox->addItem(info.portName());

    setWindowTitle(tr("Seial Painter"));
    ui->serialPortComboBox->setFocus();

    tempWidget = new DrawWidget(ui->tempTab);
    resistWidget = new DrawWidget(ui->resistTab);

    connect(ui->runButton, &QPushButton::clicked, this, &MainWindow::startSlave);
    connect(&m_thread, &SlaveThread::request, this,&MainWindow::showRequest);
    connect(&m_thread, &SlaveThread::error, this, &MainWindow::processError);
    connect(&m_thread, &SlaveThread::timeout, this, &MainWindow::processTimeout);

    connect(ui->serialPortComboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::activateRunButton);
    connect(ui->BaudRateSpinBox, QOverload<const QString &>::of(&QSpinBox::valueChanged),
            this, &MainWindow::activateRunButton);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startSlave()
{
//    drawWidget = new DrawWidget();
//    drawWidget->move(this->x(), this->y()+this->height()+40);
//    drawWidget->show();

    ui->runButton->setEnabled(false);
//    ui->runButton->setText("Stop");
    ui->statusLabel->setText(tr("Status: Running, connected to port %1.")
                           .arg(ui->serialPortComboBox->currentText()));
    if(threadRunFlag)
    {
        qDebug() << "run";
        m_thread.startSlave(ui->serialPortComboBox->currentText(),
                            ui->BaudRateSpinBox->value(),
                            "a");
    }
}

void MainWindow::showRequest(const QString &s)
{
    ui->trafficLabel->setText(tr("Traffic, transaction #%1:"
                               "\n\r-request: %2"
                               "\n\r-response: %3")
                            .arg(++m_transactionCount)
                            .arg(s)
                            .arg(""));

    //qDebug() << "Request: "<< tr("%1").arg(s);
    qDebug() << "Receives: " << s;

    QStringList sList = s.split(';');

    for(QStringList::iterator it = sList.begin(); it != sList.end(); it++)
    {
        qDebug() << "split " << (*it);
        if(!((*it).mid(0,1).compare("T")))
        {
            tempWidget->setData(100-(2*((*it).mid(1).toInt())));
        }
        else if(!((*it).mid(0,1).compare("R")))
        {
            resistWidget->setData(100-(2*((*it).mid(1).toInt())));
        }
    }

    //    drawWidget->setData(s.mid(0,1), s.mid(1).toInt());
}

void MainWindow::processError(const QString &s)
{
    activateRunButton();
    ui->statusLabel->setText(tr("Status: Not running, %1.").arg(s));
    ui->trafficLabel->setText(tr("No traffic."));
}

void MainWindow::processTimeout(const QString &s)
{
    ui->statusLabel->setText(tr("Status: Running, %1.").arg(s));
    ui->trafficLabel->setText(tr("No traffic."));
}

void MainWindow::activateRunButton()
{
    ui->runButton->setEnabled(true);
}


