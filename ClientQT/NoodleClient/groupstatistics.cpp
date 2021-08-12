#include "groupstatistics.h"
#include "ui_groupstatistics.h"

groupStatistics::groupStatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::groupStatistics)
{
    ui->setupUi(this);
}

groupStatistics::~groupStatistics()
{
    delete ui;
}
