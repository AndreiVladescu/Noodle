/********************************************************************************
** Form generated from reading UI file 'studentquizlist.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTQUIZLIST_H
#define UI_STUDENTQUIZLIST_H

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

class Ui_studentQuizList
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QTableWidget *quizesList;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *refreshButton;
    QPushButton *attemptButton;

    void setupUi(QDialog *studentQuizList)
    {
        if (studentQuizList->objectName().isEmpty())
            studentQuizList->setObjectName(QString::fromUtf8("studentQuizList"));
        studentQuizList->resize(595, 438);
        verticalLayout = new QVBoxLayout(studentQuizList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(studentQuizList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"Times New Roman\";"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(studentQuizList);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        verticalLayout->addWidget(label_2);

        quizesList = new QTableWidget(studentQuizList);
        quizesList->setObjectName(QString::fromUtf8("quizesList"));
        quizesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        quizesList->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(quizesList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(studentQuizList);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        refreshButton = new QPushButton(studentQuizList);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        attemptButton = new QPushButton(studentQuizList);
        attemptButton->setObjectName(QString::fromUtf8("attemptButton"));
        attemptButton->setEnabled(false);

        horizontalLayout->addWidget(attemptButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(studentQuizList);
        QObject::connect(pushButton, &QPushButton::clicked, studentQuizList, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(studentQuizList);
    } // setupUi

    void retranslateUi(QDialog *studentQuizList)
    {
        studentQuizList->setWindowTitle(QCoreApplication::translate("studentQuizList", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("studentQuizList", "Available tests", nullptr));
        label_2->setText(QCoreApplication::translate("studentQuizList", "Click on the test, then click \"Attempt\" button", nullptr));
        pushButton->setText(QCoreApplication::translate("studentQuizList", "Back", nullptr));
        refreshButton->setText(QCoreApplication::translate("studentQuizList", "Refresh", nullptr));
        attemptButton->setText(QCoreApplication::translate("studentQuizList", "Attempt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentQuizList: public Ui_studentQuizList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTQUIZLIST_H
