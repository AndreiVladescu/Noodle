#include "studentmaindialog.h"
#include "ui_studentmaindialog.h"
#include "IUser.h"
#include "accountinfo.h"
#include "changepassword.h"
#include "serverconnection.h"

StudentMainDialog::StudentMainDialog(QWidget *parent, IUser *u) :
    QDialog(parent),
    ui(new Ui::StudentMainDialog) , user(u)
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

StudentMainDialog::~StudentMainDialog()
{
    delete ui;
    if(this->user!=nullptr)
    {
        user->logOut();
        delete user;

    }
    if(this->resDialog!=nullptr)
    {
        delete resDialog;
        resDialog=nullptr;
    }
    if(this->testDialog!=nullptr)
    {
        delete testDialog;
        testDialog=nullptr;
    }
    if(this->gradesList!=nullptr)
    {
        delete gradesList;
        gradesList=nullptr;
    }
}



void StudentMainDialog::on_changePasswButton_clicked()
{
    ChangePassword psWindow(this,user);
    psWindow.setModal(true);
    psWindow.exec();
}

void StudentMainDialog::on_examButton_clicked()
{
    this->testDialog =new studentQuizList(this,user);
    testDialog->setModal(true);
    testDialog->exec();

    if(this->testDialog!=nullptr)
    {
        delete testDialog;
        testDialog=nullptr;
    }
}

void StudentMainDialog::on_pushButton_clicked()
{
    //this->user->logOut();
    close();
}

void StudentMainDialog::on_accountInfo_clicked()
{
    accountInfo acWindow(this,user);
    acWindow.setModal(true);
    acWindow.exec();
}

void StudentMainDialog::on_gradesButton_clicked()
{
    this->gradesList =new gradesStudent(this);
    gradesList->setModal(true);
    gradesList->exec();

    if(this->gradesList!=nullptr)
    {
        delete gradesList;
        gradesList=nullptr;
    }
}

void StudentMainDialog::on_groupStatisticButton_clicked()
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
