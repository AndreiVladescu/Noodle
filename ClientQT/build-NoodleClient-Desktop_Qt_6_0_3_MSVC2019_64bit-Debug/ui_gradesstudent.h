/********************************************************************************
** Form generated from reading UI file 'gradesstudent.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADESSTUDENT_H
#define UI_GRADESSTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_gradesStudent
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *gradesTable;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QDialog *gradesStudent)
    {
        if (gradesStudent->objectName().isEmpty())
            gradesStudent->setObjectName(QString::fromUtf8("gradesStudent"));
        gradesStudent->resize(349, 355);
        verticalLayout = new QVBoxLayout(gradesStudent);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gradesTable = new QTableWidget(gradesStudent);
        gradesTable->setObjectName(QString::fromUtf8("gradesTable"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gradesTable->sizePolicy().hasHeightForWidth());
        gradesTable->setSizePolicy(sizePolicy);
        gradesTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        gradesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        gradesTable->setDefaultDropAction(Qt::IgnoreAction);
        gradesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        gradesTable->setTextElideMode(Qt::ElideRight);
        gradesTable->setShowGrid(true);
        gradesTable->setColumnCount(0);
        gradesTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(gradesTable);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(gradesStudent);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2, 0, Qt::AlignLeft);


        retranslateUi(gradesStudent);
        QObject::connect(pushButton_2, &QPushButton::clicked, gradesStudent, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(gradesStudent);
    } // setupUi

    void retranslateUi(QDialog *gradesStudent)
    {
        gradesStudent->setWindowTitle(QCoreApplication::translate("gradesStudent", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("gradesStudent", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gradesStudent: public Ui_gradesStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADESSTUDENT_H
