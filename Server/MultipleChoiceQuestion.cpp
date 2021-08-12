#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(vector<pair<string, bool>> answers, string QBody, float newPoints) :
	Question(QBody, newPoints)
{
	if (answers.size() > MAX_NUMBER_OF_ANSWERS)
		return; //get me an exception
	answerList = answers;
	this->questionType = QuestionType::MultipleChoiceQuestion;
}

MultipleChoiceQuestion::MultipleChoiceQuestion(string Qbody, float newPoints) :
	Question(Qbody, newPoints)
{
	this->questionType = QuestionType::MultipleChoiceQuestion;
}

bool MultipleChoiceQuestion::addAnswer(string answer, bool truthness)
{
	return addAnswer(make_pair(answer, truthness));
}

bool MultipleChoiceQuestion::addAnswer(pair<string, bool> answer_truthness_pair)
{
	if (answerList.size() >= MAX_NUMBER_OF_ANSWERS)
		return false;
	answerList.push_back(answer_truthness_pair);
	return true;
}
