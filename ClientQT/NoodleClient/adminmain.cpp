#include "adminmain.h"
#include "ui_adminmain.h"
#include "mainwindow.h"

AdminMain::AdminMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMain)
{
    ui->setupUi(this);
    this->parent=parent;
}

AdminMain::~AdminMain()
{
    this->parent->show();
    delete ui;

}
