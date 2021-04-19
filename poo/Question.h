#pragma once
#include "IQuestion.h"
class Question :
    public IQuestion
{
private:
    string bodyQuestion;
    int points;

    int nrAnswers;
    map < string, bool > listaRaspunsuri;
    int nrCorrectAnswers;

public:
    Question() {};
    virtual ~Question() {};

	virtual string printQuestion() { return " "; };

	virtual string getBody() { return " "; };
	virtual void setBody(string QBody) { };
	virtual void setBody(const char* sir) { };

	virtual int getNrAnswers()  { return 0; };
	virtual void setNrAnswers(int nrAnswers) { };

	virtual pair<string, bool> getAnswer() { string x = "da";  return pair<string,bool>(x, true); };
	virtual void addAnswer(pair <string, bool> Answer) { };

	virtual int checkQuestion(int nrQ, string Answ) { return 0; };

	virtual int getNrOfPoints() { return 0; };
	virtual void setNrOfPoints(int nrPoints) { };



};

