#include "onlineaccounts.h"
#include "ui_onlineaccounts.h"
#include "IUser.h"
#include "admin.h"

OnlineAccounts::OnlineAccounts(QWidget *parent,IUser* u) :
    QDialog(parent),
    ui(new Ui::OnlineAccounts) ,user(u)
{

    ui->setupUi(this);
    this->setWindowTitle("Accounts online");

}

OnlineAccounts::~OnlineAccounts()
{
    delete ui;
}

void OnlineAccounts::on_RefreshButton_clicked()
{
    vector<string> v2;
    v2=(dynamic_cast<Admin*>(user)->askForOnlineAccounts());
    populateTable(v2);
    //primesc de la server lista cu clienti on
}

void OnlineAccounts::populateTable(vector<string> &v)
{
    // reset table first
    ui->onlineUsersTable->reset();

    ui->onlineUsersTable->setRowCount(0);
    //trimite serveru lista de users

    ui->onlineUsersTable->setRowCount(atoi(v[1].c_str()));
    ui->onlineUsersTable->setColumnCount(3);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    //ui->onlineUsersTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    //ui->listAccounts->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->onlineUsersTable->verticalHeader()->hide(); // hide vertical header
    QStringList tableHeader;
    tableHeader << "ID" << "Full Name" << "Role";
    ui->onlineUsersTable->setHorizontalHeaderLabels(tableHeader);

    //int rowCount = v.size();
    int index = 2;
    for(int rowCount=0;rowCount<atoi(v[1].c_str());rowCount++)
    {
        ui->onlineUsersTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(v[index+1]))); // id column
        ui->onlineUsersTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(v[index]))); // email column
        switch(atoi(v[index+2].c_str()))
        {
        case 1:
        {
            ui->onlineUsersTable->setItem(rowCount, 2, new QTableWidgetItem("Student")); // first name column
            break;
        }
        case 2:
        {
            ui->onlineUsersTable->setItem(rowCount, 2, new QTableWidgetItem("Profesor")); // first name column
            break;
        }
        case 3:
        {
            ui->onlineUsersTable->setItem(rowCount, 2, new QTableWidgetItem("Admin")); // first name column
            break;
        }
        }

        //ui->listAccounts->setItem(rowCount, 3, new QTableWidgetItem("Cosmin")); // last name column
        //ui->listAccounts->setItem(rowCount, 4, new QTableWidgetItem("admin")); // user type column
        index+=3;
    }

}
