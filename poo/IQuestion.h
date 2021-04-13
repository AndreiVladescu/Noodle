#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;


class IQuestion
{
public:
	virtual string printQuestion() = 0;

	virtual string getBody() = 0;
	virtual void setBody(string QBody) = 0;
	virtual void setBody(const char* sir) = 0;

	virtual int getNrAnswers() = 0;
	virtual void setNrAnswers(int nrAnswers) = 0;

	virtual pair<string, bool> getAnswer() = 0;
	virtual void addAnswer(pair <string, bool> Answer) = 0;

	virtual int checkQuestion(int nrQ, string Answ) = 0;
	virtual int getNrOfPoints() = 0;
	virtual void setNrOfPoints(int nrPoints) = 0;

};

