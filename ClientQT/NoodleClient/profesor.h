#ifndef PROFESOR_H
#define PROFESOR_H
#include "auser.h"


class Profesor : public AUser
{
protected:
    string subject;
public:
    Profesor();
    Profesor(vector<string>&,string& passw);

    void setSubject(string& s);
    string getSubject();
    void sendTest(vector<string>&v);
    void sendQuestion(vector<string>&v);
    void sendSubject(vector<string>&v);
    vector<string> askForStudentGrades(vector<string>&v);
    void changeGradeOfAStudent(vector<string>&v);
    vector<vector<string>> seeTests();
    void assignTestToGroup(vector<string>& v);

    virtual ~Profesor();

};

#endif // PROFESOR_H
