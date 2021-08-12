#include "factoryuser.h"
//#include "admin.h"
//#include "student.h"
//#include "profesor.h"
#include "admin.h"
#include "profesor.h"
#include "student.h"


IUser *FactoryUser::createUserAdmin(vector<string>&v,string& passw)
{
    return new Admin(v,passw);
}

IUser *FactoryUser::createUserStudent(vector<string>&v,string& passw)
{
    return new Student(v,passw);
}

IUser *FactoryUser::createUserProfesor(vector<string>&v,string& passw)
{
    return new Profesor(v,passw);
}
