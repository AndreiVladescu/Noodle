#pragma once

#include <iostream>
#include <string>

using namespace std;


class IUser;

class FactoryUser
{
public:
	static IUser* createUserAdmin();
	static IUser* createUserStudent();
	static IUser* createUserProfesor();

};

