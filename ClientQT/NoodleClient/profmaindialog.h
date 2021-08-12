#ifndef PROFMAINDIALOG_H
#define PROFMAINDIALOG_H

#include <QDialog>
#include "testlist.h"
#include "testresults.h"
#include "questionslist.h"

using namespace std;

namespace Ui {
class ProfMainDialog;
}

class IUser;

class ProfMainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfMainDialog(QWidget *parent = nullptr,IUser* u = nullptr);
    ~ProfMainDialog();

private slots:
    void on_changePasswordButton_clicked();

    void on_testResultsButton_clicked();

    void on_accountInfo_clicked();

    void on_TestListButton_clicked();

    void on_logOutButton_clicked();

private:
    Ui::ProfMainDialog *ui;
    TestList* testDialog=nullptr;
    TestResults* resDialog=nullptr;
    IUser* user=nullptr;

};

#endif // PROFMAINDIALOG_H
