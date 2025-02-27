/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QProgressBar *CPUprogressBar;
    QProgressBar *GPUprogressBar;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuToolBoxPC_Windows;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(160, 50, 141, 61));
        label->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        CPUprogressBar = new QProgressBar(centralwidget);
        CPUprogressBar->setObjectName("CPUprogressBar");
        CPUprogressBar->setGeometry(QRect(310, 70, 118, 23));
        CPUprogressBar->setValue(24);
        GPUprogressBar = new QProgressBar(centralwidget);
        GPUprogressBar->setObjectName("GPUprogressBar");
        GPUprogressBar->setGeometry(QRect(310, 110, 118, 23));
        GPUprogressBar->setValue(24);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(160, 90, 141, 61));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuToolBoxPC_Windows = new QMenu(menubar);
        menuToolBoxPC_Windows->setObjectName("menuToolBoxPC_Windows");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuToolBoxPC_Windows->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CPU Usage:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "GPU Usage:", nullptr));
        menuToolBoxPC_Windows->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
