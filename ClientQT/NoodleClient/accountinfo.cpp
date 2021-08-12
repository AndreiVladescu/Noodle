#include "accountinfo.h"
#include "ui_accountinfo.h"
#include "IUser.h"
#include "student.h"
#include "profesor.h"
#include "admin.h"

accountInfo::accountInfo(QWidget *parent, IUser* u) :
    QDialog(parent),
    ui(new Ui::accountInfo) , user(u)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Account Info"));

    //
    switch (user->getUserRole())
    {
    case 1:
    {
        ui->subjectLabel->hide();
        ui->subject->hide();
        //
        ui->role->setText(QString::fromStdString("Student"));
        ui->ID->setText(QString::fromStdString(to_string(user->getUserID())));
        ui->lastName->setText(QString::fromStdString(user->getLastName()));
        ui->firstName->setText(QString::fromStdString(user->getFirstName()));
        ui->userName->setText(QString::fromStdString(user->getUserName()));

        string passw = user->getPsswrd();
        int l = passw.size();
        for(int i=0;i<l;i++)
        {
            passw[i]='*';
        }
        ui->passwrd->setText(QString::fromStdString(passw));

        ui->joinDate->setText(QString::fromStdString(user->getJoinDate()));
        ui->studyYear->setText(QString::fromStdString(dynamic_cast<Student*>(user)->getStudyYear()));
        ui->studyGroup->setText(QString::fromStdString(dynamic_cast<Student*>(user)->getStudyGroup()));

        break;
    }
    case 2:
    {

        //mut subjLabel in locul la study Year
        ui->StudyYearLabel->setText(ui->subjectLabel->text());
        //ascund
        ui->StudyGroupLabel->hide();
        ui->studyGroup->hide();
        ui->subjectLabel->hide();
        ui->subject->hide();
        //
        ui->role->setText(QString::fromStdString("Profesor"));
        ui->ID->setText(QString::fromStdString(to_string(user->getUserID())));
        ui->lastName->setText(QString::fromStdString(user->getLastName()));
        ui->firstName->setText(QString::fromStdString(user->getFirstName()));
        ui->userName->setText(QString::fromStdString(user->getUserName()));

        string passw = user->getPsswrd();
        int l = passw.size();
        for(int i=0;i<l;i++)
        {
            passw[i]='*';
        }
        ui->passwrd->setText(QString::fromStdString(passw));

        ui->joinDate->setText(QString::fromStdString(user->getJoinDate()));
        ui->studyYear->setText(QString::fromStdString(dynamic_cast<Profesor*>(user)->getSubject()));

        break;
    }
    case 3:
    {
        ui->StudyYearLabel->hide();
        ui->studyYear->hide();
        ui->StudyGroupLabel->hide();
        ui->studyGroup->hide();
        ui->subjectLabel->hide();
        ui->subject->hide();
        //
        ui->role->setText(QString::fromStdString("Admin"));
        ui->ID->setText(QString::fromStdString(to_string(user->getUserID())));
        ui->lastName->setText(QString::fromStdString(user->getLastName()));
        ui->firstName->setText(QString::fromStdString(user->getFirstName()));
        ui->userName->setText(QString::fromStdString(user->getUserName()));

        string passw = user->getPsswrd();
        int l = passw.size();
        for(int i=0;i<l;i++)
        {
            passw[i]='*';
        }
        ui->passwrd->setText(QString::fromStdString(passw));

        ui->joinDate->setText(QString::fromStdString(user->getJoinDate()));

        break;
    }
    default:
    {
        close();
    }
    }

}

accountInfo::~accountInfo()
{
    delete ui;
}
