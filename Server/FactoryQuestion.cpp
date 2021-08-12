#include "FactoryQuestion.h"

MultipleChoiceQuestion* FactoryQuestion::getMultipleChoiceQuestion(vector<pair<string, bool>> answers, string QBody, float newPoints)
{
	return new MultipleChoiceQuestion(answers, QBody, newPoints);
}

MultipleChoiceQuestion* FactoryQuestion::getMultipleChoiceQuestion(string QBody, float newPoints)
{
	return new MultipleChoiceQuestion(QBody, newPoints);
}

OpenEndedQuestion* FactoryQuestion::getOpenEndedQuestion(string Qanswer, string Qbody, float newPoints)
{
	return new OpenEndedQuestion(Qanswer, Qbody, newPoints);
}
