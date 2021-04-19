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
    Student();

    string getStudentTests();
    
    void seeGrades();
    void seeGradesPerSem();
    void seeTests();
    void answerTest(ITest *t);

    void setStudyGroup(string newStudyGroup);
    void setStudyYear(int newStudyYear);

    inline int getStudyYear() { return studyYear; };
    inline string getStudyGroup() { return studyGroup; };

    ~Student();
};

