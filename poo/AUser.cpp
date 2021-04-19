#include "AUser.h"

AUser::AUser(string userData)
{
	//Todo Constructor
}

AUser::AUser()
{
}

void AUser::setUserFirstName(string name)
{
	firstName = name;
}

void AUser::setUserLastName(string name)
{
	lastName = name;
}

void AUser::setUserEmail(string mail)
{
	email = mail;
}

void AUser::setPassword(string newPassword)///////Make use of the SQL Manager & PswdHash
{
	password = newPassword;
}

void AUser::setJoinedDate(string newJoinedDate)
{
	joinedDate = newJoinedDate;
}

void AUser::setRole(int newRole)
{
	role = newRole;
}

void AUser::setUserID(int newID)
{
	userID = newID;
}

void AUser::setConnectionData(string uLastName, string uFirstName, string uEmail, string uJoinedDate, int uID, int uRole)
{
	setUserFirstName(uFirstName);
	setUserLastName(uLastName);
	setUserEmail(uEmail);
	setJoinedDate(uJoinedDate);
	setUserID(uID);
	setRole(uRole);
}

string AUser::getUserFirstName()
{
	return firstName;
}

string AUser::getUserLastName()
{
	return lastName;
}

string AUser::getUserFullName()
{
	return firstName + lastName;
}

string AUser::getUserEmail()
{
	return email;
}

string AUser::getUserJoinDate()
{
	return joinedDate;
}

int AUser::getUserRole()
{
	return role;
}

int AUser::getUserID()
{
	return userID;
}

AUser::~AUser()
{
	lastName.erase();
	firstName.erase();
	email.erase();
}

