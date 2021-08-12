#include "profesor.h"
#include "serverconnection.h"

Profesor::Profesor()
{

}

Profesor::Profesor(vector<string>& v, string& passw) :
    AUser(v,passw)
{
    setSubject(v[7]);
}

void Profesor::setSubject(string &s)
{
    this->subject=s;
}

string Profesor::getSubject()
{
    return this->subject;
}

void Profesor::sendTest(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("2");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);

}

void Profesor::sendQuestion(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("6");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);
}

void Profesor::sendSubject(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("18");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);
}

vector<string> Profesor::askForStudentGrades(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("13");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);
    return serverConnection::recvMethod();
}

void Profesor::changeGradeOfAStudent(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("10");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);
}

vector<vector<string>> Profesor::seeTests()
{
    vector<string> v2;
    v2.push_back("16");
    serverConnection::sendMethod(v2);
    v2.clear();
    v2=serverConnection::recvMethod();
    vector<vector<string>> mat;

    int nrT=atoi(v2[1].c_str());
    v2.clear();
    for(int i=0;i<nrT;i++)
    {
        v2=serverConnection::recvMethod();
        mat.push_back(v2);
    }

    return mat;
}

void Profesor::assignTestToGroup(vector<string> &v)
{
    vector<string> v2;
    v2.push_back("15");
    for(int i=0;i<v.size();i++)
        v2.push_back(v[i]);
    serverConnection::sendMethod(v2);
}

Profesor::~Profesor()
{

}
