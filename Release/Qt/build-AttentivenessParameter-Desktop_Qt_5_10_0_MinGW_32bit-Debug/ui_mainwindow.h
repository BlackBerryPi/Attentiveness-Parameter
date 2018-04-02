/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *portLabel;
    QLabel *trafficLabel;
    QLabel *statusLabel;
    QLabel *baudRateLabel;
    QSpinBox *BaudRateSpinBox;
    QComboBox *serialPortComboBox;
    QGridLayout *gridLayout;
    QPushButton *runButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tempTab;
    QWidget *resistTab;
    QWidget *GyroXTab;
    QWidget *GyroYTab;
    QWidget *GyroZTab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(524, 700);
        MainWindow->setMinimumSize(QSize(520, 700));
        MainWindow->setMaximumSize(QSize(524, 700));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        portLabel = new QLabel(centralWidget);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        gridLayout_2->addWidget(portLabel, 0, 0, 1, 1);

        trafficLabel = new QLabel(centralWidget);
        trafficLabel->setObjectName(QStringLiteral("trafficLabel"));

        gridLayout_2->addWidget(trafficLabel, 2, 0, 1, 1);

        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        gridLayout_2->addWidget(statusLabel, 3, 0, 1, 1);

        baudRateLabel = new QLabel(centralWidget);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 1, 0, 1, 1);

        BaudRateSpinBox = new QSpinBox(centralWidget);
        BaudRateSpinBox->setObjectName(QStringLiteral("BaudRateSpinBox"));
        BaudRateSpinBox->setMaximum(20000);
        BaudRateSpinBox->setValue(9600);

        gridLayout_2->addWidget(BaudRateSpinBox, 1, 1, 1, 1);

        serialPortComboBox = new QComboBox(centralWidget);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));

        gridLayout_2->addWidget(serialPortComboBox, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        runButton = new QPushButton(centralWidget);
        runButton->setObjectName(QStringLiteral("runButton"));

        gridLayout->addWidget(runButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(500, 500));
        tabWidget->setMaximumSize(QSize(500, 500));
        tempTab = new QWidget();
        tempTab->setObjectName(QStringLiteral("tempTab"));
        tabWidget->addTab(tempTab, QString());
        resistTab = new QWidget();
        resistTab->setObjectName(QStringLiteral("resistTab"));
        tabWidget->addTab(resistTab, QString());
        GyroXTab = new QWidget();
        GyroXTab->setObjectName(QStringLiteral("GyroXTab"));
        tabWidget->addTab(GyroXTab, QString());
        GyroYTab = new QWidget();
        GyroYTab->setObjectName(QStringLiteral("GyroYTab"));
        tabWidget->addTab(GyroYTab, QString());
        GyroZTab = new QWidget();
        GyroZTab->setObjectName(QStringLiteral("GyroZTab"));
        tabWidget->addTab(GyroZTab, QString());

        horizontalLayout->addWidget(tabWidget);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 524, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        portLabel->setText(QApplication::translate("MainWindow", "Serial Port:", nullptr));
        trafficLabel->setText(QApplication::translate("MainWindow", "No traffic.", nullptr));
        statusLabel->setText(QApplication::translate("MainWindow", "Status: Not running.", nullptr));
        baudRateLabel->setText(QApplication::translate("MainWindow", "Baud Rate", nullptr));
        runButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tempTab), QApplication::translate("MainWindow", "Temp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(resistTab), QApplication::translate("MainWindow", "Resist", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(GyroXTab), QApplication::translate("MainWindow", "GyroX", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(GyroYTab), QApplication::translate("MainWindow", "GyroY", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(GyroZTab), QApplication::translate("MainWindow", "GyroZ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
