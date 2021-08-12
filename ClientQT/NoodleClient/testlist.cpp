#include "testlist.h"
#include "ui_testlist.h"
#include "profesor.h"
#include <QMessageBox>
#include "parser.h"
#include <QtDebug>

TestList::TestList(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::TestList), user(u)
{
    ui->setupUi(this);
    setWindowTitle("Tests");
    ui->refreshButton->hide();

}

TestList::~TestList()
{
    delete ui;
    if(this->makeTest!=nullptr)
    {
        delete makeTest;
        makeTest=nullptr;
    }
}

void TestList::on_createTestButton_clicked()
{
    this->makeTest =new TestDetails(this,user);
    makeTest->setModal(true);
    makeTest->exec();
    //dupa ce s-a inchis fereastra de createTest
    if(this->makeTest!=nullptr)
    {
        delete makeTest;
        makeTest=nullptr;
    }
}

void TestList::on_setSubjectButton_clicked()
{
    string subj=ui->subjectComboBox->currentText().toStdString();
    vector<string> v;
    v.push_back(to_string(user->getUserID()));
    v.push_back(ui->subjectComboBox->currentText().toStdString());
    dynamic_cast<Profesor*>(user)->sendSubject(v);
    dynamic_cast<Profesor*>(user)->setSubject(subj);
    on_refreshButton_clicked();
}

void TestList::on_refreshButton_clicked()
{
    if(dynamic_cast<Profesor*>(user)->getSubject()=="")
    {
        QMessageBox::warning(this,"Error","You must choose a subject!");
    }
    else
    {
        vector<vector<string>> mat;
        mat=dynamic_cast<Profesor*>(user)->seeTests();

        populateTestList(mat);
        //cere test list pt subjectul respectiv
    }
}

void TestList::populateTestList(vector<vector<string> > &mat)
{

    // reset table first
    ui->testsTableList->reset();

    ui->testsTableList->setRowCount(0);
    //trimite serveru lista de users
    int nrT=mat.size();
    ui->testsTableList->setRowCount(nrT);
    ui->testsTableList->setColumnCount(8);
    //
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    ui->testsTableList->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    //

    ui->testsTableList->verticalHeader()->hide(); // hide vertical header
    QStringList tableHeader;
    tableHeader << "ID" << "Name" << "Date"<<"Hour"<<"Time"<<"Number of questions"<<"Number of groups"<<"Study groups";
    ui->testsTableList->setHorizontalHeaderLabels(tableHeader);

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

        ui->testsTableList->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(mat[i][2])));// id column
        ui->testsTableList->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(mat[i][0])));// name column
        ui->testsTableList->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(dataT)));// data column
        ui->testsTableList->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(timeT)));// hour column
        ui->testsTableList->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(mat[i][3])));// time column
        ui->testsTableList->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(mat[i][mat[i].size()-1])));// nrQuestions column

        ui->testsTableList->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(mat[i][4])));// nrStudyGroups column

        int nrSG=atoi(mat[i][4].c_str());
        vector<string> groups;
        for(int j=0;j<nrSG;j++)
        {
            groups.push_back(mat[i][4+j+1]);
        }
        ui->testsTableList->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(p->parseString(groups,','))));// studyGroups column

    }
}



void TestList::on_assignButton_clicked()
{
    vector<string> gr;
    string parsedGroups;
    Parser* p=Parser::getInstance();
    int y= ui->testsTableList->selectedItems().count();
    if(y==0)
    {
       QMessageBox::warning(this,"Error","You must select a test!");
    }
    else
    {
        parsedGroups=ui->testsTableList->selectedItems()[7]->text().toStdString();
        gr=p->unparseString(parsedGroups,",");
        bool check=true;
        for(int i=0;i<gr.size();i++)
        {
            if(gr[i]==ui->assignGroupsList->currentText().toStdString())
            {
                check=false;
                break;
            }
        }
        if(!check)
        {
            QMessageBox::warning(this,"Error","Test is already assigned to selected study group!");
        }
        else
        {
            //trimit assignul
            vector<string> vToSend;
            vToSend.push_back(ui->testsTableList->selectedItems()[0]->text().toStdString());
            vToSend.push_back(ui->assignGroupsList->currentText().toStdString());
            dynamic_cast<Profesor*>(user)->assignTestToGroup(vToSend);
            on_refreshButton_clicked();
        }
    }


}

void TestList::on_testsTableList_itemClicked(QTableWidgetItem *item)
{
    ui->assignButton->setEnabled(true);
}
