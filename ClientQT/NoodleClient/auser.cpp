#include "auser.h"
#include "serverconnection.h"
#include "parser.h"

AUser::AUser()
{

}

AUser::AUser(vector<string>&v,string& passWord)
{
    setPsswrd(passWord);

    int id=atoi(v[1].c_str());
    setUserID(id);
    setLastName(v[2]);
    setFirstName(v[3]);
    setUserName(v[4]);
    setJoinDate(v[5]);
    int role = atoi(v[6].c_str());
    setUserRole(role);

}

AUser::~AUser()
{

}

void AUser::changePsswrd(string& s)
{
    vector<string> vectorToSend;
    //
    vectorToSend.push_back("5");
    vectorToSend.push_back(s);
    //
    serverConnection::sendMethod(vectorToSend);
    setPsswrd(s);
}

void AUser::logOut()
{
    vector<string> vectorToSend;
    vectorToSend.push_back("19");
    serverConnection::sendMethod(vectorToSend);
}

string AUser::getUserName()
{
    return this->userName;
}

string AUser::getJoinDate()
{
    return this->joinDate;
}

string AUser::getPsswrd()
{
    return this->passWord;
}

int AUser::getUserID()
{
    return this->userID;
}

string AUser::getLastName()
{
    return this->lastName;
}

string AUser::getFirstName()
{
    return this->firstName;
}

int AUser::getUserRole()
{
    return this->role;
}

void AUser::setUserName(string& s)
{
    this->userName=s;
}

void AUser::setJoinDate(string& s)
{
    this->joinDate=s;
}

void AUser::setPsswrd(string& p)
{
    this->passWord=p;
}

void AUser::setUserID(int& id)
{
    this->userID=id;
}

void AUser::setLastName(string& s)
{
    this->lastName=s;
}

void AUser::setFirstName(string& s)
{
    this->firstName=s;
}

void AUser::setUserRole(int& r)
{
    this->role=r;
}

