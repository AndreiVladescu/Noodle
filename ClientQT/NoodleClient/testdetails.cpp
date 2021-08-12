#include "testdetails.h"
#include "ui_testdetails.h"
#include "createtestquestions.h"
#include <QMessageBox>
#include "profesor.h"

TestDetails::TestDetails(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::TestDetails), user(u)
{
    ui->setupUi(this);
    setWindowTitle("Test details");
}

TestDetails::~TestDetails()
{
    delete ui;
}

void TestDetails::on_createButton_clicked()
{
    if( ui->testNameLE->text()=="" ||
            ui->numberQuestionsLE->text()=="" ||
            ui->availableTimeLE->text()=="")
    {
        QMessageBox::warning(this,"Error","Fields can't be empty!");
    }
    else
    {
        if(atoi(ui->numberQuestionsLE->text().toStdString().c_str())==0)
        {
           QMessageBox::warning(this,"Error","Can't create empty test!");
        }
        else
        {
            //trimit test creat la server apoi creez si trimit si intrebarile
            if(ui->dateEdit->date()<QDate::currentDate() || ui->timeEdit->time()<QTime::currentTime())
            {
                QMessageBox::warning(this,"Error","Date/Time not valid!");
            }
            else
            {
                vector<string>v;
                //1
                v.push_back(ui->testNameLE->text().toStdString());
                //2
                int minute;
                int ore;
                string testTime;
                ore=ui->timeEdit->time().hour();
                minute=ui->timeEdit->time().minute();
                testTime+=to_string(minute);
                testTime+='/';
                testTime+=to_string(ore);
                testTime+='/';
                testTime+=ui->dateEdit->text().toStdString();

                v.push_back(testTime);
                //3
                v.push_back(ui->subjectList->currentText().toStdString());
                //4
                v.push_back(ui->numberQuestionsLE->text().toStdString());
                //5
                v.push_back(ui->availableTimeLE->text().toStdString());


                dynamic_cast<Profesor*>(user)->sendTest(v);

                //cream si trimitem testele
                createTestQuestions questWindow(this,atoi(ui->numberQuestionsLE->text().toStdString().c_str()),user);
                questWindow.setModal(true);
                questWindow.exec();

                close();

                //apoi trimite assigned to grupa
                //v.empty();
                //v.push_back(ui->groupsList->currentText().toStdString());
                //dynamic_cast<Profesor*>(user)->assignTest(v);

            }

        }
    }
}
