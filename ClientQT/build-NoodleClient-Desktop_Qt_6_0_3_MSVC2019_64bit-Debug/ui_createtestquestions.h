/********************************************************************************
** Form generated from reading UI file 'createtestquestions.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETESTQUESTIONS_H
#define UI_CREATETESTQUESTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_createTestQuestions
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *questionBodyLabel;
    QLineEdit *questionBodyLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *questionTypeLabel;
    QVBoxLayout *verticalLayout;
    QRadioButton *singeAnswerRadioButton;
    QRadioButton *multipleAnswerRadioButton;
    QHBoxLayout *nrAnswersLayout;
    QLabel *NumbeOfAnswersLabel;
    QComboBox *numberOfAnswersComboBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *shortAnswerLabel;
    QLineEdit *shortAnswerLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *answer1;
    QCheckBox *checkBox1;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *answer2;
    QCheckBox *checkBox2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *answer3;
    QCheckBox *checkBox3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *answer4;
    QCheckBox *checkBox4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *nrOfPointsLabel;
    QLineEdit *nrOfPointsLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextQuestion;

    void setupUi(QDialog *createTestQuestions)
    {
        if (createTestQuestions->objectName().isEmpty())
            createTestQuestions->setObjectName(QString::fromUtf8("createTestQuestions"));
        createTestQuestions->resize(409, 412);
        verticalLayout_2 = new QVBoxLayout(createTestQuestions);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        questionBodyLabel = new QLabel(createTestQuestions);
        questionBodyLabel->setObjectName(QString::fromUtf8("questionBodyLabel"));
        questionBodyLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_2->addWidget(questionBodyLabel);

        questionBodyLineEdit = new QLineEdit(createTestQuestions);
        questionBodyLineEdit->setObjectName(QString::fromUtf8("questionBodyLineEdit"));

        verticalLayout_2->addWidget(questionBodyLineEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        questionTypeLabel = new QLabel(createTestQuestions);
        questionTypeLabel->setObjectName(QString::fromUtf8("questionTypeLabel"));
        questionTypeLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        horizontalLayout_7->addWidget(questionTypeLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        singeAnswerRadioButton = new QRadioButton(createTestQuestions);
        singeAnswerRadioButton->setObjectName(QString::fromUtf8("singeAnswerRadioButton"));

        verticalLayout->addWidget(singeAnswerRadioButton);

        multipleAnswerRadioButton = new QRadioButton(createTestQuestions);
        multipleAnswerRadioButton->setObjectName(QString::fromUtf8("multipleAnswerRadioButton"));

        verticalLayout->addWidget(multipleAnswerRadioButton);


        horizontalLayout_7->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_7);

        nrAnswersLayout = new QHBoxLayout();
        nrAnswersLayout->setObjectName(QString::fromUtf8("nrAnswersLayout"));
        NumbeOfAnswersLabel = new QLabel(createTestQuestions);
        NumbeOfAnswersLabel->setObjectName(QString::fromUtf8("NumbeOfAnswersLabel"));
        NumbeOfAnswersLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        nrAnswersLayout->addWidget(NumbeOfAnswersLabel);

        numberOfAnswersComboBox = new QComboBox(createTestQuestions);
        numberOfAnswersComboBox->addItem(QString());
        numberOfAnswersComboBox->addItem(QString());
        numberOfAnswersComboBox->addItem(QString());
        numberOfAnswersComboBox->setObjectName(QString::fromUtf8("numberOfAnswersComboBox"));

        nrAnswersLayout->addWidget(numberOfAnswersComboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        nrAnswersLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(nrAnswersLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        shortAnswerLabel = new QLabel(createTestQuestions);
        shortAnswerLabel->setObjectName(QString::fromUtf8("shortAnswerLabel"));
        shortAnswerLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        horizontalLayout_2->addWidget(shortAnswerLabel);

        shortAnswerLineEdit = new QLineEdit(createTestQuestions);
        shortAnswerLineEdit->setObjectName(QString::fromUtf8("shortAnswerLineEdit"));

        horizontalLayout_2->addWidget(shortAnswerLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        answer1 = new QLineEdit(createTestQuestions);
        answer1->setObjectName(QString::fromUtf8("answer1"));

        horizontalLayout_3->addWidget(answer1, 0, Qt::AlignHCenter);

        checkBox1 = new QCheckBox(createTestQuestions);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));

        horizontalLayout_3->addWidget(checkBox1);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        answer2 = new QLineEdit(createTestQuestions);
        answer2->setObjectName(QString::fromUtf8("answer2"));

        horizontalLayout_4->addWidget(answer2, 0, Qt::AlignHCenter);

        checkBox2 = new QCheckBox(createTestQuestions);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));

        horizontalLayout_4->addWidget(checkBox2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        answer3 = new QLineEdit(createTestQuestions);
        answer3->setObjectName(QString::fromUtf8("answer3"));

        horizontalLayout_5->addWidget(answer3, 0, Qt::AlignHCenter);

        checkBox3 = new QCheckBox(createTestQuestions);
        checkBox3->setObjectName(QString::fromUtf8("checkBox3"));

        horizontalLayout_5->addWidget(checkBox3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        answer4 = new QLineEdit(createTestQuestions);
        answer4->setObjectName(QString::fromUtf8("answer4"));

        horizontalLayout_6->addWidget(answer4, 0, Qt::AlignHCenter);

        checkBox4 = new QCheckBox(createTestQuestions);
        checkBox4->setObjectName(QString::fromUtf8("checkBox4"));

        horizontalLayout_6->addWidget(checkBox4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nrOfPointsLabel = new QLabel(createTestQuestions);
        nrOfPointsLabel->setObjectName(QString::fromUtf8("nrOfPointsLabel"));

        horizontalLayout->addWidget(nrOfPointsLabel);

        nrOfPointsLineEdit = new QLineEdit(createTestQuestions);
        nrOfPointsLineEdit->setObjectName(QString::fromUtf8("nrOfPointsLineEdit"));

        horizontalLayout->addWidget(nrOfPointsLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        nextQuestion = new QPushButton(createTestQuestions);
        nextQuestion->setObjectName(QString::fromUtf8("nextQuestion"));

        horizontalLayout_8->addWidget(nextQuestion);


        verticalLayout_2->addLayout(horizontalLayout_8);


        retranslateUi(createTestQuestions);

        QMetaObject::connectSlotsByName(createTestQuestions);
    } // setupUi

    void retranslateUi(QDialog *createTestQuestions)
    {
        createTestQuestions->setWindowTitle(QCoreApplication::translate("createTestQuestions", "Dialog", nullptr));
        questionBodyLabel->setText(QCoreApplication::translate("createTestQuestions", "Question body:", nullptr));
        questionTypeLabel->setText(QCoreApplication::translate("createTestQuestions", "Question type:", nullptr));
        singeAnswerRadioButton->setText(QCoreApplication::translate("createTestQuestions", "single answer", nullptr));
        multipleAnswerRadioButton->setText(QCoreApplication::translate("createTestQuestions", "multiple answer", nullptr));
        NumbeOfAnswersLabel->setText(QCoreApplication::translate("createTestQuestions", "Number of answers:", nullptr));
        numberOfAnswersComboBox->setItemText(0, QCoreApplication::translate("createTestQuestions", "2", nullptr));
        numberOfAnswersComboBox->setItemText(1, QCoreApplication::translate("createTestQuestions", "3", nullptr));
        numberOfAnswersComboBox->setItemText(2, QCoreApplication::translate("createTestQuestions", "4", nullptr));

        shortAnswerLabel->setText(QCoreApplication::translate("createTestQuestions", "Short Answer:", nullptr));
        checkBox1->setText(QCoreApplication::translate("createTestQuestions", "True", nullptr));
        checkBox2->setText(QCoreApplication::translate("createTestQuestions", "True", nullptr));
        checkBox3->setText(QCoreApplication::translate("createTestQuestions", "True", nullptr));
        checkBox4->setText(QCoreApplication::translate("createTestQuestions", "True", nullptr));
        nrOfPointsLabel->setText(QCoreApplication::translate("createTestQuestions", "Number of points", nullptr));
        nextQuestion->setText(QCoreApplication::translate("createTestQuestions", "Next question", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createTestQuestions: public Ui_createTestQuestions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETESTQUESTIONS_H
