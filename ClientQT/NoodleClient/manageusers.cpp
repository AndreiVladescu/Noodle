#include "manageusers.h"
#include "ui_manageusers.h"
#include "registeruser.h"
#include "IUser.h"
#include "admin.h"
#include <QMessageBox>

manageUsers::manageUsers(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::manageUsers) , user(u)
{
    ui->setupUi(this);
    this->setWindowTitle("Manage Accounts");


    vector<string>v2;

    v2= dynamic_cast<Admin*>(user)->askForAllRegisteredUsers();

    populateUsersTable(v2);
}

manageUsers::~manageUsers()
{
    delete ui;
}


void manageUsers::on_addUserButton_clicked()
{
    registerUser ruWindow(this,user);
    ruWindow.setModal(true);
    ruWindow.exec();
    //de creat fereastra pt introdus date si
    //trimis la server
}

void manageUsers::on_deleteUserButton_clicked()
{
    ui->listAccounts->selectedItems();

    string id = ui->listAccounts->selectedItems()[0]->text().toStdString();
    vector<string> v;

    dynamic_cast<Admin*>(user)->deleteUser(id);
    QMessageBox::information(this,"Deleted account","Account deleted successfully");
    for(int i=0;i<ui->listAccounts->rowCount();i++)
    {
        QTableWidgetItem* q= ui->listAccounts->item(i,0);
        if(q->text().toStdString() ==id)
        {
            ui->listAccounts->removeRow(i);
            break;
        }
    }
    ui->listAccounts->setRowCount(ui->listAccounts->rowCount()-1);
    ui->searchUser->clear();
    showAllUsers();
}

void manageUsers::populateUsersTable(vector<string>& v)
{
    //getUsersList(ui.searchUserInput->text());
    // reset table first
    ui->listAccounts->reset();
    int nr = atoi(v[1].c_str())/4;

    ui->listAccounts->setRowCount(0);
    //trimite serveru lista de users

    ui->listAccounts->setRowCount(nr);
    ui->listAccounts->setColumnCount(4);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->listAccounts->verticalHeader()->hide(); // hide vertical header
    QStringList tableHeader;
    tableHeader << "ID" << "Full name" << "Username"<<"Role";
    ui->listAccounts->setHorizontalHeaderLabels(tableHeader);

    int index = 2;
    for(int row=0;row<nr;row++)
    {
        ui->listAccounts->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(v[index]))); // id column
        ui->listAccounts->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(v[index+1]))); // fullname column
        ui->listAccounts->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(v[index+2]))); // email column

        switch(atoi(v[index+3].c_str()))
        {
        case 1:
        {
            ui->listAccounts->setItem(row, 3, new QTableWidgetItem("Student")); // first name column
            break;
        }
        case 2:
        {
            ui->listAccounts->setItem(row, 3, new QTableWidgetItem("Profesor")); // first name column
            break;
        }
        case 3:
        {
            ui->listAccounts->setItem(row, 3, new QTableWidgetItem("Admin")); // first name column
            break;
        }
        }

        //ui->listAccounts->setItem(rowCount, 3, new QTableWidgetItem("Cosmin")); // last name column
        //ui->listAccounts->setItem(rowCount, 4, new QTableWidgetItem("admin")); // user type column
        index+=4;
    }



    //ui->listAccounts->setItem(rowCount, 0, new QTableWidgetItem(QString::number(121))); // id column
    //ui->listAccounts->setItem(rowCount, 1, new QTableWidgetItem("admin")); // email column
    //ui->listAccounts->setItem(rowCount, 2, new QTableWidgetItem("Rosu")); // first name column
    //ui->listAccounts->setItem(rowCount, 3, new QTableWidgetItem("Cosmin")); // last name column
    //ui->listAccounts->setItem(rowCount, 4, new QTableWidgetItem("admin")); // user type column
    //rowCount++;




    //ui->onlineUsersTable->setRowCount(atoi(v[1].c_str()));
    //ui->onlineUsersTable->setColumnCount(3);

    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    //ui->onlineUsersTable->verticalHeader()->hide(); // hide vertical header
    //QStringList tableHeader;
    //tableHeader << "ID" << "Full Name" << "Role";
    //ui->onlineUsersTable->setHorizontalHeaderLabels(tableHeader);

    //int rowCount = v.size();

}


void manageUsers::on_listAccounts_itemClicked(QTableWidgetItem *item)
{
    ui->deleteUserButton->setEnabled(true);
}



void manageUsers::on_searchUser_textChanged(const QString &arg1)
{
    if(arg1.toStdString()=="")
    {
        showAllUsers();
    }
    else
    {
        string aux = arg1.toStdString();
        showUsersByString(aux);
    }

}

void manageUsers::showAllUsers()
{
    for(int i=0;i<ui->listAccounts->rowCount();i++)
    {
        if(ui->listAccounts->isRowHidden(i))
            ui->listAccounts->showRow(i);
    }
}

void manageUsers::showUsersByString(string &s)
{
    showAllUsers();
    for(int i=0;i<ui->listAccounts->rowCount();i++)
    {
        QTableWidgetItem* q= ui->listAccounts->item(i,1);
        if(q->text().toStdString().find(s) ==string::npos)
        {
            if(!ui->listAccounts->isRowHidden(i))
                ui->listAccounts->hideRow(i);
        }
        else
        {
            if(ui->listAccounts->isRowHidden(i))
                ui->listAccounts->showRow(i);
        }
    }
}
