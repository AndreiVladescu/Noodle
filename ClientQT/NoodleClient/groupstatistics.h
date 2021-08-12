#ifndef GROUPSTATISTICS_H
#define GROUPSTATISTICS_H

#include <QDialog>

namespace Ui {
class groupStatistics;
}

class groupStatistics : public QDialog
{
    Q_OBJECT

public:
    explicit groupStatistics(QWidget *parent = nullptr);
    ~groupStatistics();

private:
    Ui::groupStatistics *ui;
};

#endif // GROUPSTATISTICS_H
