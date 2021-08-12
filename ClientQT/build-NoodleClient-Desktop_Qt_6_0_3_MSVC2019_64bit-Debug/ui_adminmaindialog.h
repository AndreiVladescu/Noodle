/********************************************************************************
** Form generated from reading UI file 'adminmaindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINDIALOG_H
#define UI_ADMINMAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdminMainDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *WelcomeLabel;
    QPushButton *manageUserAccount;
    QPushButton *seeUserAccount;
    QPushButton *accountInfo;
    QPushButton *changePassword;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *AdminMainDialog)
    {
        if (AdminMainDialog->objectName().isEmpty())
            AdminMainDialog->setObjectName(QString::fromUtf8("AdminMainDialog"));
        AdminMainDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(AdminMainDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WelcomeLabel = new QLabel(AdminMainDialog);
        WelcomeLabel->setObjectName(QString::fromUtf8("WelcomeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WelcomeLabel->sizePolicy().hasHeightForWidth());
        WelcomeLabel->setSizePolicy(sizePolicy);
        WelcomeLabel->setStyleSheet(QString::fromUtf8("font: 18pt \"Times New Roman\";"));

        verticalLayout->addWidget(WelcomeLabel);

        manageUserAccount = new QPushButton(AdminMainDialog);
        manageUserAccount->setObjectName(QString::fromUtf8("manageUserAccount"));

        verticalLayout->addWidget(manageUserAccount);

        seeUserAccount = new QPushButton(AdminMainDialog);
        seeUserAccount->setObjectName(QString::fromUtf8("seeUserAccount"));

        verticalLayout->addWidget(seeUserAccount);

        accountInfo = new QPushButton(AdminMainDialog);
        accountInfo->setObjectName(QString::fromUtf8("accountInfo"));

        verticalLayout->addWidget(accountInfo);

        changePassword = new QPushButton(AdminMainDialog);
        changePassword->setObjectName(QString::fromUtf8("changePassword"));

        verticalLayout->addWidget(changePassword);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(AdminMainDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignRight);


        retranslateUi(AdminMainDialog);

        QMetaObject::connectSlotsByName(AdminMainDialog);
    } // setupUi

    void retranslateUi(QDialog *AdminMainDialog)
    {
        AdminMainDialog->setWindowTitle(QCoreApplication::translate("AdminMainDialog", "Dialog", nullptr));
        WelcomeLabel->setText(QString());
        manageUserAccount->setText(QCoreApplication::translate("AdminMainDialog", "Add/ Delete user accounts", nullptr));
        seeUserAccount->setText(QCoreApplication::translate("AdminMainDialog", "See connected accounts", nullptr));
        accountInfo->setText(QCoreApplication::translate("AdminMainDialog", "Account info", nullptr));
        changePassword->setText(QCoreApplication::translate("AdminMainDialog", "Change account password", nullptr));
        pushButton->setText(QCoreApplication::translate("AdminMainDialog", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMainDialog: public Ui_AdminMainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINDIALOG_H
