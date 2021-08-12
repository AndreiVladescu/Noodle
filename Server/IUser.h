#pragma once
#include <iostream>

using namespace std;
class IUser
{
public:

	virtual void printUser() = 0;
	virtual void changePswd() = 0;

	//set-ere
	virtual void setUserFirstName(string) = 0;
	virtual void setUserLastName(string) = 0;
	virtual void setUserEmail(string) = 0;
	virtual void setPassword(string) = 0;
	virtual void setJoinedDate(string) = 0;
	virtual void setRole(int) = 0;
	virtual void setUserID(int) = 0;
	virtual void setConnectionData(string uLastName, string uFirstName, string uEmail, string uJoinedDate, int uID, int uRole) = 0;
	virtual void setConnectionStatus() = 0;

	//get-ere
	virtual	string getUserFirstName() = 0;
	virtual string getUserLastName() = 0;
	virtual string getUserFullName() = 0;
	virtual string getUserEmail() = 0;
	virtual string getUserJoinDate() = 0;
	virtual int getUserRole() = 0;
	virtual int getUserID() = 0;
	virtual bool getConnectionStatus() = 0;
};