/********************************************************************************
** Form generated from reading UI file 'quizeslist.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZESLIST_H
#define UI_QUIZESLIST_H

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
        label_2->setText(QCoreApplication::translate("testAttempt", "Click on the test, then click \"Attempt\"", nullptr));
        back->setText(QCoreApplication::translate("testAttempt", "Back", nullptr));
        refreshButton->setText(QCoreApplication::translate("testAttempt", "Refresh", nullptr));
        attemptButton->setText(QCoreApplication::translate("testAttempt", "Attempt quiz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testAttempt: public Ui_testAttempt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZESLIST_H
