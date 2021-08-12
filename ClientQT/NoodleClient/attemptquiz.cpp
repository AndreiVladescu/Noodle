#include "attemptquiz.h"
#include "ui_attemptquiz.h"
#include <QMessageBox>
#include <QDateTime>
#include <time.h>
#include <QTime>
#include "student.h"

attemptQuiz::attemptQuiz(string test,string s,QTime fTime,string titluTest,vector<vector<string>>&v,int& t,QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::attemptQuiz) , user(u) ,questions(v) , time(t*60) ,subjectName(s), testID(test),finishTime(fTime)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(titluTest));

    nrQ=questions.size();

    for(int i=0;i<nrQ;i++)
    {
        maxPoints+=atoi(questions[i][1].c_str());
    }
    //index
    updateIndex();
    //timer
    this->clock = new QTimer(this);
    clock->
    connect(clock,SIGNAL(timeout()), this, SLOT(showTime()));
    clock->start(1000);
    updateUI();
}

attemptQuiz::~attemptQuiz()
{
    delete ui;
}

void attemptQuiz::showTime()
{
    time--;
    if (time == 0)
    {
        QMessageBox::information(this, "Overtime", "Time is over!", QMessageBox::Button::Ok);
        endTest();
    }
    //else if (finishTime<QTime::currentTime())
    //{
        //endTest();
    //}
    ui->clockDisplay->display(QDateTime::fromSecsSinceEpoch(time).toUTC().toString("hh:mm:ss"));
}

void attemptQuiz::updateIndex()
{
    string aux;
    aux+=to_string(indexQuestion+1);
    aux+='/';
    aux+=to_string(nrQ);
    ui->indexLabel->setText(QString::fromStdString(aux));

}

void attemptQuiz::updateUI()
{
    updateIndex();
    if(indexQuestion==nrQ-1)
    {
        ui->nextQuestionButton->setText(QString::fromStdString("Finish test"));
    }
    vector<string> aux=questions[indexQuestion];
    switch(atoi(aux[2].c_str()))
    {
    case 1:
    {
        ui->questionBodyLabel->setText(QString::fromStdString(aux[0]));

        ui->answerLabel->hide();
        ui->openAnswerEdit->clear();
        ui->openAnswerEdit->hide();

        ui->chooseBetweenLabel->show();

        switch (atoi(aux[3].c_str()))
        {
        case 2:
        {
            ui->answer1->setCheckState(Qt::Unchecked);
            ui->answer1->setText(QString::fromStdString(aux[4]));
            ui->answer1->show();

            ui->answer2->setCheckState(Qt::Unchecked);
            ui->answer2->setText(QString::fromStdString(aux[6]));
            ui->answer2->show();

            ui->answer3->setCheckState(Qt::Unchecked);
            ui->answer3->hide();
            ui->answer4->setCheckState(Qt::Unchecked);
            ui->answer4->hide();


            break;

        }
        case 3:
        {
            ui->answer1->setCheckState(Qt::Unchecked);
            ui->answer1->setText(QString::fromStdString(aux[4]));
            ui->answer1->show();

            ui->answer2->setCheckState(Qt::Unchecked);
            ui->answer2->setText(QString::fromStdString(aux[6]));
            ui->answer2->show();

            ui->answer3->setCheckState(Qt::Unchecked);
            ui->answer3->setText(QString::fromStdString(aux[8]));
            ui->answer3->show();

            ui->answer4->setCheckState(Qt::Unchecked);
            ui->answer4->hide();

            break;
        }
        case 4:
        {
            ui->answer1->setCheckState(Qt::Unchecked);
            ui->answer1->setText(QString::fromStdString(aux[4]));
            ui->answer1->show();

            ui->answer2->setCheckState(Qt::Unchecked);
            ui->answer2->setText(QString::fromStdString(aux[6]));
            ui->answer2->show();

            ui->answer3->setCheckState(Qt::Unchecked);
            ui->answer3->setText(QString::fromStdString(aux[8]));
            ui->answer3->show();

            ui->answer4->setCheckState(Qt::Unchecked);
            ui->answer4->setText(QString::fromStdString(aux[10]));
            ui->answer4->show();


            break;
        }

        }

        break;
    }
    case 2:
    {
        ui->questionBodyLabel->setText(QString::fromStdString(aux[0]));

        ui->chooseBetweenLabel->hide();
        ui->answer1->hide();
        ui->answer1->text().clear();
        ui->answer2->hide();
        ui->answer2->text().clear();
        ui->answer3->hide();
        ui->answer3->text().clear();
        ui->answer4->hide();
        ui->answer4->text().clear();

        ui->answerLabel->show();
        ui->openAnswerEdit->clear();
        ui->openAnswerEdit->show();

        break;
    }
    }
}

void attemptQuiz::endTest()
{
    calculateGrade();
    sendGrade();
    QMessageBox::information(this, "End", "Test have been submitted!", QMessageBox::Button::Ok);
    close();
}

void attemptQuiz::calculateQPoints()
{
    vector<string>aux=questions[indexQuestion];

    switch(atoi(aux[2].c_str()))
    {
    case 1:
    {
        int numberOfAnswers=atoi(aux[3].c_str());
        int index=5;
        int nrCorrect=0;
        for(int j=0;j<numberOfAnswers;j++)
        {
            if(aux[index]=="1")
            {
                nrCorrect++;
            }
            index+=2;
        }
        int nrChecked=0;
        if(ui->answer1->isChecked())
            nrChecked++;
        if(ui->answer2->isChecked())
            nrChecked++;
        if(ui->answer3->isChecked())
            nrChecked++;
        if(ui->answer4->isChecked())
            nrChecked++;

        if(nrChecked<=nrCorrect)
        {
            if(checkSuppAnswer(aux,numberOfAnswers))
            {
                break;
            }
            else
            {
                switch (numberOfAnswers)
                {
                case 2:
                {
                    if(ui->answer1->isChecked() && aux[5]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    if(ui->answer2->isChecked() && aux[7]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    break;
                }
                case 3:
                {
                    if(ui->answer1->isChecked() && aux[5]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    if(ui->answer2->isChecked() && aux[7]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    if(ui->answer3->isChecked() && aux[9]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    break;
                }
                case 4:
                {
                    if(ui->answer1->isChecked() && aux[5]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    if(ui->answer2->isChecked() && aux[7]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    if(ui->answer3->isChecked() && aux[9]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    if(ui->answer4->isChecked() && aux[11]=="1")
                    {
                        currentPoints+=atof(aux[1].c_str())/(double)nrCorrect;
                    }
                    break;
                }
                }
            }

        }
        break;
    }
    case 2:
    {
        if(ui->openAnswerEdit->text().toStdString()==aux[3])
        {
            currentPoints+=atoi(aux[1].c_str());
        }
        break;
    }
    }
}

void attemptQuiz::calculateGrade()
{
    if(currentPoints!=0)
    {
        grade = currentPoints*10/maxPoints;
    }
    else
        grade=2;
}

void attemptQuiz::sendGrade()
{
    vector<string> v;
    v.push_back(subjectName);
    v.push_back(to_string(grade));
    dynamic_cast<Student*>(user)->sendTestResult(v);
    dynamic_cast<Student*>(user)->addFinishedTest(testID);
}

bool attemptQuiz::checkSuppAnswer(vector<string> aux,int nrAns)
{
    switch(nrAns)
    {
    case 2:
    {
        if(ui->answer1->isChecked() && aux[5]=="0")
        {
            return true;
        }
        if(ui->answer2->isChecked() && aux[7]=="0")
        {
            return true;
        }
        return false;
        break;
    }
    case 3:
    {
        if(ui->answer1->isChecked() && aux[5]=="0")
        {
            return true;
        }
        if(ui->answer2->isChecked() && aux[7]=="0")
        {
            return true;
        }
        if(ui->answer3->isChecked() && aux[9]=="0")
        {
            return true;
        }
        return false;
        break;
    }
    case 4:
    {
        if(ui->answer1->isChecked() && aux[5]=="0")
        {
            return true;
        }
        if(ui->answer2->isChecked() && aux[7]=="0")
        {
            return true;
        }
        if(ui->answer3->isChecked() && aux[9]=="0")
        {
            return true;
        }
        if(ui->answer4->isChecked() && aux[11]=="0")
        {
            return true;
        }
        return false;
        break;
    }
    }
    return false;
}

void attemptQuiz::on_nextQuestionButton_clicked()
{
    calculateQPoints();
    indexQuestion++;
    if(indexQuestion==nrQ)
        endTest();
    else
        updateUI();
}
