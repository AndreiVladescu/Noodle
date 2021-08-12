/********************************************************************************
** Form generated from reading UI file 'testattempt.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTATTEMPT_H
#define UI_TESTATTEMPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_testAttempt
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *back;
    QSpacerItem *horizontalSpacer;
    QPushButton *refreshButton;
    QPushButton *attemptButton;

    void setupUi(QDialog *testAttempt)
    {
        if (testAttempt->objectName().isEmpty())
            testAttempt->setObjectName(QString::fromUtf8("testAttempt"));
        testAttempt->resize(527, 375);
        verticalLayout = new QVBoxLayout(testAttempt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(testAttempt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(testAttempt);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        verticalLayout->addWidget(label_2);

        tableWidget = new QTableWidget(testAttempt);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem8);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        back = new QPushButton(testAttempt);
        back->setObjectName(QString::fromUtf8("back"));

        horizontalLayout->addWidget(back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        refreshButton = new QPushButton(testAttempt);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        attemptButton = new QPushButton(testAttempt);
        attemptButton->setObjectName(QString::fromUtf8("attemptButton"));
        attemptButton->setEnabled(false);

        horizontalLayout->addWidget(attemptButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(testAttempt);
        QObject::connect(back, &QPushButton::clicked, testAttempt, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(testAttempt);
    } // setupUi

    void retranslateUi(QDialog *testAttempt)
    {
        testAttempt->setWindowTitle(QCoreApplication::translate("testAttempt", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("testAttempt", "Available tests", nullptr));
        label_2->setText(QCoreApplication::translate("testAttempt", "Click on the test, and then click \"Attempt\"", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("testAttempt", "#", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("testAttempt", "State", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("testAttempt", "Available time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("testAttempt", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("testAttempt", "New Row", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("testAttempt", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("testAttempt", "Finished", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("testAttempt", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("testAttempt", "7.5", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        back->setText(QCoreApplication::translate("testAttempt", "Back", nullptr));
        refreshButton->setText(QCoreApplication::translate("testAttempt", "Refresh", nullptr));
        attemptButton->setText(QCoreApplication::translate("testAttempt", "Attempt quiz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testAttempt: public Ui_testAttempt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTATTEMPT_H
