#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QDialog>
#include <vector>
#include <string>

using namespace std;

namespace Ui {
class registerUser;
}

class IUser;

class registerUser : public QDialog
{
    Q_OBJECT

public:
    explicit registerUser(QWidget *parent = nullptr,IUser* u=nullptr);
    ~registerUser();

private slots:
    void on_adminRadioButton_clicked();

    void on_professorRadioButton_clicked();

    void on_studentRadioButton_clicked();

    void on_confirmButton_clicked();

private:
    void sendUserRegistration();
    Ui::registerUser *ui;
    IUser* user;
};

#endif // REGISTERUSER_H
