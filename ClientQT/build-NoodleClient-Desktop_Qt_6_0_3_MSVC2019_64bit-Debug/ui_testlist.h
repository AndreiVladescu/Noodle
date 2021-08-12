/********************************************************************************
** Form generated from reading UI file 'testlist.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTLIST_H
#define UI_TESTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TestList
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *subjectLabel;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *subjectComboBox;
    QPushButton *setSubjectButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *assignGroupsList;
    QPushButton *assignButton;
    QTableWidget *testsTableList;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *refreshButton;
    QPushButton *createTestButton;

    void setupUi(QDialog *TestList)
    {
        if (TestList->objectName().isEmpty())
            TestList->setObjectName(QString::fromUtf8("TestList"));
        TestList->resize(696, 622);
        verticalLayout_3 = new QVBoxLayout(TestList);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label = new QLabel(TestList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";\n"
"font: 18pt \"Times New Roman\";"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        subjectLabel = new QLabel(TestList);
        subjectLabel->setObjectName(QString::fromUtf8("subjectLabel"));
        subjectLabel->setStyleSheet(QString::fromUtf8("font: 18pt \"Times New Roman\";"));

        verticalLayout_2->addWidget(subjectLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        subjectComboBox = new QComboBox(TestList);
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->setObjectName(QString::fromUtf8("subjectComboBox"));

        horizontalLayout_2->addWidget(subjectComboBox);

        setSubjectButton = new QPushButton(TestList);
        setSubjectButton->setObjectName(QString::fromUtf8("setSubjectButton"));

        horizontalLayout_2->addWidget(setSubjectButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(TestList);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt \"Times New Roman\";"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        assignGroupsList = new QComboBox(TestList);
        assignGroupsList->addItem(QString());
        assignGroupsList->addItem(QString());
        assignGroupsList->addItem(QString());
        assignGroupsList->addItem(QString());
        assignGroupsList->addItem(QString());
        assignGroupsList->setObjectName(QString::fromUtf8("assignGroupsList"));

        horizontalLayout_3->addWidget(assignGroupsList);

        assignButton = new QPushButton(TestList);
        assignButton->setObjectName(QString::fromUtf8("assignButton"));
        assignButton->setEnabled(false);

        horizontalLayout_3->addWidget(assignButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_5);

        testsTableList = new QTableWidget(TestList);
        testsTableList->setObjectName(QString::fromUtf8("testsTableList"));
        testsTableList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        testsTableList->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(testsTableList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QPushButton(TestList);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        refreshButton = new QPushButton(TestList);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        createTestButton = new QPushButton(TestList);
        createTestButton->setObjectName(QString::fromUtf8("createTestButton"));

        horizontalLayout->addWidget(createTestButton);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(TestList);
        QObject::connect(backButton, &QPushButton::clicked, TestList, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(TestList);
    } // setupUi

    void retranslateUi(QDialog *TestList)
    {
        TestList->setWindowTitle(QCoreApplication::translate("TestList", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TestList", "Created tests", nullptr));
        subjectLabel->setText(QCoreApplication::translate("TestList", "Subject:", nullptr));
        subjectComboBox->setItemText(0, QCoreApplication::translate("TestList", "Fizica", nullptr));
        subjectComboBox->setItemText(1, QCoreApplication::translate("TestList", "Matematica", nullptr));
        subjectComboBox->setItemText(2, QCoreApplication::translate("TestList", "Filosofie", nullptr));
        subjectComboBox->setItemText(3, QCoreApplication::translate("TestList", "Geografie", nullptr));
        subjectComboBox->setItemText(4, QCoreApplication::translate("TestList", "Romana", nullptr));

        setSubjectButton->setText(QCoreApplication::translate("TestList", "Set", nullptr));
        label_2->setText(QCoreApplication::translate("TestList", "Assign test to:", nullptr));
        assignGroupsList->setItemText(0, QCoreApplication::translate("TestList", "C112A", nullptr));
        assignGroupsList->setItemText(1, QCoreApplication::translate("TestList", "C112D", nullptr));
        assignGroupsList->setItemText(2, QCoreApplication::translate("TestList", "C112E", nullptr));
        assignGroupsList->setItemText(3, QCoreApplication::translate("TestList", "A112B", nullptr));
        assignGroupsList->setItemText(4, QCoreApplication::translate("TestList", "C112JMK", nullptr));

        assignButton->setText(QCoreApplication::translate("TestList", "Assign", nullptr));
        backButton->setText(QCoreApplication::translate("TestList", "Back", nullptr));
        refreshButton->setText(QCoreApplication::translate("TestList", "Refresh", nullptr));
        createTestButton->setText(QCoreApplication::translate("TestList", "Create new test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestList: public Ui_TestList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTLIST_H
