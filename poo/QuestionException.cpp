#include "QuestionException.h"

QuestionException::QuestionException(string exceptionMessage) :
	AException("Question Exception: " + exceptionMessage, 301)
{
}

QuestionException::~QuestionException()
{
}
