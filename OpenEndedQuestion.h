#pragma once
#include "Question.h"

//This question uses an open field 
// 
//
class OpenEndedQuestion :
    public Question
{
public:
    OpenEndedQuestion(string Qanswer, string Qbody, float newPoints);
    ~OpenEndedQuestion() {}

    inline void setAnswer(string myAnswer) { answer = myAnswer; }
    inline string getAnswer() { return answer; }

private:
    string answer;

};