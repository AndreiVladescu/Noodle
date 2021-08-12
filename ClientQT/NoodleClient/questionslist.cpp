#include "questionslist.h"
#include "ui_questionslist.h"

QuestionsList::QuestionsList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionsList)
{
    ui->setupUi(this);
}

QuestionsList::~QuestionsList()
{
    delete ui;
}
