#include "profcreatetest.h"
#include "ui_profcreatetest.h"

profCreateTest::profCreateTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profCreateTest)
{
    ui->setupUi(this);
}

profCreateTest::~profCreateTest()
{
    delete ui;
}
