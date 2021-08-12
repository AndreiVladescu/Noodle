#include "createtestquestions.h"
#include "ui_createtestquestions.h"
#include <QMessageBox>
#include "profesor.h"

createTestQuestions::createTestQuestions(QWidget *parent,int counter,IUser* u) :
    QDialog(parent),
    ui(new Ui::createTestQuestions), counter(counter), user(u)
{
    ui->setupUi(this);

    setWindowTitle("Configure questions");

    ui->NumbeOfAnswersLabel->hide();
    ui->numberOfAnswersComboBox->hide();
    ui->shortAnswerLabel->hide();
    ui->shortAnswerLineEdit->hide();
    hideAllCheckBox();


}

createTestQuestions::~createTestQuestions()
{
    delete ui;
}

void createTestQuestions::on_singeAnswerRadioButton_clicked()
{
    //
    ui->shortAnswerLabel->show();
    ui->shortAnswerLineEdit->show();
    //
    ui->NumbeOfAnswersLabel->hide();
    ui->numberOfAnswersComboBox->hide();
    hideAllCheckBox();


}

void createTestQuestions::on_multipleAnswerRadioButton_clicked()
{
    //
    ui->shortAnswerLabel->hide();
    ui->shortAnswerLineEdit->hide();
    //
    ui->NumbeOfAnswersLabel->show();
    ui->numberOfAnswersComboBox->show();


}

void createTestQuestions::on_numberOfAnswersComboBox_currentTextChanged(const QString &arg1)
{
    int nrOfAnswers= atoi(arg1.toStdString().c_str());
    switch(nrOfAnswers)
    {
    case 2:
    {
        ui->answer1->show();
        ui->checkBox1->show();
        ui->answer2->show();
        ui->checkBox2->show();
        //
        ui->answer3->hide();
        ui->answer3->clear();
        ui->checkBox3->hide();
        ui->checkBox3->setCheckState(Qt::Unchecked);
        //
        ui->answer4->hide();
        ui->answer4->clear();
        ui->checkBox4->hide();
        ui->checkBox4->setCheckState(Qt::Unchecked);

        break;
    }
    case 3:
    {
        ui->answer1->show();
        ui->checkBox1->show();
        ui->answer2->show();
        ui->checkBox2->show();
        ui->answer3->show();
        ui->checkBox3->show();
        //
        ui->answer4->hide();
        ui->answer4->clear();
        ui->checkBox4->hide();
        ui->checkBox4->setCheckState(Qt::Unchecked);

        break;
    }
    case 4:
    {
        ui->answer1->show();
        ui->checkBox1->show();
        ui->answer2->show();
        ui->checkBox2->show();
        ui->answer3->show();
        ui->checkBox3->show();
        ui->answer4->show();
        ui->checkBox4->show();
        break;
    }
    }
}

void createTestQuestions::resetUI()
{
    //
    ui->questionBodyLineEdit->clear();
    //
    ui->singeAnswerRadioButton->setAutoExclusive(false);
    ui->singeAnswerRadioButton->setChecked(false);
    ui->singeAnswerRadioButton->setAutoExclusive(true);
    //
    ui->multipleAnswerRadioButton->setAutoExclusive(false);
    ui->multipleAnswerRadioButton->setChecked(false);
    ui->multipleAnswerRadioButton->setAutoExclusive(true);
    //
    ui->NumbeOfAnswersLabel->hide();
    ui->numberOfAnswersComboBox->hide();
    //
    ui->shortAnswerLabel->hide();
    ui->shortAnswerLineEdit->hide();
    ui->shortAnswerLineEdit->clear();
    //
    clearAllCheckBox();
    hideAllCheckBox();
    //
    ui->nrOfPointsLineEdit->clear();

}

void createTestQuestions::hideAllCheckBox()
{
    ui->answer1->hide();
    ui->answer2->hide();
    ui->answer3->hide();
    ui->answer4->hide();
    ui->checkBox1->hide();
    ui->checkBox2->hide();
    ui->checkBox3->hide();
    ui->checkBox4->hide();
}

void createTestQuestions::clearAllCheckBox()
{
    ui->answer1->clear();
    ui->answer2->clear();
    ui->answer3->clear();
    ui->answer4->clear();
    ui->checkBox1->setCheckState(Qt::Unchecked);
    ui->checkBox2->setCheckState(Qt::Unchecked);
    ui->checkBox3->setCheckState(Qt::Unchecked);
    ui->checkBox4->setCheckState(Qt::Unchecked);

}

bool createTestQuestions::sendQuestion()
{
    if(ui->questionBodyLineEdit->text()==""
            || ui->nrOfPointsLineEdit->text()==""
            || (!ui->singeAnswerRadioButton->isChecked() && !ui->multipleAnswerRadioButton->isChecked()))
    {
        QMessageBox::warning(this,"Error","All fields must be completed!");
        return false;
    }
    else
    {
        if(ui->singeAnswerRadioButton->isChecked())
        {
            if(ui->shortAnswerLineEdit->text()=="")
            {
                QMessageBox::warning(this,"Error","All fields must be completed!");
                return false;
            }
            else
            {
                vector<string> v;
                v.push_back("2");
                v.push_back(ui->questionBodyLineEdit->text().toStdString());
                v.push_back(ui->nrOfPointsLineEdit->text().toStdString());
                v.push_back(ui->shortAnswerLineEdit->text().toStdString());
                dynamic_cast<Profesor*>(user)->sendQuestion(v);
                return true;
            }
        }
        else
        {
            if(ui->multipleAnswerRadioButton->isChecked())
            {
                switch(atoi(ui->numberOfAnswersComboBox->currentText().toStdString().c_str()))
                {
                case 2:
                {
                    if(ui->answer1->text()=="" || ui->answer2->text()=="")
                    {
                        QMessageBox::warning(this,"Error","All answer fields must be completed!");
                        return false;
                    }
                    else
                    {
                        vector<string> v;
                        v.push_back("1");
                        v.push_back(ui->questionBodyLineEdit->text().toStdString());
                        v.push_back(ui->nrOfPointsLineEdit->text().toStdString());

                        v.push_back(ui->numberOfAnswersComboBox->currentText().toStdString());

                        v.push_back(ui->answer1->text().toStdString());
                        if(ui->checkBox1->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        v.push_back(ui->answer2->text().toStdString());
                        if(ui->checkBox2->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        dynamic_cast<Profesor*>(user)->sendQuestion(v);
                        return true;
                    }
                    break;
                }
                case 3:
                {
                    if(ui->answer1->text()==""
                            || ui->answer2->text()==""
                            || ui->answer3->text()=="")
                    {
                        QMessageBox::warning(this,"Error","All answer fields must be completed!");
                        return false;
                    }
                    else
                    {
                        vector<string> v;
                        v.push_back("1");
                        v.push_back(ui->questionBodyLineEdit->text().toStdString());
                        v.push_back(ui->nrOfPointsLineEdit->text().toStdString());

                        v.push_back(ui->numberOfAnswersComboBox->currentText().toStdString());

                        v.push_back(ui->answer1->text().toStdString());
                        if(ui->checkBox1->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        v.push_back(ui->answer2->text().toStdString());
                        if(ui->checkBox2->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        v.push_back(ui->answer3->text().toStdString());
                        if(ui->checkBox3->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        dynamic_cast<Profesor*>(user)->sendQuestion(v);
                        return true;
                    }
                    break;
                }
                case 4:
                {
                    if(ui->answer1->text()==""
                            || ui->answer2->text()==""
                            || ui->answer3->text()==""
                            || ui->answer4->text()=="")
                    {
                        QMessageBox::warning(this,"Error","All answer fields must be completed!");
                        return false;
                    }
                    else
                    {
                        vector<string> v;
                        v.push_back("1");
                        v.push_back(ui->questionBodyLineEdit->text().toStdString());
                        v.push_back(ui->nrOfPointsLineEdit->text().toStdString());

                        v.push_back(ui->numberOfAnswersComboBox->currentText().toStdString());

                        v.push_back(ui->answer1->text().toStdString());
                        if(ui->checkBox1->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        v.push_back(ui->answer2->text().toStdString());
                        if(ui->checkBox2->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        v.push_back(ui->answer3->text().toStdString());
                        if(ui->checkBox3->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        v.push_back(ui->answer4->text().toStdString());
                        if(ui->checkBox4->isChecked())
                            v.push_back("1");
                        else
                            v.push_back("0");

                        dynamic_cast<Profesor*>(user)->sendQuestion(v);
                        return true;
                    }
                    break;
                }
                }
            }
        }
        //dupa ce am trimis counter--;
    }
}

void createTestQuestions::on_nextQuestion_clicked()
{
    if(sendQuestion())
    {
        counter--;
        if(counter==0)
        {
            close();
        }
        else
        {

            resetUI();
            ;
        }
    }
    //trimit question la vladut

}
