/********************************************************************************
** Form generated from reading UI file 'adminmain.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAIN_H
#define UI_ADMINMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMain
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMain)
    {
        if (AdminMain->objectName().isEmpty())
            AdminMain->setObjectName(QString::fromUtf8("AdminMain"));
        AdminMain->resize(800, 600);
        centralwidget = new QWidget(AdminMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 260, 93, 28));
        AdminMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        AdminMain->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminMain->setStatusBar(statusbar);

        retranslateUi(AdminMain);
        QObject::connect(pushButton, &QPushButton::clicked, AdminMain, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(AdminMain);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMain)
    {
        AdminMain->setWindowTitle(QCoreApplication::translate("AdminMain", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("AdminMain", "log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMain: public Ui_AdminMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAIN_H
