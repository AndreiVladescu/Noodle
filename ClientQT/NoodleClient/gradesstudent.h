#ifndef GRADESSTUDENT_H
#define GRADESSTUDENT_H

#include <QDialog>
#include <vector>
#include <string>

using namespace std;

namespace Ui {
class gradesStudent;
}

class IUser;

class gradesStudent : public QDialog
{
    Q_OBJECT

public:
    explicit gradesStudent(QWidget *parent = nullptr,IUser* u=nullptr);
    ~gradesStudent();

private:
    void populateGradesList(vector<string>&);

    Ui::gradesStudent *ui;
    IUser* user=nullptr;
};

#endif // GRADESSTUDENT_H
