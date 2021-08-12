#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H

#include <QDialog>
#include <qtablewidget.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

namespace Ui {
class manageUsers;
}

class IUser;

class manageUsers : public QDialog
{
    Q_OBJECT

public:
    explicit manageUsers(QWidget *parent = nullptr,IUser* u=nullptr);
    ~manageUsers();

private slots:

    void on_addUserButton_clicked();

    void on_deleteUserButton_clicked();

    void populateUsersTable(vector<string>& v);

    void on_listAccounts_itemClicked(QTableWidgetItem *item);



    void on_searchUser_textChanged(const QString &arg1);

private:
    void showAllUsers();
    void showUsersByString(string& s);


    Ui::manageUsers *ui;
    IUser* user=nullptr;
    int rowCount=0;
};

#endif // MANAGEUSERS_H
