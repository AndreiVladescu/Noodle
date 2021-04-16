#pragma once
#include "AUser.h"
#include <vector>
#include <iostream>

using namespace std;

class ITest;


class Student :
    public AUser
{
protected:
    int studyYear;
    string studyGroup;

public:
    Student(string);

    string getStudentTests();
    
    void seeGrades();
    void seeGradesPerSem();
    void seeTests();
    void answerTest(ITest *t);

    int getStudyYear() {};
    string getStudyGroup() {};

    ~Student();
};

