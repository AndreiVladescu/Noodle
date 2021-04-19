#pragma once
#include "AUser.h"
#include <iostream>
#include <vector>


using namespace std;

class ITest;
class IQuestion;
class Student;

class Profesor :
    public AUser
{
private:
    vector<ITest*> Exams;
    vector<string> Materii;
public:
    Profesor(string);
    Profesor();

    void makeNewTest(string);
    void addQuestionToTest(IQuestion* quest,ITest* t);
    ITest* seeTest();
    void modifyGrade(Student* sd,int grade);
    void printMaterii();

   

    ~Profesor();
};

