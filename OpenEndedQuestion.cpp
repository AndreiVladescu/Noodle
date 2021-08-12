#include "OpenEndedQuestion.h"

OpenEndedQuestion::OpenEndedQuestion(string Qanswer, string Qbody, float newPoints) :
	Question(Qbody, newPoints)
{
	questionType = QuestionType::OpenEndedQuestion;
	answer = Qanswer;
}
