#include "testresults.h"
#include "ui_testresults.h"
#include "profesor.h"
#include "student.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
TestResults::TestResults(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::TestResults), user(u)
{
    ui->setupUi(this);
    if(user->getUserRole()==1)
    {
        setWindowTitle("Statistics");
        string sGr;
        sGr+=dynamic_cast<Student*>(user)->getStudyGroup();
        sGr+=", Anul ";
        sGr+=dynamic_cast<Student*>(user)->getStudyYear();
        ui->studyGroupLabel->setText(QString::fromStdString(sGr));
        //hide group comboBox
        ui->studyGroupComboBox->hide();
        ui->changeGradeLE->hide();
        ui->changeGradeButton->hide();
        ui->changeGradeLabel->setText("Group average: ");

    }
    else
    {
        setWindowTitle("Grades");
    }
}

TestResults::~TestResults()
{
    delete ui;
}

void TestResults::on_seeGradesButton_clicked()
{



    if(user->getUserRole()==2)
    {
        if(dynamic_cast<Profesor*>(user)->getSubject()=="")
        {
            QMessageBox::warning(this,"Error","Professor must have a subject!");
        }
        else
        {
            vector<string> v_recv;
            vector<string> v;
            v.push_back(ui->studyGroupComboBox->currentText().toStdString());
            v.push_back(ui->subjectComboBox->currentText().toStdString());
            v_recv=dynamic_cast<Profesor*>(user)->askForStudentGrades(v);
            populateStudentList(v_recv);
        }
    }
    else
    {
        vector<string> v_recv;
        vector<string> v;
        v.push_back(dynamic_cast<Student*>(user)->getStudyGroup());
        v.push_back(ui->subjectComboBox->currentText().toStdString());
        v_recv=dynamic_cast<Student*>(user)->askForStatistics(v);

        populateStudentList(v_recv);

    }

}

void TestResults::on_changeGradeButton_clicked()
{
    if(ui->changeGradeLE->text()=="")
    {
        QMessageBox::warning(this,"Error","Grade field must be completed!");
    }
    else
    {
        if(atoi(ui->changeGradeLE->text().toStdString().c_str())>10 || atoi(ui->changeGradeLE->text().toStdString().c_str())<1)
        {
            QMessageBox::warning(this,"Error","Invalid grade!");
        }
        else
        {
            vector<string> v;
            string id=ui->studentsTable->selectedItems()[0]->text().toStdString();
            v.push_back(id);
            v.push_back(ui->subjectComboBox->currentText().toStdString());
            v.push_back(ui->changeGradeLE->text().toStdString());
            dynamic_cast<Profesor*>(user)->changeGradeOfAStudent(v);
        }
    }
    //change grade
}

void TestResults::populateStudentList(vector<string>& v)
{
    // reset table first
    ui->studentsTable->reset();

    ui->studentsTable->setRowCount(0);
    //trimite serveru lista de users
    int nr_stud=(v.size()-1)/3;

    ui->studentsTable->setRowCount(nr_stud);
    ui->studentsTable->setColumnCount(3);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->studentsTable->verticalHeader()->hide(); // hide vertical header
    QStringList tableHeader;
    tableHeader << "ID" << "Full Name" << "Grade";
    ui->studentsTable->setHorizontalHeaderLabels(tableHeader);

    //int rowCount = v.size();
    int index = 1;
    for(int i=0;i<nr_stud;i++)
    {
        ui->studentsTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(v[index+2]))); // id column
        ui->studentsTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(v[index]))); //full name
        ui->studentsTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(v[index+1]))); // grade column

        index+=3;
    }
    if(user->getUserRole()==1)
    {
        showGroupAverage();
    }
}

void TestResults::showGroupAverage()
{
    int nr=0;
    nr=ui->studentsTable->rowCount();
    double avg=0;
    if(nr!=0)
    {
        for(int i=0;i<nr;i++)
        {
            avg+=atof(ui->studentsTable->item(i,2)->text().toStdString().c_str());
        }
        avg=avg/(double)nr;
        QString QstrAvg;
        QstrAvg=QString::asprintf("Group average: %.2f",avg);
        ui->changeGradeLabel->setText(QstrAvg);
    }
    else
    {
        ui->changeGradeLabel->setText("Group average: ");
    }

}



