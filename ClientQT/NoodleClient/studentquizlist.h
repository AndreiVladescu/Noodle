#ifndef STUDENTQUIZLIST_H
#define STUDENTQUIZLIST_H

#include <QDialog>
#include <QTableWidgetItem>
#include "attemptquiz.h"

namespace Ui {
class studentQuizList;
}

class IUser;

using namespace std;

class studentQuizList : public QDialog
{
    Q_OBJECT

public:
    explicit studentQuizList(QWidget *parent = nullptr,IUser* u=nullptr);
    ~studentQuizList();

private slots:
    void on_refreshButton_clicked();

    void on_attemptButton_clicked();

    void on_quizesList_itemClicked(QTableWidgetItem *item);

    void on_quizesList_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::studentQuizList *ui;
    IUser* user=nullptr;
    attemptQuiz* activeQuiz=nullptr;

    int nrTeste;

    vector<vector<string>> vTeste;
    vector<vector<vector<string>>> vQuestions;

    void populateQuizList(vector<vector<string>>& mat);
    bool checkStatus(int zi,int luna,int an,int min,int ore,int duration);
    bool checkIfCanStartQuiz();
    void tryToAttempt();

};

#endif // STUDENTQUIZLIST_H
