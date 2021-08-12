/********************************************************************************
** Form generated from reading UI file 'testresults.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTRESULTS_H
#define UI_TESTRESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TestResults
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *studyGroupLabel;
    QComboBox *studyGroupComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *subjectComboBox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *seeGradesButton;
    QTableWidget *studentsTable;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *changeGradeLabel;
    QLineEdit *changeGradeLE;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *changeGradeButton;

    void setupUi(QDialog *TestResults)
    {
        if (TestResults->objectName().isEmpty())
            TestResults->setObjectName(QString::fromUtf8("TestResults"));
        TestResults->resize(362, 477);
        verticalLayout_3 = new QVBoxLayout(TestResults);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(TestResults);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Times New Roman\";"));

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        studyGroupLabel = new QLabel(TestResults);
        studyGroupLabel->setObjectName(QString::fromUtf8("studyGroupLabel"));
        studyGroupLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout->addWidget(studyGroupLabel);

        studyGroupComboBox = new QComboBox(TestResults);
        studyGroupComboBox->addItem(QString());
        studyGroupComboBox->addItem(QString());
        studyGroupComboBox->setObjectName(QString::fromUtf8("studyGroupComboBox"));

        horizontalLayout->addWidget(studyGroupComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(TestResults);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        horizontalLayout_4->addWidget(label_4);

        subjectComboBox = new QComboBox(TestResults);
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->addItem(QString());
        subjectComboBox->setObjectName(QString::fromUtf8("subjectComboBox"));

        horizontalLayout_4->addWidget(subjectComboBox);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        seeGradesButton = new QPushButton(TestResults);
        seeGradesButton->setObjectName(QString::fromUtf8("seeGradesButton"));

        horizontalLayout_5->addWidget(seeGradesButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        studentsTable = new QTableWidget(TestResults);
        studentsTable->setObjectName(QString::fromUtf8("studentsTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(studentsTable->sizePolicy().hasHeightForWidth());
        studentsTable->setSizePolicy(sizePolicy);
        studentsTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        studentsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        studentsTable->verticalHeader()->setVisible(false);
        studentsTable->verticalHeader()->setHighlightSections(false);

        verticalLayout_3->addWidget(studentsTable);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        changeGradeLabel = new QLabel(TestResults);
        changeGradeLabel->setObjectName(QString::fromUtf8("changeGradeLabel"));
        changeGradeLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_2->addWidget(changeGradeLabel, 0, Qt::AlignRight);

        changeGradeLE = new QLineEdit(TestResults);
        changeGradeLE->setObjectName(QString::fromUtf8("changeGradeLE"));

        verticalLayout_2->addWidget(changeGradeLE, 0, Qt::AlignRight);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(TestResults);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        changeGradeButton = new QPushButton(TestResults);
        changeGradeButton->setObjectName(QString::fromUtf8("changeGradeButton"));

        horizontalLayout_2->addWidget(changeGradeButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(TestResults);
        QObject::connect(pushButton, &QPushButton::clicked, TestResults, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(TestResults);
    } // setupUi

    void retranslateUi(QDialog *TestResults)
    {
        TestResults->setWindowTitle(QCoreApplication::translate("TestResults", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("TestResults", "Grades", nullptr));
        studyGroupLabel->setText(QCoreApplication::translate("TestResults", "Study group:", nullptr));
        studyGroupComboBox->setItemText(0, QCoreApplication::translate("TestResults", "C112E", nullptr));
        studyGroupComboBox->setItemText(1, QCoreApplication::translate("TestResults", "C112A", nullptr));

        label_4->setText(QCoreApplication::translate("TestResults", "Subject:", nullptr));
        subjectComboBox->setItemText(0, QCoreApplication::translate("TestResults", "Fizica", nullptr));
        subjectComboBox->setItemText(1, QCoreApplication::translate("TestResults", "Matematica", nullptr));
        subjectComboBox->setItemText(2, QCoreApplication::translate("TestResults", "Filosofie", nullptr));
        subjectComboBox->setItemText(3, QCoreApplication::translate("TestResults", "Geografie", nullptr));
        subjectComboBox->setItemText(4, QCoreApplication::translate("TestResults", "Romana", nullptr));

        seeGradesButton->setText(QCoreApplication::translate("TestResults", "See", nullptr));
        changeGradeLabel->setText(QCoreApplication::translate("TestResults", "Change grade:", nullptr));
        pushButton->setText(QCoreApplication::translate("TestResults", "Back", nullptr));
        changeGradeButton->setText(QCoreApplication::translate("TestResults", "Change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestResults: public Ui_TestResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTRESULTS_H
