#ifndef AUSER_H
#define AUSER_H
#include "IUser.h"

#include <vector>

class AUser : public IUser
{
protected:
    int userID;
    string lastName;
    string firstName;
    string userName;
    string joinDate;
    int role;

    string passWord;



public:

    AUser();
    AUser(vector<string>&,string& passWord);

    virtual ~AUser();


    virtual void changePsswrd(string& s);
    virtual void logOut();

    virtual int getUserID();
    virtual string getLastName();
    virtual string getFirstName();
    virtual string getUserName();
    virtual string getJoinDate();
    virtual int getUserRole();

    virtual string getPsswrd();


    virtual void setUserID(int& id);
    virtual void setLastName(string& s);
    virtual void setFirstName(string& s);
    virtual void setUserName(string& s);
    virtual void setJoinDate(string& s);
    virtual void setUserRole(int& r);

    virtual void setPsswrd(string& p);



};

#endif // AUSER_H
