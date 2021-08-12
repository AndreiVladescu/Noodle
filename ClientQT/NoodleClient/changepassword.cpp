#include "changepassword.h"
#include "ui_changepassword.h"
#include <QMessageBox>
#include "IUser.h"

ChangePassword::ChangePassword(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::ChangePassword) , user(u)
{
    ui->setupUi(this);
    this->setWindowTitle("Change password");

}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_confirmButton_clicked()
{
    QString qpas1 = ui->NewPassword1->text();
    QString qpas2 = ui->NewPassword2->text();
    QString qoldp = ui->OldPassword->text();

    if(qoldp=="" || qpas1=="" || qpas2=="")
    {
        QMessageBox::warning(this,"Change Password Error","All fields must be completed.");
    }
    else
    {
        if(qoldp.toStdString()!=this->user->getPsswrd())
        {
            QMessageBox::warning(this,"Change Password Error","Old password is wrong, please try again.");
        }
        else
        {
            if(qpas1!=qpas2)
            {
               QMessageBox::warning(this,"Change Password Error","Passwords don't match, please try again.");
            }
            else
            {
                string newPass = qpas2.toStdString();
                this->user->changePsswrd(newPass);
                QMessageBox::information(this,"Confirmation","Your password has been successfully updated!");
                close();
            }
        }
    }


}
