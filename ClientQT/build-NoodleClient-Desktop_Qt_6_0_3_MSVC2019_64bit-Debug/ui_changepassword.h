/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *OldPassword;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *NewPassword1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *NewPassword2;
    QPushButton *confirmButton;
    QPushButton *BackButton;

    void setupUi(QDialog *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->resize(400, 185);
        verticalLayout = new QVBoxLayout(ChangePassword);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ChangePassword);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label, 0, Qt::AlignRight);

        OldPassword = new QLineEdit(ChangePassword);
        OldPassword->setObjectName(QString::fromUtf8("OldPassword"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(OldPassword->sizePolicy().hasHeightForWidth());
        OldPassword->setSizePolicy(sizePolicy1);
        OldPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(OldPassword);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ChangePassword);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2, 0, Qt::AlignRight);

        NewPassword1 = new QLineEdit(ChangePassword);
        NewPassword1->setObjectName(QString::fromUtf8("NewPassword1"));
        sizePolicy1.setHeightForWidth(NewPassword1->sizePolicy().hasHeightForWidth());
        NewPassword1->setSizePolicy(sizePolicy1);
        NewPassword1->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(NewPassword1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ChangePassword);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3, 0, Qt::AlignRight);

        NewPassword2 = new QLineEdit(ChangePassword);
        NewPassword2->setObjectName(QString::fromUtf8("NewPassword2"));
        sizePolicy1.setHeightForWidth(NewPassword2->sizePolicy().hasHeightForWidth());
        NewPassword2->setSizePolicy(sizePolicy1);
        NewPassword2->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(NewPassword2);


        verticalLayout->addLayout(horizontalLayout_3);

        confirmButton = new QPushButton(ChangePassword);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        verticalLayout->addWidget(confirmButton, 0, Qt::AlignHCenter);

        BackButton = new QPushButton(ChangePassword);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        verticalLayout->addWidget(BackButton, 0, Qt::AlignLeft|Qt::AlignBottom);


        retranslateUi(ChangePassword);
        QObject::connect(BackButton, &QPushButton::clicked, ChangePassword, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QDialog *ChangePassword)
    {
        ChangePassword->setWindowTitle(QCoreApplication::translate("ChangePassword", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChangePassword", "Old Password:", nullptr));
        label_2->setText(QCoreApplication::translate("ChangePassword", "New password:", nullptr));
        label_3->setText(QCoreApplication::translate("ChangePassword", "Repeat new password:", nullptr));
        confirmButton->setText(QCoreApplication::translate("ChangePassword", "Confirm", nullptr));
        BackButton->setText(QCoreApplication::translate("ChangePassword", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
