#include "adminmaindialog.h"
#include "ui_adminmaindialog.h"
#include "changepassword.h"
#include "IUser.h"
#include "accountinfo.h"

AdminMainDialog::AdminMainDialog(QWidget *parent, IUser *u) :
    QDialog(parent),
    ui(new Ui::AdminMainDialog), user(u)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Menu");

    string welcome ="Welcome, " ;
    welcome+=user->getFirstName();
    welcome+=" ";
    welcome+=user->getLastName();
    welcome+="!";
    ui->WelcomeLabel->setText(QString::fromStdString(welcome));
}

AdminMainDialog::~AdminMainDialog()
{
    delete ui;
    if(this->user!=nullptr)
    {
        user->logOut();
        delete user;
    }
    if(this->mngUsers!=nullptr)
    {
        delete mngUsers;
        mngUsers=nullptr;
    }
    if(this->onlineUsers!=nullptr)
    {
        delete onlineUsers;
        onlineUsers=nullptr;
    }
}



void AdminMainDialog::on_manageUserAccount_clicked()
{

    this->mngUsers =new manageUsers(this);
    mngUsers->setModal(true);
    mngUsers->exec();

    if(this->mngUsers!=nullptr)
    {
        delete mngUsers;
        mngUsers=nullptr;
    }
}

void AdminMainDialog::on_seeUserAccount_clicked()
{
    this->onlineUsers =new OnlineAccounts(this);
    onlineUsers->setModal(true);
    onlineUsers->exec();

    if(this->onlineUsers!=nullptr)
    {
        delete onlineUsers;
        onlineUsers=nullptr;
    }
}



void AdminMainDialog::on_changePassword_clicked()
{
    ChangePassword psWindow(this,user);
    psWindow.setModal(true);
    psWindow.exec();

}

void AdminMainDialog::on_pushButton_clicked()
{
    //this->user->logOut();
    close();
}

void AdminMainDialog::on_accountInfo_clicked()
{
    accountInfo acWindow(this,user);
    acWindow.setModal(true);
    acWindow.exec();
}
