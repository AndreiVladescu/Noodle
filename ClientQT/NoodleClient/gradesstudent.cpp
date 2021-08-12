#include "gradesstudent.h"
#include "ui_gradesstudent.h"
#include "IUser.h"
#include "student.h"

gradesStudent::gradesStudent(QWidget *parent,IUser *u) :
    QDialog(parent),
    ui(new Ui::gradesStudent) , user(u)
{
    ui->setupUi(this);
    this->setWindowTitle("Grades");

    vector<string> v;
    v=dynamic_cast<Student*>(user)->askForGrades();
    populateGradesList(v);
}

gradesStudent::~gradesStudent()
{
    delete ui;
}

void gradesStudent::populateGradesList(vector<string> &v)
{
    // reset table first
    ui->gradesTable->reset();
    ui->gradesTable->setRowCount(0);

    ui->gradesTable->setRowCount(atoi(v[1].c_str()));
    ui->gradesTable->setColumnCount(3);

    //ui->gradesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->gradesTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    //ui->gradesTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    ui->gradesTable->verticalHeader()->hide(); // hide vertical header
    QStringList tableHeader;
    tableHeader << "Discipline" << "Grade" << "Status";
    ui->gradesTable->setHorizontalHeaderLabels(tableHeader);

    int index = 2;
    for(int rowCount=0;rowCount<atoi(v[1].c_str());rowCount++)
    {
        ui->gradesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(v[index]))); // id column
        ui->gradesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(v[index+1]))); // email column
        if(atoi(v[index+1].c_str()) < 5)
        {
            ui->gradesTable->setItem(rowCount, 2, new QTableWidgetItem("Nepromovat")); // first name column

        }
        else
        {
            ui->gradesTable->setItem(rowCount, 2, new QTableWidgetItem("Promovat")); // first name column
        }
        index+=2;
    }

}
