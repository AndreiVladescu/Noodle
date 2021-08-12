#include "ui_quizeslist.h"
#include "ui_testattempt.h"
#include "attemptquiz.h"

testAttempt::testAttempt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testAttempt)
{
    ui->setupUi(this);

}

testAttempt::~testAttempt()
{
    delete ui;
}

void testAttempt::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->attemptButton->setEnabled(true);
}

void testAttempt::on_attemptButton_clicked()
{
    attemptQuiz psWindow(this);
    psWindow.setModal(true);
    psWindow.exec();
}
