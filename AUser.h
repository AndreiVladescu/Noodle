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
           password;

    int userID,
        role;

    bool connectionStatus = true;
public:
    AUser(string userData);
    AUser();

    virtual void printUser() {};
    virtual void changePswd() {};


    //setere
    void setUserFirstName(string) override;
    void setUserLastName(string) override;
    void setUserEmail(string) override;
    void setPassword(string) override;
    void setJoinedDate(string) override;
    void setRole(int) override;
    void setUserID(int) override;
    inline void setConnectionStatus() override  {connectionStatus = false; }

    void setConnectionData(string uLastName, string uFirstName, string uEmail, string uJoinedDate, int uID, int uRole) override;

    //get-ere
    string getUserFirstName() override;
    string getUserLastName() override;
    string getUserFullName() override ;
    string getUserEmail() override;
    string getUserJoinDate() override;
    int getUserRole() override;
    int getUserID() override;
    inline bool getConnectionStatus() override { return connectionStatus;}

    virtual ~AUser();
};

