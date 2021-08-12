/********************************************************************************
** Form generated from reading UI file 'accountinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTINFO_H
#define UI_ACCOUNTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_accountInfo
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *roleLabel;
    QLabel *role;
    QHBoxLayout *horizontalLayout_2;
    QLabel *userIdLabel;
    QLabel *ID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lastNameLabel;
    QLabel *lastName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *firstNameLabel;
    QLabel *firstName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *userNameLabel;
    QLabel *userName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *PasswdLabel;
    QLabel *passwrd;
    QHBoxLayout *horizontalLayout_7;
    QLabel *joinDateLabel;
    QLabel *joinDate;
    QHBoxLayout *horizontalLayout_9;
    QLabel *StudyYearLabel;
    QLabel *studyYear;
    QHBoxLayout *horizontalLayout_8;
    QLabel *StudyGroupLabel;
    QLabel *studyGroup;
    QHBoxLayout *horizontalLayout_10;
    QLabel *subjectLabel;
    QLabel *subject;
    QPushButton *pushButton;

    void setupUi(QDialog *accountInfo)
    {
        if (accountInfo->objectName().isEmpty())
            accountInfo->setObjectName(QString::fromUtf8("accountInfo"));
        accountInfo->resize(458, 511);
        verticalLayout = new QVBoxLayout(accountInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        roleLabel = new QLabel(accountInfo);
        roleLabel->setObjectName(QString::fromUtf8("roleLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(roleLabel->sizePolicy().hasHeightForWidth());
        roleLabel->setSizePolicy(sizePolicy);
        roleLabel->setCursor(QCursor(Qt::IBeamCursor));
        roleLabel->setLayoutDirection(Qt::LeftToRight);
        roleLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        roleLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(roleLabel, 0, Qt::AlignRight);

        role = new QLabel(accountInfo);
        role->setObjectName(QString::fromUtf8("role"));
        role->setCursor(QCursor(Qt::IBeamCursor));
        role->setMouseTracking(false);
        role->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        role->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(role);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        userIdLabel = new QLabel(accountInfo);
        userIdLabel->setObjectName(QString::fromUtf8("userIdLabel"));
        userIdLabel->setCursor(QCursor(Qt::IBeamCursor));
        userIdLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        userIdLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(userIdLabel, 0, Qt::AlignRight);

        ID = new QLabel(accountInfo);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setCursor(QCursor(Qt::IBeamCursor));
        ID->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        ID->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(ID);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lastNameLabel = new QLabel(accountInfo);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));
        lastNameLabel->setCursor(QCursor(Qt::IBeamCursor));
        lastNameLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        lastNameLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(lastNameLabel, 0, Qt::AlignRight);

        lastName = new QLabel(accountInfo);
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastName->setCursor(QCursor(Qt::IBeamCursor));
        lastName->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        lastName->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(lastName);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        firstNameLabel = new QLabel(accountInfo);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));
        firstNameLabel->setCursor(QCursor(Qt::IBeamCursor));
        firstNameLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        firstNameLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(firstNameLabel, 0, Qt::AlignRight);

        firstName = new QLabel(accountInfo);
        firstName->setObjectName(QString::fromUtf8("firstName"));
        firstName->setCursor(QCursor(Qt::IBeamCursor));
        firstName->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        firstName->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(firstName);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        userNameLabel = new QLabel(accountInfo);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setCursor(QCursor(Qt::IBeamCursor));
        userNameLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        userNameLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_5->addWidget(userNameLabel, 0, Qt::AlignRight);

        userName = new QLabel(accountInfo);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setCursor(QCursor(Qt::IBeamCursor));
        userName->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        userName->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_5->addWidget(userName);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        PasswdLabel = new QLabel(accountInfo);
        PasswdLabel->setObjectName(QString::fromUtf8("PasswdLabel"));
        PasswdLabel->setCursor(QCursor(Qt::IBeamCursor));
        PasswdLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        PasswdLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_6->addWidget(PasswdLabel, 0, Qt::AlignRight);

        passwrd = new QLabel(accountInfo);
        passwrd->setObjectName(QString::fromUtf8("passwrd"));
        passwrd->setCursor(QCursor(Qt::IBeamCursor));
        passwrd->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        passwrd->setFrameShadow(QFrame::Plain);
        passwrd->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_6->addWidget(passwrd);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        joinDateLabel = new QLabel(accountInfo);
        joinDateLabel->setObjectName(QString::fromUtf8("joinDateLabel"));
        joinDateLabel->setCursor(QCursor(Qt::IBeamCursor));
        joinDateLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        joinDateLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_7->addWidget(joinDateLabel, 0, Qt::AlignRight);

        joinDate = new QLabel(accountInfo);
        joinDate->setObjectName(QString::fromUtf8("joinDate"));
        joinDate->setCursor(QCursor(Qt::IBeamCursor));
        joinDate->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        joinDate->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_7->addWidget(joinDate);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        StudyYearLabel = new QLabel(accountInfo);
        StudyYearLabel->setObjectName(QString::fromUtf8("StudyYearLabel"));
        StudyYearLabel->setCursor(QCursor(Qt::IBeamCursor));
        StudyYearLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        StudyYearLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_9->addWidget(StudyYearLabel, 0, Qt::AlignRight);

        studyYear = new QLabel(accountInfo);
        studyYear->setObjectName(QString::fromUtf8("studyYear"));
        studyYear->setCursor(QCursor(Qt::IBeamCursor));
        studyYear->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        studyYear->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_9->addWidget(studyYear);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        StudyGroupLabel = new QLabel(accountInfo);
        StudyGroupLabel->setObjectName(QString::fromUtf8("StudyGroupLabel"));
        StudyGroupLabel->setCursor(QCursor(Qt::IBeamCursor));
        StudyGroupLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        StudyGroupLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_8->addWidget(StudyGroupLabel, 0, Qt::AlignRight);

        studyGroup = new QLabel(accountInfo);
        studyGroup->setObjectName(QString::fromUtf8("studyGroup"));
        studyGroup->setCursor(QCursor(Qt::IBeamCursor));
        studyGroup->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        studyGroup->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_8->addWidget(studyGroup);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        subjectLabel = new QLabel(accountInfo);
        subjectLabel->setObjectName(QString::fromUtf8("subjectLabel"));
        subjectLabel->setCursor(QCursor(Qt::IBeamCursor));
        subjectLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        subjectLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_10->addWidget(subjectLabel, 0, Qt::AlignRight);

        subject = new QLabel(accountInfo);
        subject->setObjectName(QString::fromUtf8("subject"));
        subject->setCursor(QCursor(Qt::IBeamCursor));
        subject->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        subject->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_10->addWidget(subject);


        verticalLayout->addLayout(horizontalLayout_10);

        pushButton = new QPushButton(accountInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignLeft);


        retranslateUi(accountInfo);
        QObject::connect(pushButton, &QPushButton::clicked, accountInfo, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(accountInfo);
    } // setupUi

    void retranslateUi(QDialog *accountInfo)
    {
        accountInfo->setWindowTitle(QCoreApplication::translate("accountInfo", "Dialog", nullptr));
        roleLabel->setText(QCoreApplication::translate("accountInfo", "Role:", nullptr));
        role->setText(QString());
        userIdLabel->setText(QCoreApplication::translate("accountInfo", "User ID:", nullptr));
        ID->setText(QString());
        lastNameLabel->setText(QCoreApplication::translate("accountInfo", "Last Name:", nullptr));
        lastName->setText(QString());
        firstNameLabel->setText(QCoreApplication::translate("accountInfo", "First Name:", nullptr));
        firstName->setText(QString());
        userNameLabel->setText(QCoreApplication::translate("accountInfo", "Username:", nullptr));
        userName->setText(QString());
        PasswdLabel->setText(QCoreApplication::translate("accountInfo", "Password:", nullptr));
        passwrd->setText(QString());
        joinDateLabel->setText(QCoreApplication::translate("accountInfo", "Join Date:", nullptr));
        joinDate->setText(QString());
        StudyYearLabel->setText(QCoreApplication::translate("accountInfo", "Study Year:", nullptr));
        studyYear->setText(QString());
        StudyGroupLabel->setText(QCoreApplication::translate("accountInfo", "Study Group:", nullptr));
        studyGroup->setText(QString());
        subjectLabel->setText(QCoreApplication::translate("accountInfo", "Subject:", nullptr));
        subject->setText(QString());
        pushButton->setText(QCoreApplication::translate("accountInfo", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accountInfo: public Ui_accountInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTINFO_H
