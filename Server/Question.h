#pragma once
#include "IQuestion.h"

class Question :
    public IQuestion
{
protected:
    string bodyQuestion;
    float points;

	QuestionType questionType;

public:
    Question(string Qbody, float newPoints);

    inline string printQuestion() override final { return bodyQuestion; }

	
    inline void setBody(string QBody) override final { bodyQuestion = QBody; }
    inline void setBody(const char* sir) override final { bodyQuestion = sir; }
    inline void setQuestionType(QuestionType type) override final { questionType = type; }
    inline void setNrOfPoints(float nrPoints) override final { points = nrPoints; }

    inline string getBody() override final { return bodyQuestion; }
	inline float getPoints() override final { return points; }
    inline QuestionType getQuestionType() override final { return questionType; }
    virtual ~Question() {}
};

