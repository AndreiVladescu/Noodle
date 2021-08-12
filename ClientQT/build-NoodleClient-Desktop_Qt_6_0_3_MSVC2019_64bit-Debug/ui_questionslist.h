/********************************************************************************
** Form generated from reading UI file 'questionslist.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONSLIST_H
#define UI_QUESTIONSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QuestionsList
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *AddQuestion;

    void setupUi(QDialog *QuestionsList)
    {
        if (QuestionsList->objectName().isEmpty())
            QuestionsList->setObjectName(QString::fromUtf8("QuestionsList"));
        QuestionsList->resize(529, 463);
        verticalLayout = new QVBoxLayout(QuestionsList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(QuestionsList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(QuestionsList);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout->addWidget(label_2);

        tableWidget = new QTableWidget(QuestionsList);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(QuestionsList);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton, 0, Qt::AlignLeft);

        AddQuestion = new QPushButton(QuestionsList);
        AddQuestion->setObjectName(QString::fromUtf8("AddQuestion"));

        horizontalLayout->addWidget(AddQuestion, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QuestionsList);
        QObject::connect(pushButton, &QPushButton::clicked, QuestionsList, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(QuestionsList);
    } // setupUi

    void retranslateUi(QDialog *QuestionsList)
    {
        QuestionsList->setWindowTitle(QCoreApplication::translate("QuestionsList", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("QuestionsList", "These are the questions associated with your account", nullptr));
        label_2->setText(QCoreApplication::translate("QuestionsList", "Click on the + button to create a question", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QuestionsList", "#", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QuestionsList", "Domain", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QuestionsList", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("QuestionsList", "Answers number", nullptr));
        pushButton->setText(QCoreApplication::translate("QuestionsList", "Back", nullptr));
        AddQuestion->setText(QCoreApplication::translate("QuestionsList", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionsList: public Ui_QuestionsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONSLIST_H
