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
    vector<ITest*> tests;
    string subject;
public:
    Profesor(string);
    Profesor();

    /*vector <IQuestion*> questions;
    vector <IUser*> students;
    IUser* ProfessorOwner;
    float maxPoints;
    float suppPoints;
    string name;
    string time;*/
    void makeNewTest(string);
    void addQuestionToTest(IQuestion* quest,ITest* t);
    vector<ITest*> getTests();
    inline void setSubject(string newSubject) { subject = newSubject; }
    inline string getSubject() { return subject; }
    /*void modifyGrade(Student* sd,int grade);*/
    void printSubject();

   

    ~Profesor();
};

