#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

enum class QuestionType
{
	MultipleChoiceQuestion = 1,
	OpenEndedQuestion = 2
};

class IQuestion
{
public:
	virtual string printQuestion() = 0;

	virtual string getBody() = 0;
	virtual void setBody(string QBody) = 0;
	virtual void setBody(const char* sir) = 0;
	virtual void setQuestionType(QuestionType type) = 0;

	virtual float getPoints() = 0;
	virtual void setNrOfPoints(float nrPoints) = 0;
	virtual QuestionType getQuestionType() = 0;

};

