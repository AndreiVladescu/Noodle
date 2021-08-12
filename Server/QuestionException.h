#pragma once
#include "AException.h"
#include "Question.h"
class QuestionException :
    public AException
{
public:
    QuestionException(string exceptionMessage);
    ~QuestionException();
};
