#ifndef IUSER_H
#define IUSER_H

#include <iostream>
#include <string>

using namespace std;


class IUser
{
public:
    virtual void changePsswrd(string& s) =0;
    virtual void logOut()=0;


    virtual int getUserID()=0;
    virtual string getLastName()=0;
    virtual string getFirstName()=0;
    virtual string getUserName()=0;
    virtual string getJoinDate()=0;
    virtual int getUserRole()=0;

    virtual string getPsswrd()=0;

    virtual void setUserID(int& id)=0;
    virtual void setLastName(string& s)=0;
    virtual void setFirstName(string& s)=0;
    virtual void setUserName(string& s)=0;
    virtual void setJoinDate(string& s)=0;
    virtual void setUserRole(int& r)=0;

    virtual void setPsswrd(string& p)=0;

};





#endif // IUSER_H
