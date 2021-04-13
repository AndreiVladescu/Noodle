#pragma once
#include "IUser.h"

class AUser :
    public IUser
{
protected:
    string lastName,
        firstName,
        email,
        joinedDate,
        pswd;
    int role;
public:
    AUser(string userData);

    virtual void printUser() {};
    virtual void changePswd() {};


    //setere
    void setUserFirstName(string) override;
    void setUserLastName(string) override;
    void setUserEmail(string) override;
    void setPassword(string) override;

    //get-ere
    string getUserFirstName() override;
    string getUserLastName() override;
    string getUserFullName() override ;
    string getUserEmail() override;
    string getUserJoinDate() override;

    virtual ~AUser();
};

