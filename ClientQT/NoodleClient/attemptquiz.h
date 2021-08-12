#ifndef ATTEMPTQUIZ_H
#define ATTEMPTQUIZ_H

#include <QDialog>
#include <QTimer>
#include <vector>
#include <string>
#include <QTime>

namespace Ui {
class attemptQuiz;
}

using namespace std;

class IUser;

class attemptQuiz : public QDialog
{
    Q_OBJECT

public:
    explicit attemptQuiz(string test,string s,QTime fTime,string titluTest,vector<vector<string>>& v,int& time,QWidget *parent = nullptr,IUser* u=nullptr);
    ~attemptQuiz();

private slots:
    void showTime();


    void on_nextQuestionButton_clicked();

private:
    Ui::attemptQuiz *ui;
    IUser* user=nullptr;
    vector<vector<string>> questions;

    int indexQuestion=0;
    int maxPoints=0;
    double currentPoints=0;
    int nrQ=0;
    int time=0;
    int grade=1;
    QTimer* clock=nullptr;
    string subjectName;
    string testID;

    QTime finishTime;

    void updateIndex();
    void updateUI();
    void endTest();
    void calculateQPoints();
    void calculateGrade();
    void sendGrade();
    bool checkSuppAnswer(vector<string>v,int nrAns);
};

#endif // ATTEMPTQUIZ_H
