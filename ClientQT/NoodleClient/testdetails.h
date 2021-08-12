#ifndef TESTDETAILS_H
#define TESTDETAILS_H

#include <QDialog>
#include <vector>
#include <string>
#include <iostream>

namespace Ui {
class TestDetails;
}

using namespace std;


class IUser;

class TestDetails : public QDialog
{
    Q_OBJECT

public:
    explicit TestDetails(QWidget *parent = nullptr,IUser* u=nullptr);
    ~TestDetails();

private slots:
    void on_createButton_clicked();

private:
    Ui::TestDetails *ui;
    IUser* user;
};

#endif // TESTDETAILS_H
