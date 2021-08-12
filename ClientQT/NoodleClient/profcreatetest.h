#ifndef PROFCREATETEST_H
#define PROFCREATETEST_H

#include <QWidget>

namespace Ui {
class profCreateTest;
}

class profCreateTest : public QWidget
{
    Q_OBJECT

public:
    explicit profCreateTest(QWidget *parent = nullptr);
    ~profCreateTest();

private:
    Ui::profCreateTest *ui;
};

#endif // PROFCREATETEST_H
