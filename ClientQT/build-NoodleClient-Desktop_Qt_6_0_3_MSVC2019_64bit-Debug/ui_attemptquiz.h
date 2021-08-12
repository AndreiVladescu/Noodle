/********************************************************************************
** Form generated from reading UI file 'attemptquiz.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTEMPTQUIZ_H
#define UI_ATTEMPTQUIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_attemptQuiz
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *indexLabel;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *clockDisplay;
    QSpacerItem *verticalSpacer_2;
    QLabel *questionBodyLabel;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *answerLabel;
    QLineEdit *openAnswerEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *chooseBetweenLabel;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *answer1;
    QCheckBox *answer2;
    QCheckBox *answer3;
    QCheckBox *answer4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextQuestionButton;

    void setupUi(QDialog *attemptQuiz)
    {
        if (attemptQuiz->objectName().isEmpty())
            attemptQuiz->setObjectName(QString::fromUtf8("attemptQuiz"));
        attemptQuiz->resize(460, 418);
        verticalLayout_4 = new QVBoxLayout(attemptQuiz);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        indexLabel = new QLabel(attemptQuiz);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));
        indexLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"Times New Roman\";"));

        horizontalLayout_2->addWidget(indexLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        clockDisplay = new QLCDNumber(attemptQuiz);
        clockDisplay->setObjectName(QString::fromUtf8("clockDisplay"));
        clockDisplay->setDigitCount(7);

        horizontalLayout_2->addWidget(clockDisplay);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        questionBodyLabel = new QLabel(attemptQuiz);
        questionBodyLabel->setObjectName(QString::fromUtf8("questionBodyLabel"));
        questionBodyLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Times New Roman\";"));

        verticalLayout_4->addWidget(questionBodyLabel);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        answerLabel = new QLabel(attemptQuiz);
        answerLabel->setObjectName(QString::fromUtf8("answerLabel"));
        answerLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Times New Roman\";"));

        verticalLayout->addWidget(answerLabel);

        openAnswerEdit = new QLineEdit(attemptQuiz);
        openAnswerEdit->setObjectName(QString::fromUtf8("openAnswerEdit"));

        verticalLayout->addWidget(openAnswerEdit);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        chooseBetweenLabel = new QLabel(attemptQuiz);
        chooseBetweenLabel->setObjectName(QString::fromUtf8("chooseBetweenLabel"));
        chooseBetweenLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Times New Roman\";"));

        verticalLayout_3->addWidget(chooseBetweenLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        answer1 = new QCheckBox(attemptQuiz);
        answer1->setObjectName(QString::fromUtf8("answer1"));
        answer1->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_2->addWidget(answer1);

        answer2 = new QCheckBox(attemptQuiz);
        answer2->setObjectName(QString::fromUtf8("answer2"));
        answer2->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_2->addWidget(answer2);

        answer3 = new QCheckBox(attemptQuiz);
        answer3->setObjectName(QString::fromUtf8("answer3"));
        answer3->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_2->addWidget(answer3);

        answer4 = new QCheckBox(attemptQuiz);
        answer4->setObjectName(QString::fromUtf8("answer4"));
        answer4->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";"));

        verticalLayout_2->addWidget(answer4);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextQuestionButton = new QPushButton(attemptQuiz);
        nextQuestionButton->setObjectName(QString::fromUtf8("nextQuestionButton"));

        horizontalLayout->addWidget(nextQuestionButton);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(attemptQuiz);

        QMetaObject::connectSlotsByName(attemptQuiz);
    } // setupUi

    void retranslateUi(QDialog *attemptQuiz)
    {
        attemptQuiz->setWindowTitle(QCoreApplication::translate("attemptQuiz", "Dialog", nullptr));
        indexLabel->setText(QCoreApplication::translate("attemptQuiz", "1/10", nullptr));
        questionBodyLabel->setText(QCoreApplication::translate("attemptQuiz", "Body", nullptr));
        answerLabel->setText(QCoreApplication::translate("attemptQuiz", "Short answer:", nullptr));
        chooseBetweenLabel->setText(QCoreApplication::translate("attemptQuiz", "Choose between:", nullptr));
        answer1->setText(QCoreApplication::translate("attemptQuiz", "cf", nullptr));
        answer2->setText(QCoreApplication::translate("attemptQuiz", "CheckBox", nullptr));
        answer3->setText(QCoreApplication::translate("attemptQuiz", "CheckBox", nullptr));
        answer4->setText(QCoreApplication::translate("attemptQuiz", "CheckBox", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("attemptQuiz", "Next question>>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class attemptQuiz: public Ui_attemptQuiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTEMPTQUIZ_H
