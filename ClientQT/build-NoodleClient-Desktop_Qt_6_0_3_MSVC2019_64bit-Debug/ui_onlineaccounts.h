/********************************************************************************
** Form generated from reading UI file 'onlineaccounts.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEACCOUNTS_H
#define UI_ONLINEACCOUNTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OnlineAccounts
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *onlineUsersTable;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *RefreshButton;

    void setupUi(QDialog *OnlineAccounts)
    {
        if (OnlineAccounts->objectName().isEmpty())
            OnlineAccounts->setObjectName(QString::fromUtf8("OnlineAccounts"));
        OnlineAccounts->resize(400, 300);
        verticalLayout = new QVBoxLayout(OnlineAccounts);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        onlineUsersTable = new QTableWidget(OnlineAccounts);
        onlineUsersTable->setObjectName(QString::fromUtf8("onlineUsersTable"));
        onlineUsersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        onlineUsersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        onlineUsersTable->setGridStyle(Qt::SolidLine);

        verticalLayout->addWidget(onlineUsersTable);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QPushButton(OnlineAccounts);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton, 0, Qt::AlignLeft);

        RefreshButton = new QPushButton(OnlineAccounts);
        RefreshButton->setObjectName(QString::fromUtf8("RefreshButton"));

        horizontalLayout->addWidget(RefreshButton, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(OnlineAccounts);
        QObject::connect(backButton, &QPushButton::clicked, OnlineAccounts, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(OnlineAccounts);
    } // setupUi

    void retranslateUi(QDialog *OnlineAccounts)
    {
        OnlineAccounts->setWindowTitle(QCoreApplication::translate("OnlineAccounts", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("OnlineAccounts", "Back", nullptr));
        RefreshButton->setText(QCoreApplication::translate("OnlineAccounts", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineAccounts: public Ui_OnlineAccounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEACCOUNTS_H
