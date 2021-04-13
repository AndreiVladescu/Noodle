#pragma once
#include <iostream>

using namespace std;
class IUser
{
public:

	virtual void printUser() = 0;
	virtual void changePswd() = 0;


	virtual void setUserFirstName(string) = 0;
	virtual void setUserLastName(string) = 0;
	virtual void setUserEmail(string) = 0;
	virtual void setPassword(string) = 0;

	virtual	string getUserFirstName() = 0;
	virtual string getUserLastName() = 0;
	virtual string getUserFullName() = 0;
	virtual string getUserEmail() = 0;
	virtual string getUserJoinDate() = 0;
};