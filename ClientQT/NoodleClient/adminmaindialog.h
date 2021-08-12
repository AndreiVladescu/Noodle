#ifndef ADMINMAINDIALOG_H
#define ADMINMAINDIALOG_H

#include <QDialog>
#include "manageusers.h"
#include "onlineaccounts.h"
#include <string>

using namespace std;

namespace Ui {
class AdminMainDialog;
}

class IUser;

class AdminMainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMainDialog(QWidget *parent = nullptr, IUser* u = nullptr);
    ~AdminMainDialog();

private slots:

    void on_manageUserAccount_clicked();

    void on_seeUserAccount_clicked();

    void on_changePassword_clicked();

    void on_pushButton_clicked();

    void on_accountInfo_clicked();

private:
    Ui::AdminMainDialog *ui;
    manageUsers *mngUsers=nullptr;
    OnlineAccounts* onlineUsers=nullptr;
    IUser* user=nullptr;
};

#endif // ADMINMAINDIALOG_H
