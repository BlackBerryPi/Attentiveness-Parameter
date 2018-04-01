#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startSlave();
    void showRequest(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);
    void activateRunButton();

private:
    Ui::MainWindow *ui;
    SlaveThread m_thread;

    bool threadRunFlag = true;
    int m_transactionCount = 0;

    DrawWidget *tempWidget = nullptr;
    DrawWidget *resistWidget = nullptr;
    DrawWidget *acceleroMeterWidget = nullptr;
};

#endif // MAINWINDOW_H
