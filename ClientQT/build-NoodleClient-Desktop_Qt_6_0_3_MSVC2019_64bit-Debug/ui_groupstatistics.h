/********************************************************************************
** Form generated from reading UI file 'groupstatistics.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSTATISTICS_H
#define UI_GROUPSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_groupStatistics
{
public:

    void setupUi(QDialog *groupStatistics)
    {
        if (groupStatistics->objectName().isEmpty())
            groupStatistics->setObjectName(QString::fromUtf8("groupStatistics"));
        groupStatistics->resize(400, 300);

        retranslateUi(groupStatistics);

        QMetaObject::connectSlotsByName(groupStatistics);
    } // setupUi

    void retranslateUi(QDialog *groupStatistics)
    {
        groupStatistics->setWindowTitle(QCoreApplication::translate("groupStatistics", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupStatistics: public Ui_groupStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSTATISTICS_H
