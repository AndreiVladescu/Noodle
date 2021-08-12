/********************************************************************************
** Form generated from reading UI file 'testdetails.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDETAILS_H
#define UI_TESTDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TestDetails
{
public:
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QLineEdit *testNameLE;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *availableTimeLE;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *numberQuestionsLE;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QTimeEdit *timeEdit;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QComboBox *subjectList;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *createButton;

    void setupUi(QDialog *TestDetails)
    {
        if (TestDetails->objectName().isEmpty())
            TestDetails->setObjectName(QString::fromUtf8("TestDetails"));
        TestDetails->resize(539, 557);
        verticalLayout_8 = new QVBoxLayout(TestDetails);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label = new QLabel(TestDetails);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Times New Roman\";"));

        verticalLayout_8->addWidget(label, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_8 = new QLabel(TestDetails);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8, 0, Qt::AlignHCenter);

        testNameLE = new QLineEdit(TestDetails);
        testNameLE->setObjectName(QString::fromUtf8("testNameLE"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(testNameLE->sizePolicy().hasHeightForWidth());
        testNameLE->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(testNameLE, 0, Qt::AlignHCenter);


        verticalLayout_8->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(TestDetails);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_6->addWidget(label_2, 0, Qt::AlignHCenter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        availableTimeLE = new QLineEdit(TestDetails);
        availableTimeLE->setObjectName(QString::fromUtf8("availableTimeLE"));
        sizePolicy1.setHeightForWidth(availableTimeLE->sizePolicy().hasHeightForWidth());
        availableTimeLE->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(availableTimeLE);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(TestDetails);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_5->addWidget(label_3, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        numberQuestionsLE = new QLineEdit(TestDetails);
        numberQuestionsLE->setObjectName(QString::fromUtf8("numberQuestionsLE"));
        sizePolicy1.setHeightForWidth(numberQuestionsLE->sizePolicy().hasHeightForWidth());
        numberQuestionsLE->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(numberQuestionsLE);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(TestDetails);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_4->addWidget(label_4, 0, Qt::AlignHCenter);

        dateEdit = new QDateEdit(TestDetails);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        sizePolicy1.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(dateEdit, 0, Qt::AlignHCenter);


        verticalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(TestDetails);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_3->addWidget(label_5, 0, Qt::AlignHCenter);

        timeEdit = new QTimeEdit(TestDetails);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        sizePolicy1.setHeightForWidth(timeEdit->sizePolicy().hasHeightForWidth());
        timeEdit->setSizePolicy(sizePolicy1);
        timeEdit->setMaximumTime(QTime(23, 59, 59));
        timeEdit->setCalendarPopup(false);
        timeEdit->setTimeSpec(Qt::LocalTime);

        verticalLayout_3->addWidget(timeEdit, 0, Qt::AlignHCenter);


        verticalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_6 = new QLabel(TestDetails);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_7->addWidget(label_6, 0, Qt::AlignHCenter);

        subjectList = new QComboBox(TestDetails);
        subjectList->addItem(QString());
        subjectList->addItem(QString());
        subjectList->addItem(QString());
        subjectList->addItem(QString());
        subjectList->addItem(QString());
        subjectList->setObjectName(QString::fromUtf8("subjectList"));
        sizePolicy1.setHeightForWidth(subjectList->sizePolicy().hasHeightForWidth());
        subjectList->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(subjectList, 0, Qt::AlignHCenter);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_2 = new QPushButton(TestDetails);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        createButton = new QPushButton(TestDetails);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        horizontalLayout_5->addWidget(createButton);


        verticalLayout_8->addLayout(horizontalLayout_5);


        retranslateUi(TestDetails);
        QObject::connect(pushButton_2, &QPushButton::clicked, TestDetails, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(TestDetails);
    } // setupUi

    void retranslateUi(QDialog *TestDetails)
    {
        TestDetails->setWindowTitle(QCoreApplication::translate("TestDetails", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TestDetails", "Create test", nullptr));
        label_8->setText(QCoreApplication::translate("TestDetails", "Test name:", nullptr));
        label_2->setText(QCoreApplication::translate("TestDetails", "Available time (in minutes):", nullptr));
        label_3->setText(QCoreApplication::translate("TestDetails", "Number of questions:", nullptr));
        label_4->setText(QCoreApplication::translate("TestDetails", "Date:", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("TestDetails", "d/M/yyyy", nullptr));
        label_5->setText(QCoreApplication::translate("TestDetails", "Time:", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("TestDetails", "hh:mm", nullptr));
        label_6->setText(QCoreApplication::translate("TestDetails", "Subject:", nullptr));
        subjectList->setItemText(0, QCoreApplication::translate("TestDetails", "Fizica", nullptr));
        subjectList->setItemText(1, QCoreApplication::translate("TestDetails", "Geografie", nullptr));
        subjectList->setItemText(2, QCoreApplication::translate("TestDetails", "Matematica", nullptr));
        subjectList->setItemText(3, QCoreApplication::translate("TestDetails", "Filosofie", nullptr));
        subjectList->setItemText(4, QCoreApplication::translate("TestDetails", "Romana", nullptr));

        pushButton_2->setText(QCoreApplication::translate("TestDetails", "Cancel", nullptr));
        createButton->setText(QCoreApplication::translate("TestDetails", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestDetails: public Ui_TestDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDETAILS_H
