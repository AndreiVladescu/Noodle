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
    vector<pair<string, int>> studentGrades;

public:
    Student(string);
    Student();

    string getStudentTests();
    
    void seeGrades();
    void seeGradesPerSem();
    void seeTests();
    void answerTest(ITest *t);

    inline void setStudyGroup(string newStudyGroup) { studyGroup = newStudyGroup; }
    inline void setStudyYear(int newStudyYear) { studyYear = newStudyYear; }
    inline void addNewGrade(pair<string, int> newGrade) { studentGrades.push_back(newGrade); }

    inline vector<pair<string, int>> getStudentGrades() { return studentGrades; }
    inline int getStudyYear() { return studyYear; };
    inline string getStudyGroup() { return studyGroup; };

    ~Student();
};

