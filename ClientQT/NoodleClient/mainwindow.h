#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentmaindialog.h"
#include "adminmaindialog.h"
#include "profmaindialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonLogIn_clicked();

    void on_showPassword_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    StudentMainDialog* studMain=nullptr;
    AdminMainDialog* adMain=nullptr;
    ProfMainDialog* profMain=nullptr;

};
#endif // MAINWINDOW_H
