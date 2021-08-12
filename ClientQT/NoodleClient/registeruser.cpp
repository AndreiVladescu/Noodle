#include "registeruser.h"
#include "ui_registeruser.h"
#include "IUser.h"
#include "admin.h"
#include <QMessageBox>


registerUser::registerUser(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::registerUser) , user(u)
{
    ui->setupUi(this);
    setWindowTitle("Register new user");

    ui->studyGroupLabel->hide();
    ui->studyGroupEdit->hide();
    ui->studyYearLabel->hide();
    ui->studyYearEdit->hide();
}

registerUser::~registerUser()
{
    delete ui;
}

void registerUser::on_adminRadioButton_clicked()
{
    ui->studyGroupLabel->hide();
    ui->studyGroupEdit->hide();
    ui->studyGroupEdit->clear();
    ui->studyYearLabel->hide();
    ui->studyYearEdit->hide();
    ui->studyYearEdit->clear();

}

void registerUser::on_professorRadioButton_clicked()
{
    ui->studyGroupLabel->hide();
    ui->studyGroupEdit->hide();
    ui->studyGroupEdit->clear();
    ui->studyYearLabel->hide();
    ui->studyYearEdit->hide();
    ui->studyYearEdit->clear();
}

void registerUser::on_studentRadioButton_clicked()
{
    ui->studyGroupLabel->show();
    ui->studyGroupEdit->show();
    ui->studyYearLabel->show();
    ui->studyYearEdit->show();

}

void registerUser::on_confirmButton_clicked()
{
    if(ui->lastNameEdit->text().toStdString()==""
            || ui->firstNameEdit->text().toStdString()==""
            || ui->usernameEdit->text().toStdString()==""
            || ui->password1Edit->text().toStdString()==""
            || ui->password2Edit->text().toStdString()=="")
    {
        QMessageBox::warning(this,"Register error","All fields must be completed.");
    }
    else
    {
        if(!(ui->studentRadioButton->isChecked()
                || ui->professorRadioButton->isChecked()
                || ui->adminRadioButton->isChecked()))
        {
            QMessageBox::warning(this,"Register error", "One role must be checked.");
        }
        else
        {
            if(ui->studentRadioButton->isChecked())
            {
                if(ui->studyGroupEdit->text().toStdString() == ""
                        || ui->studyYearEdit->text().toStdString()=="")
                {
                    QMessageBox::warning(this,"Register error","All fields must be completed.");
                }
                else
                {
                    if(ui->password1Edit->text()!=ui->password2Edit->text())
                    {
                        QMessageBox::warning(this,"Register error","Passwords don't match, please try again.");
                    }
                    else
                    {
                        this->sendUserRegistration();
                    }
                }
            }
            else
            {
                if(ui->password1Edit->text()!=ui->password2Edit->text())
                {
                    QMessageBox::warning(this,"Register error","Passwords don't match, please try again.");
                }
                else
                {
                    this->sendUserRegistration();
                }
            }
        }
    }
}

void registerUser::sendUserRegistration()
{
    vector<string> v;
    v.push_back("3");

    if(ui->studentRadioButton->isChecked())
    {
        v.push_back("1");
        v.push_back(ui->lastNameEdit->text().toStdString());
        v.push_back(ui->firstNameEdit->text().toStdString());
        v.push_back(ui->usernameEdit->text().toStdString());
        v.push_back(ui->password1Edit->text().toStdString());
        v.push_back(ui->studyGroupEdit->text().toStdString());
        v.push_back(ui->studyYearEdit->text().toStdString());
    }
    else
    {
        if(ui->professorRadioButton->isChecked())
        {
            v.push_back("2");
        }
        else
        {
            v.push_back("3");
        }
        v.push_back(ui->lastNameEdit->text().toStdString());
        v.push_back(ui->firstNameEdit->text().toStdString());
        v.push_back(ui->usernameEdit->text().toStdString());
        v.push_back(ui->password1Edit->text().toStdString());
    }
    if(dynamic_cast<Admin*>(this->user)->insertUser(v))
    {
        QMessageBox::information(this,"Register confirmation", "User added successfully!");
        close();
    }
    else
    {
        QMessageBox::warning(this,"Register error","Please choose another username.");
    }

}
