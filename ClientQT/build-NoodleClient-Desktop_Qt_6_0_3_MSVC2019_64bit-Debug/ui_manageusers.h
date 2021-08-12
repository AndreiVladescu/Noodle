/********************************************************************************
** Form generated from reading UI file 'manageusers.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEUSERS_H
#define UI_MANAGEUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_manageUsers
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *searchUser;
    QTableWidget *listAccounts;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *deleteUserButton;
    QPushButton *addUserButton;

    void setupUi(QDialog *manageUsers)
    {
        if (manageUsers->objectName().isEmpty())
            manageUsers->setObjectName(QString::fromUtf8("manageUsers"));
        manageUsers->resize(444, 506);
        verticalLayout = new QVBoxLayout(manageUsers);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(manageUsers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(manageUsers);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Times New Roman\";"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(manageUsers);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchUser = new QLineEdit(manageUsers);
        searchUser->setObjectName(QString::fromUtf8("searchUser"));

        horizontalLayout_2->addWidget(searchUser);


        verticalLayout->addLayout(horizontalLayout_2);

        listAccounts = new QTableWidget(manageUsers);
        listAccounts->setObjectName(QString::fromUtf8("listAccounts"));
        listAccounts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listAccounts->setSelectionMode(QAbstractItemView::SingleSelection);
        listAccounts->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(listAccounts);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QPushButton(manageUsers);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton);

        deleteUserButton = new QPushButton(manageUsers);
        deleteUserButton->setObjectName(QString::fromUtf8("deleteUserButton"));
        deleteUserButton->setEnabled(false);

        horizontalLayout->addWidget(deleteUserButton);

        addUserButton = new QPushButton(manageUsers);
        addUserButton->setObjectName(QString::fromUtf8("addUserButton"));

        horizontalLayout->addWidget(addUserButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(manageUsers);
        QObject::connect(backButton, &QPushButton::clicked, manageUsers, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(manageUsers);
    } // setupUi

    void retranslateUi(QDialog *manageUsers)
    {
        manageUsers->setWindowTitle(QCoreApplication::translate("manageUsers", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("manageUsers", "Manage user accounts", nullptr));
        label_2->setText(QCoreApplication::translate("manageUsers", "Press delete/add button to delete/add an account", nullptr));
        label_3->setText(QCoreApplication::translate("manageUsers", "Search for users:", nullptr));
        backButton->setText(QCoreApplication::translate("manageUsers", "Back", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("manageUsers", "Delete", nullptr));
        addUserButton->setText(QCoreApplication::translate("manageUsers", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manageUsers: public Ui_manageUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEUSERS_H
