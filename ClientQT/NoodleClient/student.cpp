#include "student.h"
#include "serverconnection.h"

Student::Student()
{

}

Student::Student(vector<string> &v, string& passw) :
    AUser(v,passw)
{
    setStudyGroup(v[7]);
    setStudyYear(v[8]);
}

vector<string> Student::askForGrades()
{
    vector<string> v;
    v.push_back("8");
    serverConnection::sendMethod(v);
    return serverConnection::recvMethod();
}

string Student::getStudyGroup()
{
    return this->studyGroup;
}

string Student::getStudyYear()
{
    return this->studyYear;
}

void Student::setStudyGroup(string &s)
{
    this->studyGroup=s;
}

void Student::setStudyYear(string &s)
{
    this->studyYear=s;
}

vector<string> Student::askForStatistics(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("13");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);
    return serverConnection::recvMethod();
}

int Student::askForQuizes()
{
    vector<string> v2;
    v2.push_back("4");
    serverConnection::sendMethod(v2);
    v2.clear();
    v2=serverConnection::recvMethod();
    return atoi(v2[1].c_str());

}

void Student::sendTestResult(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("7");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);
}

void Student::addFinishedTest(string s)
{
    this->finishedTests.push_back(s);
}

vector<string> Student::getFinishedTests()
{
    return finishedTests;

}

Student::~Student()
{

}
