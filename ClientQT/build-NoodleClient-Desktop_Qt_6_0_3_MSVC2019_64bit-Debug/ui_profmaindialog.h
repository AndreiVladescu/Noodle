/********************************************************************************
** Form generated from reading UI file 'profmaindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFMAINDIALOG_H
#define UI_PROFMAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProfMainDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *WelcomeLabel;
    QPushButton *TestListButton;
    QPushButton *testResultsButton;
    QPushButton *accountInfo;
    QPushButton *changePasswordButton;
    QSpacerItem *verticalSpacer;
    QPushButton *logOutButton;

    void setupUi(QDialog *ProfMainDialog)
    {
        if (ProfMainDialog->objectName().isEmpty())
            ProfMainDialog->setObjectName(QString::fromUtf8("ProfMainDialog"));
        ProfMainDialog->resize(473, 342);
        verticalLayout = new QVBoxLayout(ProfMainDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WelcomeLabel = new QLabel(ProfMainDialog);
        WelcomeLabel->setObjectName(QString::fromUtf8("WelcomeLabel"));
        WelcomeLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout->addWidget(WelcomeLabel);

        TestListButton = new QPushButton(ProfMainDialog);
        TestListButton->setObjectName(QString::fromUtf8("TestListButton"));

        verticalLayout->addWidget(TestListButton);

        testResultsButton = new QPushButton(ProfMainDialog);
        testResultsButton->setObjectName(QString::fromUtf8("testResultsButton"));

        verticalLayout->addWidget(testResultsButton);

        accountInfo = new QPushButton(ProfMainDialog);
        accountInfo->setObjectName(QString::fromUtf8("accountInfo"));

        verticalLayout->addWidget(accountInfo);

        changePasswordButton = new QPushButton(ProfMainDialog);
        changePasswordButton->setObjectName(QString::fromUtf8("changePasswordButton"));

        verticalLayout->addWidget(changePasswordButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        logOutButton = new QPushButton(ProfMainDialog);
        logOutButton->setObjectName(QString::fromUtf8("logOutButton"));

        verticalLayout->addWidget(logOutButton, 0, Qt::AlignRight);


        retranslateUi(ProfMainDialog);

        QMetaObject::connectSlotsByName(ProfMainDialog);
    } // setupUi

    void retranslateUi(QDialog *ProfMainDialog)
    {
        ProfMainDialog->setWindowTitle(QCoreApplication::translate("ProfMainDialog", "Dialog", nullptr));
        WelcomeLabel->setText(QString());
        TestListButton->setText(QCoreApplication::translate("ProfMainDialog", "Tests", nullptr));
        testResultsButton->setText(QCoreApplication::translate("ProfMainDialog", "See/Modify students grades", nullptr));
        accountInfo->setText(QCoreApplication::translate("ProfMainDialog", "Account info", nullptr));
        changePasswordButton->setText(QCoreApplication::translate("ProfMainDialog", "Change password", nullptr));
        logOutButton->setText(QCoreApplication::translate("ProfMainDialog", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfMainDialog: public Ui_ProfMainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFMAINDIALOG_H
