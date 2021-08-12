#ifndef UI_QUIZESLIST_H
#define UI_QUIZESLIST_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class testAttempt;
}

class testAttempt : public QDialog
{
    Q_OBJECT

public:
    explicit testAttempt(QWidget *parent = nullptr);
    ~testAttempt();

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_attemptButton_clicked();

    void on_refreshButton_clicked();

private:
    Ui::testAttempt *ui;
};

#endif // UI_QUIZESLIST_H
