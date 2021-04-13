#include "FactoryQuestion.h"
#include "Question.h"

IQuestion* FactoryQuestion::CreateNewQuestion()
{
    return new Question;
}
