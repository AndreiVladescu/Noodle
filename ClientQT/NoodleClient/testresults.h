#ifndef TESTRESULTS_H
#define TESTRESULTS_H

#include <QDialog>
#include <string>
#include <vector>
#include <stdio.h>

namespace Ui {
class TestResults;
}
class IUser;

using namespace std;
class TestResults : public QDialog
{
    Q_OBJECT

public:
    explicit TestResults(QWidget *parent = nullptr,IUser* u=nullptr);
    ~TestResults();

private slots:
    void on_seeGradesButton_clicked();

    void on_changeGradeButton_clicked();


private:
    Ui::TestResults *ui;
    IUser* user=nullptr;

    void populateStudentList(vector<string>&);
    void showGroupAverage();
};

#endif // TESTRESULTS_H
