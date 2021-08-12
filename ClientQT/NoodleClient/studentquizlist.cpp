#include "studentquizlist.h"
#include "ui_studentquizlist.h"
#include "attemptquiz.h"
#include "student.h"
#include <QMessageBox>
#include "serverconnection.h"
#include "parser.h"
#include <QDate>
#include <QString>


studentQuizList::studentQuizList(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::studentQuizList) ,user(u)
{
    ui->setupUi(this);
    setWindowTitle("Exams");
}

studentQuizList::~studentQuizList()
{
    delete ui;
}

void studentQuizList::on_refreshButton_clicked()
{
    nrTeste=0;
    if(vTeste.size()>0)
    {
        vTeste.clear();
    }
    if(vQuestions.size()>0)
    {
        vQuestions.clear();
    }

    nrTeste=dynamic_cast<Student*>(user)->askForQuizes();

    //populateTestList(mat);
    //cere test list pt subjectul respectiv
    for(int i=0;i<nrTeste;i++)
    {
        vTeste.push_back(serverConnection::recvMethod());

        int nrQ=atoi(vTeste[i][4].c_str());
        vector<vector<string>>aux;
        for(int j=0;j<nrQ;j++)
        {
            aux.push_back(serverConnection::recvMethod());
        }
        vQuestions.push_back(aux);

    }
    populateQuizList(vTeste);
}

void studentQuizList::on_attemptButton_clicked()
{
    if(ui->quizesList->selectedItems()[7]->text().toStdString()=="Finished")
    {
        QMessageBox::warning(this,"Quiz","Quiz already submitted!");
    }
    else
    {
        if(!checkIfCanStartQuiz())
        {
            QMessageBox::warning(this,"Quiz","Quiz not available!");
            on_refreshButton_clicked();
        }
        else
        {
            tryToAttempt();
        }
    }

}

void studentQuizList::on_quizesList_itemClicked(QTableWidgetItem *item)
{
    ui->attemptButton->setEnabled(true);
}

void studentQuizList::populateQuizList(vector<vector<string> > &mat)
{
    // reset table first
    ui->quizesList->reset();

    ui->quizesList->setRowCount(0);
    //trimite serveru lista de users
    int nrT=mat.size();
    ui->quizesList->setRowCount(nrT);
    ui->quizesList->setColumnCount(8);
    //
    ui->quizesList->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->quizesList->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->quizesList->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->quizesList->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->quizesList->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->quizesList->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    ui->quizesList->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    ui->quizesList->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    //

    ui->quizesList->verticalHeader()->hide(); // hide vertical header
    QStringList tableHeader;
    tableHeader << "ID" <<"Subject"<< "Name" << "Date"<<"Hour"<<"Time"<<"Number of questions"<<"Status";
    ui->quizesList->setHorizontalHeaderLabels(tableHeader);

    for(int i=0;i<nrT;i++)
    {

        //
        vector<string> datetime;
        Parser* p=Parser::getInstance();
        datetime=p->unparseString(mat[i][1],"/");
        if(datetime.size()!=5)
            continue;
        string dataT;
        string timeT;
        dataT+=datetime[2];
        dataT+='/';
        dataT+=datetime[3];
        dataT+='/';
        dataT+=datetime[4];
        timeT+=datetime[1];
        timeT+=':';
        if(datetime[0].size()==1)
        {
            timeT+='0';
        }
        timeT+=datetime[0];

        ui->quizesList->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(mat[i][2])));// id column
        ui->quizesList->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(mat[i][5])));// subject column

        ui->quizesList->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(mat[i][0])));// name column
        ui->quizesList->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(dataT)));// data column
        ui->quizesList->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(timeT)));// hour column
        ui->quizesList->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(mat[i][3])));// time column
        ui->quizesList->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(mat[i][4])));// nrQuestions column


        int zi=atoi(datetime[2].c_str());
        int luna=atoi(datetime[3].c_str());
        int an=atoi(datetime[4].c_str());
        int minute=atoi(datetime[0].c_str());
        int ore=atoi(datetime[1].c_str());
        int duration=atoi(mat[i][3].c_str());

        if(checkStatus(zi,luna,an,minute,ore,duration))
        {
            if(dynamic_cast<Student*>(user)->getNrOfFinishedTests()!=0)
            {
                vector<string> finishedT=dynamic_cast<Student*>(user)->getFinishedTests();
                bool isFinished=false;
                for(int j=0;j<finishedT.size();j++)
                {
                    if(mat[i][2]==finishedT[j])
                    {
                        isFinished=true;
                        break;
                    }
                }
                if(isFinished)
                {
                    ui->quizesList->setItem(i, 7, new QTableWidgetItem(QString::fromStdString("Finished")));// available column
                }
                else
                {
                    ui->quizesList->setItem(i, 7, new QTableWidgetItem(QString::fromStdString("Available")));// available column
                }
            }
            else
            {
                ui->quizesList->setItem(i, 7, new QTableWidgetItem(QString::fromStdString("Available")));// available column
            }

        }
        else
        {
            ui->quizesList->setItem(i, 7, new QTableWidgetItem(QString::fromStdString("Not available")));// available column
        }
    }
}

bool studentQuizList::checkStatus(int zi,int luna,int an,int min,int ore,int duration)
{
    QDate azi = QDate::currentDate();
    QDate dataTest(an,luna,zi);

    QTime acum = QTime::currentTime();
    QTime inceputTest(ore,min);
    QTime finalTest=inceputTest.addSecs(duration*60);

    if(azi==dataTest)
    {
        if(acum>=inceputTest && acum <=finalTest)
        {
            return true;
        }
        return false;
    }
    else
        return false;
}

bool studentQuizList::checkIfCanStartQuiz()
{

    Parser* p=Parser::getInstance();
    vector<string> v;

    int zi=0;
    int luna=0;
    int an=0;
    int minute=0;
    int ore=0;

    int duration=atoi(ui->quizesList->selectedItems()[5]->text().toStdString().c_str());



    string date=ui->quizesList->selectedItems()[3]->text().toStdString();
    string time=ui->quizesList->selectedItems()[4]->text().toStdString();
    v=p->unparseString(date,"/");
    if(v.size()==3)
    {
        zi=atoi(v[0].c_str());
        luna=atoi(v[1].c_str());
        an=atoi(v[2].c_str());
    }
    v.clear();
    v=p->unparseString(time,":");
    if(v.size()==2)
    {
        ore=atoi(v[0].c_str());
        minute=atoi(v[1].c_str());
    }
    if(checkStatus(zi,luna,an,minute,ore,duration))
        return true;
    return false;
}

void studentQuizList::tryToAttempt()
{
    if(vTeste.size()>0)
    {
        int index=ui->quizesList->currentRow(); ///?

        int timpT=atoi(vTeste[index][3].c_str());

        string startTimes=ui->quizesList->selectedItems()[4]->text().toStdString();
        vector<string> v;
        Parser* p=Parser::getInstance();
        v=p->unparseString(startTimes,":");
        int h=atoi(v[0].c_str());
        int m=atoi(v[1].c_str());
        int duration =atoi( ui->quizesList->selectedItems()[5]->text().toStdString().c_str());
        QTime startTime(h,m);
        QTime finishTime=startTime.addSecs(duration*60);

        this->activeQuiz =new attemptQuiz(vTeste[index][2],vTeste[index][5],finishTime,vTeste[index][0],this->vQuestions[index],timpT,this,user);
        activeQuiz->setModal(true);
        activeQuiz->exec();

        //dupa ce s-a inchis fereastra de createTest
        if(this->activeQuiz!=nullptr)
        {
            delete activeQuiz;
            activeQuiz=nullptr;
        }
        on_refreshButton_clicked();
    }
}

void studentQuizList::on_quizesList_itemDoubleClicked(QTableWidgetItem *item)
{
    if(ui->quizesList->selectedItems()[7]->text().toStdString()=="Finished")
    {
        QMessageBox::warning(this,"Quiz","Quiz already submitted!");
    }
    else
    {
        if(!checkIfCanStartQuiz())
        {
            QMessageBox::warning(this,"Quiz","Quiz not available!");
            on_refreshButton_clicked();
        }
        else
        {
            tryToAttempt();
        }
    }
}
