#include "profmaindialog.h"
#include "ui_profmaindialog.h"
#include "IUser.h"
#include "accountinfo.h"
#include "changepassword.h"

ProfMainDialog::ProfMainDialog(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::ProfMainDialog) , user(u)
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

ProfMainDialog::~ProfMainDialog()
{

    delete ui;
    if(this->user!=nullptr)
    {
        user->logOut();
        delete user;
    }
    if(this->testDialog!=nullptr)
    {
        delete testDialog;
        testDialog=nullptr;
    }
    if(this->resDialog!=nullptr)
    {
        delete resDialog;
        resDialog=nullptr;
    }
}

void ProfMainDialog::on_changePasswordButton_clicked()
{
    ChangePassword psWindow(this,user);
    psWindow.setModal(true);
    psWindow.exec();

}

void ProfMainDialog::on_testResultsButton_clicked()
{
    this->resDialog =new TestResults(this,user);
    resDialog->setModal(true);
    resDialog->exec();
    if(this->resDialog!=nullptr)
    {
        delete resDialog;
        resDialog=nullptr;
    }
}


void ProfMainDialog::on_accountInfo_clicked()
{
    accountInfo acWindow(this,user);
    acWindow.setModal(true);
    acWindow.exec();
}

void ProfMainDialog::on_TestListButton_clicked()
{
    this->testDialog =new TestList(this,user);
    testDialog->setModal(true);
    testDialog->exec();

    if(this->testDialog!=nullptr)
    {
        delete testDialog;
        testDialog=nullptr;
    }
}

void ProfMainDialog::on_logOutButton_clicked()
{
    //this->user->logOut();
    close();
}
