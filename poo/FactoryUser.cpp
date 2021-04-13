#include "FactoryUser.h"
#include "Admin.h"
#include "Student.h"
#include "Profesor.h"



IUser* FactoryUser::createUserAdmin(string name)
{
    return new Admin(name);
}

IUser* FactoryUser::createUserStudent(string nume)
{
    return new Student(nume);
}

IUser* FactoryUser::createUserProfesor(string nume)
{
    return new Profesor(nume);
}
