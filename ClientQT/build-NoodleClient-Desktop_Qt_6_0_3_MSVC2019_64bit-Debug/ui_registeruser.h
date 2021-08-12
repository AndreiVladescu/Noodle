/********************************************************************************
** Form generated from reading UI file 'registeruser.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSER_H
#define UI_REGISTERUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registerUser
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *LastNameLabel;
    QLineEdit *lastNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *FirstNameLabel;
    QLineEdit *firstNameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *password1Label;
    QLineEdit *password1Edit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *password2Label;
    QLineEdit *password2Edit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *roleLabel;
    QVBoxLayout *verticalLayout;
    QRadioButton *adminRadioButton;
    QRadioButton *professorRadioButton;
    QRadioButton *studentRadioButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *studyGroupLabel;
    QLineEdit *studyGroupEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *studyYearLabel;
    QLineEdit *studyYearEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *backButton;
    QPushButton *confirmButton;

    void setupUi(QDialog *registerUser)
    {
        if (registerUser->objectName().isEmpty())
            registerUser->setObjectName(QString::fromUtf8("registerUser"));
        registerUser->resize(384, 409);
        verticalLayout_2 = new QVBoxLayout(registerUser);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LastNameLabel = new QLabel(registerUser);
        LastNameLabel->setObjectName(QString::fromUtf8("LastNameLabel"));
        LastNameLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout->addWidget(LastNameLabel);

        lastNameEdit = new QLineEdit(registerUser);
        lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));

        horizontalLayout->addWidget(lastNameEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        FirstNameLabel = new QLabel(registerUser);
        FirstNameLabel->setObjectName(QString::fromUtf8("FirstNameLabel"));
        FirstNameLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_2->addWidget(FirstNameLabel);

        firstNameEdit = new QLineEdit(registerUser);
        firstNameEdit->setObjectName(QString::fromUtf8("firstNameEdit"));

        horizontalLayout_2->addWidget(firstNameEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        usernameLabel = new QLabel(registerUser);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_3->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(registerUser);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        horizontalLayout_3->addWidget(usernameEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        password1Label = new QLabel(registerUser);
        password1Label->setObjectName(QString::fromUtf8("password1Label"));
        password1Label->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_4->addWidget(password1Label);

        password1Edit = new QLineEdit(registerUser);
        password1Edit->setObjectName(QString::fromUtf8("password1Edit"));
        password1Edit->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(password1Edit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        password2Label = new QLabel(registerUser);
        password2Label->setObjectName(QString::fromUtf8("password2Label"));
        password2Label->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_5->addWidget(password2Label);

        password2Edit = new QLineEdit(registerUser);
        password2Edit->setObjectName(QString::fromUtf8("password2Edit"));
        password2Edit->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(password2Edit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        roleLabel = new QLabel(registerUser);
        roleLabel->setObjectName(QString::fromUtf8("roleLabel"));
        roleLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_6->addWidget(roleLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        adminRadioButton = new QRadioButton(registerUser);
        adminRadioButton->setObjectName(QString::fromUtf8("adminRadioButton"));

        verticalLayout->addWidget(adminRadioButton);

        professorRadioButton = new QRadioButton(registerUser);
        professorRadioButton->setObjectName(QString::fromUtf8("professorRadioButton"));

        verticalLayout->addWidget(professorRadioButton);

        studentRadioButton = new QRadioButton(registerUser);
        studentRadioButton->setObjectName(QString::fromUtf8("studentRadioButton"));

        verticalLayout->addWidget(studentRadioButton);


        horizontalLayout_6->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        studyGroupLabel = new QLabel(registerUser);
        studyGroupLabel->setObjectName(QString::fromUtf8("studyGroupLabel"));
        studyGroupLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_7->addWidget(studyGroupLabel);

        studyGroupEdit = new QLineEdit(registerUser);
        studyGroupEdit->setObjectName(QString::fromUtf8("studyGroupEdit"));

        horizontalLayout_7->addWidget(studyGroupEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        studyYearLabel = new QLabel(registerUser);
        studyYearLabel->setObjectName(QString::fromUtf8("studyYearLabel"));
        studyYearLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_8->addWidget(studyYearLabel);

        studyYearEdit = new QLineEdit(registerUser);
        studyYearEdit->setObjectName(QString::fromUtf8("studyYearEdit"));

        horizontalLayout_8->addWidget(studyYearEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        backButton = new QPushButton(registerUser);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_9->addWidget(backButton, 0, Qt::AlignLeft);

        confirmButton = new QPushButton(registerUser);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        horizontalLayout_9->addWidget(confirmButton, 0, Qt::AlignRight);


        verticalLayout_2->addLayout(horizontalLayout_9);


        retranslateUi(registerUser);
        QObject::connect(backButton, &QPushButton::clicked, registerUser, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(registerUser);
    } // setupUi

    void retranslateUi(QDialog *registerUser)
    {
        registerUser->setWindowTitle(QCoreApplication::translate("registerUser", "Dialog", nullptr));
        LastNameLabel->setText(QCoreApplication::translate("registerUser", "Last Name:", nullptr));
        FirstNameLabel->setText(QCoreApplication::translate("registerUser", "First name:", nullptr));
        usernameLabel->setText(QCoreApplication::translate("registerUser", "Username:", nullptr));
        password1Label->setText(QCoreApplication::translate("registerUser", "Password:", nullptr));
        password2Label->setText(QCoreApplication::translate("registerUser", "Repeat password:", nullptr));
        roleLabel->setText(QCoreApplication::translate("registerUser", "Role:", nullptr));
        adminRadioButton->setText(QCoreApplication::translate("registerUser", "Admin", nullptr));
        professorRadioButton->setText(QCoreApplication::translate("registerUser", "Profesor", nullptr));
        studentRadioButton->setText(QCoreApplication::translate("registerUser", "Student", nullptr));
        studyGroupLabel->setText(QCoreApplication::translate("registerUser", "Study group:", nullptr));
        studyYearLabel->setText(QCoreApplication::translate("registerUser", "Study year:", nullptr));
        backButton->setText(QCoreApplication::translate("registerUser", "Back", nullptr));
        confirmButton->setText(QCoreApplication::translate("registerUser", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerUser: public Ui_registerUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSER_H
