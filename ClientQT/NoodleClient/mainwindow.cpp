#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include "serverconnection.h"
#include "parser.h"
#include "IUser.h"
#include "factoryuser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPixmap pix(":/resources/img/distance-education-e-learning-mobile-learning-online-education-online-learning-png-512_512.png");
    //QPixmap pix(":/resources/img/noodle2.jpeg");

    //int w= ui->labelPic->width();
    //int h= ui->labelPic->height();
    //ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    //ui->labelPic->setPixmap(pix);

    this->setWindowTitle("Login Window");
    this->ui->groupBox->raise();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogIn_clicked()
{
    QString qusername = ui->lineEditUsername->text();
    QString qpassword = ui->lineEditPassword->text();
    string username = qusername.toStdString();
    string password = qpassword.toStdString();

    if(username=="" || password=="")
    {
        QMessageBox::warning(this,"Error","Username/Password field can't be empty!");
    }
    else
    {
        vector<string> vectorOfStrings;
        //create vector to send
        string aux = "17";
        vectorOfStrings.push_back(aux);
        vectorOfStrings.push_back(username);
        vectorOfStrings.push_back(password);
        //send
        serverConnection::sendMethod(vectorOfStrings);
        //receive confirmation
        bool check;
        serverConnection::receiveBoolFromServer(check);
        if(check == true)
        {
            IUser* ptr=nullptr;

            vector<string> v2= serverConnection::recvMethod();

            switch(atoi(v2[6].c_str()))
            {
            case(1):
            {
                ptr = FactoryUser::createUserStudent(v2,password);
                hide();
                studMain = new StudentMainDialog(this,ptr);
                studMain->setModal(true);
                studMain->exec();
                if (studMain!=nullptr)
                {
                    delete studMain;
                    studMain=nullptr;
                }
                show();
                break;
            }
            case(2):
            {
                ptr=FactoryUser::createUserProfesor(v2,password);
                hide();
                profMain = new ProfMainDialog(this,ptr);
                profMain->setModal(true);
                profMain->exec();
                if(profMain!=nullptr)
                {
                    delete profMain;
                    profMain=nullptr;
                }
                show();
                break;
            }
            case(3):
            {
                ptr=FactoryUser::createUserAdmin(v2,password);
                hide();
                adMain = new AdminMainDialog(this,ptr);
                adMain->show();
                adMain->setModal(true);
                adMain->exec();
                if(adMain!=nullptr)
                {
                    delete this->adMain;
                    adMain=nullptr;
                }
                show();

                break;
            }
            default:
            {
                cout<<"Invalid protocol function";
            }
            }
        }
        else
        {
            QMessageBox::warning(this,"Log in","Invalid login, please try again.");
        }

        if(!ui->RememberMe->isChecked())
        {
            ui->lineEditUsername->setText("");
            ui->lineEditPassword->setText("");

        }

    }

}

void MainWindow::on_showPassword_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);

    }
    else
    {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}
