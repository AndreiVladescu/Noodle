#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class ChangePassword;
}


class IUser;

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = nullptr,IUser* u=nullptr);
    ~ChangePassword();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::ChangePassword *ui;
    IUser* user;
};

#endif // CHANGEPASSWORD_H
