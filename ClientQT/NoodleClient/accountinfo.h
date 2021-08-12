#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include <QDialog>
#include <string>
#include <string.h>
#include <iostream>

namespace Ui {
class accountInfo;
}

using namespace std;

class IUser;

class accountInfo : public QDialog
{
    Q_OBJECT

public:
    explicit accountInfo(QWidget *parent = nullptr,IUser* user=nullptr);
    ~accountInfo();

private:
    Ui::accountInfo *ui;
    IUser* user;
};

#endif // ACCOUNTINFO_H
