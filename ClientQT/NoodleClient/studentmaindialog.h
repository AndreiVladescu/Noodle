#ifndef STUDENTMAINDIALOG_H
#define STUDENTMAINDIALOG_H

#include <QDialog>
#include "gradesstudent.h"
#include "testresults.h"
#include "studentquizlist.h"

using namespace std;

namespace Ui {
class StudentMainDialog;
}

class IUser;

class StudentMainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMainDialog(QWidget *parent = nullptr, IUser* u = nullptr);
    ~StudentMainDialog();

private slots:


    void on_changePasswButton_clicked();


    void on_examButton_clicked();

    void on_pushButton_clicked();

    void on_accountInfo_clicked();

    void on_gradesButton_clicked();

    void on_groupStatisticButton_clicked();

private:
    Ui::StudentMainDialog *ui;
    gradesStudent* gradesList=nullptr;
    studentQuizList* testDialog=nullptr;
    TestResults* resDialog=nullptr;
    IUser* user=nullptr;


};

#endif // STUDENTMAINDIALOG_H
