/********************************************************************************
** Form generated from reading UI file 'profcreatetest.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFCREATETEST_H
#define UI_PROFCREATETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profCreateTest
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QDateTimeEdit *dateTimeEdit_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *DomainName;
    QComboBox *comboBoxGroups;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *createTestButton;

    void setupUi(QWidget *profCreateTest)
    {
        if (profCreateTest->objectName().isEmpty())
            profCreateTest->setObjectName(QString::fromUtf8("profCreateTest"));
        profCreateTest->resize(453, 297);
        horizontalLayout_6 = new QHBoxLayout(profCreateTest);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(profCreateTest);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(profCreateTest);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(profCreateTest);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit, 0, Qt::AlignLeft);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        label_3 = new QLabel(profCreateTest);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_2 = new QLineEdit(profCreateTest);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_4 = new QLabel(profCreateTest);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dateTimeEdit = new QDateTimeEdit(profCreateTest);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_3->addWidget(dateTimeEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        label_5 = new QLabel(profCreateTest);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dateTimeEdit_2 = new QDateTimeEdit(profCreateTest);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout_4->addWidget(dateTimeEdit_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DomainName = new QTableWidget(profCreateTest);
        DomainName->setObjectName(QString::fromUtf8("DomainName"));

        verticalLayout_2->addWidget(DomainName);

        comboBoxGroups = new QComboBox(profCreateTest);
        comboBoxGroups->addItem(QString());
        comboBoxGroups->addItem(QString());
        comboBoxGroups->setObjectName(QString::fromUtf8("comboBoxGroups"));

        verticalLayout_2->addWidget(comboBoxGroups);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton = new QPushButton(profCreateTest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        createTestButton = new QPushButton(profCreateTest);
        createTestButton->setObjectName(QString::fromUtf8("createTestButton"));

        horizontalLayout_5->addWidget(createTestButton);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_2);


        retranslateUi(profCreateTest);
        QObject::connect(pushButton, &QPushButton::clicked, profCreateTest, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(profCreateTest);
    } // setupUi

    void retranslateUi(QWidget *profCreateTest)
    {
        profCreateTest->setWindowTitle(QCoreApplication::translate("profCreateTest", "Form", nullptr));
        label->setText(QCoreApplication::translate("profCreateTest", "Create test", nullptr));
        label_2->setText(QCoreApplication::translate("profCreateTest", "Available time(in minutes):", nullptr));
        label_3->setText(QCoreApplication::translate("profCreateTest", "Number of questions:", nullptr));
        label_4->setText(QCoreApplication::translate("profCreateTest", "Start time:", nullptr));
        label_5->setText(QCoreApplication::translate("profCreateTest", "End time:", nullptr));
        comboBoxGroups->setItemText(0, QCoreApplication::translate("profCreateTest", "C112E", nullptr));
        comboBoxGroups->setItemText(1, QCoreApplication::translate("profCreateTest", "C112D", nullptr));

        pushButton->setText(QCoreApplication::translate("profCreateTest", "Cancel", nullptr));
        createTestButton->setText(QCoreApplication::translate("profCreateTest", "CreateTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profCreateTest: public Ui_profCreateTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFCREATETEST_H
