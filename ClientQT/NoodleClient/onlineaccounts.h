#ifndef ONLINEACCOUNTS_H
#define ONLINEACCOUNTS_H

#include <QDialog>
#include <vector>
#include <string>

using namespace std;

namespace Ui {
class OnlineAccounts;
}

class IUser;

class OnlineAccounts : public QDialog
{
    Q_OBJECT

public:
    explicit OnlineAccounts(QWidget *parent = nullptr,IUser* u=nullptr);
    ~OnlineAccounts();

private slots:
    void on_RefreshButton_clicked();

private:
    Ui::OnlineAccounts *ui;
    IUser* user=nullptr;

    void populateTable(vector<string>& );
};

#endif // ONLINEACCOUNTS_H
