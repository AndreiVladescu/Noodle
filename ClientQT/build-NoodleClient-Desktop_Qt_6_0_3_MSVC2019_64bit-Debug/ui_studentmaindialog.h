/********************************************************************************
** Form generated from reading UI file 'studentmaindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMAINDIALOG_H
#define UI_STUDENTMAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentMainDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *WelcomeLabel;
    QPushButton *examButton;
    QPushButton *gradesButton;
    QPushButton *groupStatisticButton;
    QPushButton *accountInfo;
    QPushButton *changePasswButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *StudentMainDialog)
    {
        if (StudentMainDialog->objectName().isEmpty())
            StudentMainDialog->setObjectName(QString::fromUtf8("StudentMainDialog"));
        StudentMainDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(StudentMainDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WelcomeLabel = new QLabel(StudentMainDialog);
        WelcomeLabel->setObjectName(QString::fromUtf8("WelcomeLabel"));
        WelcomeLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout->addWidget(WelcomeLabel);

        examButton = new QPushButton(StudentMainDialog);
        examButton->setObjectName(QString::fromUtf8("examButton"));

        verticalLayout->addWidget(examButton);

        gradesButton = new QPushButton(StudentMainDialog);
        gradesButton->setObjectName(QString::fromUtf8("gradesButton"));

        verticalLayout->addWidget(gradesButton);

        groupStatisticButton = new QPushButton(StudentMainDialog);
        groupStatisticButton->setObjectName(QString::fromUtf8("groupStatisticButton"));

        verticalLayout->addWidget(groupStatisticButton);

        accountInfo = new QPushButton(StudentMainDialog);
        accountInfo->setObjectName(QString::fromUtf8("accountInfo"));

        verticalLayout->addWidget(accountInfo);

        changePasswButton = new QPushButton(StudentMainDialog);
        changePasswButton->setObjectName(QString::fromUtf8("changePasswButton"));

        verticalLayout->addWidget(changePasswButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(StudentMainDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignRight|Qt::AlignBottom);


        retranslateUi(StudentMainDialog);

        QMetaObject::connectSlotsByName(StudentMainDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentMainDialog)
    {
        StudentMainDialog->setWindowTitle(QCoreApplication::translate("StudentMainDialog", "Dialog", nullptr));
        WelcomeLabel->setText(QString());
        examButton->setText(QCoreApplication::translate("StudentMainDialog", "Exams", nullptr));
        gradesButton->setText(QCoreApplication::translate("StudentMainDialog", "Grades", nullptr));
        groupStatisticButton->setText(QCoreApplication::translate("StudentMainDialog", "Group statistics", nullptr));
        accountInfo->setText(QCoreApplication::translate("StudentMainDialog", "Account info", nullptr));
        changePasswButton->setText(QCoreApplication::translate("StudentMainDialog", "Change password account", nullptr));
        pushButton->setText(QCoreApplication::translate("StudentMainDialog", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentMainDialog: public Ui_StudentMainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMAINDIALOG_H
