#include "AUser.h"

AUser::AUser(string userData)
{
	//Todo Constructor
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

void AUser::setPassword(string)///////Make use of the SQL Manager & PswdHash
{

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

AUser::~AUser()
{
	lastName.erase();
	firstName.erase();
	email.erase();
}

