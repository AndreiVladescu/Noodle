#pragma once
#include "OpenEndedQuestion.h"
#include "MultipleChoiceQuestion.h"

class FactoryQuestion
{
public:
	static MultipleChoiceQuestion* getMultipleChoiceQuestion(vector<pair<string, bool>> answers, string QBody, float newPoints);
	static MultipleChoiceQuestion* getMultipleChoiceQuestion(string QBody, float newPoints);
	static OpenEndedQuestion* getOpenEndedQuestion(string Qanswer, string Qbody, float newPoints);
};

