#pragma once

#include <iostream>
#include <string>

using namespace std;


class IUser;

class FactoryUser
{
public:
	static IUser* createUserAdmin(string name);
	static IUser* createUserStudent(string name);
	static IUser* createUserProfesor(string name);

};

