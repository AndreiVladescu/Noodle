#ifndef TESTLIST_H
#define TESTLIST_H

#include <QDialog>
#include "testdetails.h"
#include <QTableWidgetItem>


namespace Ui {
class TestList;
}

class IUser;

class TestList : public QDialog
{
    Q_OBJECT

public:
    explicit TestList(QWidget *parent = nullptr,IUser* user=nullptr);
    ~TestList();

private slots:
    void on_createTestButton_clicked();


    void on_setSubjectButton_clicked();

    void on_refreshButton_clicked();

    void on_assignButton_clicked();

    void on_testsTableList_itemClicked(QTableWidgetItem *item);

private:
    Ui::TestList *ui;
    TestDetails *makeTest=nullptr;
    IUser* user=nullptr;

    void populateTestList(vector<vector<string>>&);


};

#endif // TESTLIST_H
