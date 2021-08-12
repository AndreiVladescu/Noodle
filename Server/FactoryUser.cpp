#include "FactoryUser.h"
#include "Admin.h"
#include "Student.h"
#include "Profesor.h"



IUser* FactoryUser::createUserAdmin()
{
    return new Admin;
}

IUser* FactoryUser::createUserStudent()
{
    return new Student;
}

IUser* FactoryUser::createUserProfesor()
{
    return new Profesor;
}
