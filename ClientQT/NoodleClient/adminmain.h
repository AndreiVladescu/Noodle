#ifndef ADMINMAIN_H
#define ADMINMAIN_H

#include <QMainWindow>

namespace Ui {
class AdminMain;
}

class AdminMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMain(QWidget *parent = nullptr);
    ~AdminMain();

private:
    Ui::AdminMain *ui;
    QWidget *parent;
};

#endif // ADMINMAIN_H
