#include "mainwidget.h"
#include "drawwidget.h"

#include <QDebug>
#include <QString>

#define BOLDER_RATE 9600

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    m_serialPortLabel(new QLabel(tr("Serial port:"))),
    m_serialPortComboBox(new QComboBox),
    m_waitRequestLabel(new QLabel(tr("Wait request, msec:"))),
    m_waitRequestSpinBox(new QSpinBox),
//    m_responseLabel(new QLabel(tr("Response:"))),
//    m_responseLineEdit(new QLineEdit(tr("Hello, I'm Slave."))),
    m_trafficLabel(new QLabel(tr("No traffic."))),
    m_statusLabel(new QLabel(tr("Status: Not running."))),
    m_runButton(new QPushButton(tr("Start")))
{
    m_waitRequestSpinBox->setRange(0, BOLDER_RATE);
    m_waitRequestSpinBox->setValue(BOLDER_RATE);

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        m_serialPortComboBox->addItem(info.portName());

    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(m_serialPortLabel, 0, 0);
    mainLayout->addWidget(m_serialPortComboBox, 0, 1);
    mainLayout->addWidget(m_waitRequestLabel, 1, 0);
    mainLayout->addWidget(m_waitRequestSpinBox, 1, 1);
    mainLayout->addWidget(m_runButton, 0, 2, 2, 1);
//    mainLayout->addWidget(m_responseLabel, 2, 0);
//    mainLayout->addWidget(m_responseLineEdit, 2, 1, 1, 3);
//    mainLayout->addWidget(m_trafficLabel, 2, 0, 1, 0);
    mainLayout->addWidget(m_trafficLabel, 2, 0);
    mainLayout->addWidget(m_statusLabel, 3, 0);
    setLayout(mainLayout);

    setWindowTitle(tr("Seial Painter"));
    m_serialPortComboBox->setFocus();

    connect(m_runButton, &QPushButton::clicked, this, &MainWidget::startSlave);
    connect(&m_thread, &SlaveThread::request, this,&MainWidget::showRequest);
    connect(&m_thread, &SlaveThread::error, this, &MainWidget::processError);
    connect(&m_thread, &SlaveThread::timeout, this, &MainWidget::processTimeout);

    connect(m_serialPortComboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            this, &MainWidget::activateRunButton);
    connect(m_waitRequestSpinBox, QOverload<const QString &>::of(&QSpinBox::valueChanged),
            this, &MainWidget::activateRunButton);
//    connect(m_responseLineEdit, &QLineEdit::textChanged, this, &MainWidget::activateRunButton);

//    setFixedSize(500, 500);
}


MainWidget::~MainWidget()
{
}

void MainWidget::startSlave()
{
    drawWidget = new DrawWidget();
    drawWidget->move(this->x(), this->y()+this->height()+40);
    drawWidget->show();

//    while(true) {
//        drawWidget->setData(200);
//    }

    m_runButton->setEnabled(false);
    m_statusLabel->setText(tr("Status: Running, connected to port %1.")
                           .arg(m_serialPortComboBox->currentText()));
    m_thread.startSlave(m_serialPortComboBox->currentText(),
                        m_waitRequestSpinBox->value(),
                        "a");
}

void MainWidget::showRequest(const QString &s)
{
    m_trafficLabel->setText(tr("Traffic, transaction #%1:"
                               "\n\r-request: %2"
                               "\n\r-response: %3")
                            .arg(++m_transactionCount)
                            .arg(s)
                            .arg(""));

    //qDebug() << "Request: "<< tr("%1").arg(s);
    qDebug() << "Receives: " << s;

    drawWidget->setData(s.mid(0,1), s.mid(1).toInt());
}

void MainWidget::processError(const QString &s)
{
    activateRunButton();
    m_statusLabel->setText(tr("Status: Not running, %1.").arg(s));
    m_trafficLabel->setText(tr("No traffic."));
}

void MainWidget::processTimeout(const QString &s)
{
    m_statusLabel->setText(tr("Status: Running, %1.").arg(s));
    m_trafficLabel->setText(tr("No traffic."));
}

void MainWidget::activateRunButton()
{
    m_runButton->setEnabled(true);
}


