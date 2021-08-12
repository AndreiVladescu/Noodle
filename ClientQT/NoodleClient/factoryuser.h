#ifndef FACTORYUSER_H
#define FACTORYUSER_H
#include <string>
#include <vector>

using namespace std;

class IUser;

class FactoryUser
{
public:

    static IUser* createUserAdmin(vector<string>&v,string& passw);
    static IUser* createUserStudent(vector<string>&v,string& passw);
    static IUser* createUserProfesor(vector<string>&v,string& passw);

};

#endif // FACTORYUSER_H
