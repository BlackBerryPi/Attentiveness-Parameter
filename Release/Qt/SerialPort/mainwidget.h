#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSerialPortInfo>
#include <QSpinBox>

#include "slavethread.h"
#include "drawwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void startSlave();
    void showRequest(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);
    void activateRunButton();

private:
    int m_transactionCount = 0;

    DrawWidget *drawWidget = nullptr;

    QLabel *m_serialPortLabel = nullptr;
    QComboBox *m_serialPortComboBox = nullptr;
    QLabel *m_waitRequestLabel = nullptr;
    QSpinBox *m_waitRequestSpinBox = nullptr;
//    QLabel *m_responseLabel = nullptr;
//    QLineEdit *m_responseLineEdit = nullptr;
    QLabel *m_trafficLabel = nullptr;
    QLabel *m_statusLabel = nullptr;
    QPushButton *m_runButton = nullptr;

    SlaveThread m_thread;


};

#endif // MAINWIDGET_H
