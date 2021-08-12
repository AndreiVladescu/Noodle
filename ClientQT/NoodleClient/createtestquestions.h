#ifndef CREATETESTQUESTIONS_H
#define CREATETESTQUESTIONS_H

#include <QDialog>
#include <vector>
#include <string>

using namespace std;


namespace Ui {
class createTestQuestions;
}

class IUser;


class createTestQuestions : public QDialog
{
    Q_OBJECT

public:
    explicit createTestQuestions(QWidget *parent = nullptr,int counter=0,IUser* u=nullptr);
    ~createTestQuestions();

private slots:
    void on_singeAnswerRadioButton_clicked();

    void on_multipleAnswerRadioButton_clicked();

    void on_numberOfAnswersComboBox_currentTextChanged(const QString &arg1);

    void on_nextQuestion_clicked();

private:
    Ui::createTestQuestions *ui;
    int counter;
    IUser* user=nullptr;


    void resetUI();
    void hideAllCheckBox();
    void clearAllCheckBox();
    bool sendQuestion();
};

#endif // CREATETESTQUESTIONS_H
