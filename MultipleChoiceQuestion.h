#pragma once
#include "Question.h"

#define MAX_NUMBER_OF_ANSWERS 4

//This question uses multiple choices
//
class MultipleChoiceQuestion :
    public Question
{
public:
    MultipleChoiceQuestion(vector <pair<string, bool>> answers, string Qbody, float newPoints);
    MultipleChoiceQuestion(string Qbody, float newPoints);
    ~MultipleChoiceQuestion() {}

    bool addAnswer(string answer, bool truthness);
    bool addAnswer (pair<string, bool> answer_truthness_pair);
    inline vector <pair<string, bool>> getAllAnswers() { return answerList; };
private:
    vector <pair<string, bool>> answerList;
};

