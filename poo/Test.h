#pragma once
#include "ITest.h"


class IQuestion;
class IUser;

class Test :
    public ITest
{
private:
    vector <IQuestion*> questions;
    vector <IUser*> toStudents;
    IUser* ProfessorOwner;
    int maxPoints;
    int suppPoint;

public:
    Test() {};
    virtual void printTest() {};
    virtual IQuestion* getQuestion() { return nullptr; };
    virtual void addQuestion(IQuestion* q) {};
    virtual void calculateMaxPoints() {};
    virtual void setSuppPoint(int x) {};
    virtual int getSuppPoint() { return 0; };
    virtual int getMaxPoints() { return 0; };
    virtual void checkTest(string bufferClient) { };

    virtual ~Test() {};



};

