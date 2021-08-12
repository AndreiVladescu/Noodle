#ifndef QUESTIONSLIST_H
#define QUESTIONSLIST_H

#include <QDialog>

namespace Ui {
class QuestionsList;
}

class QuestionsList : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionsList(QWidget *parent = nullptr);
    ~QuestionsList();

private:
    Ui::QuestionsList *ui;
};

#endif // QUESTIONSLIST_H
