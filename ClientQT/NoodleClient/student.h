#ifndef STUDENT_H
#define STUDENT_H
#include "auser.h"
#include <vector>
#include <string>


class Student : public AUser
{
protected:
    string studyGroup;
    string studyYear;
    vector<string> finishedTests;

public:
    Student();
    Student(vector<string>&v,string& passw);

    vector<string> askForGrades();



    string getStudyGroup();
    string getStudyYear();


    void setStudyGroup(string& s);
    void setStudyYear(string& s);
    vector<string> askForStatistics(vector<string>&v);
    int askForQuizes();
    void sendTestResult(vector<string>& v);
    void addFinishedTest(string s);
    vector<string> getFinishedTests();
    int getNrOfFinishedTests() { return finishedTests.size(); }
    virtual ~Student();

};

#endif // STUDENT_H
