#pragma once
#include "AUser.h"
class Admin :
    public AUser
{
public:
    Admin(string);


    void seeConnectedUsers();
    void registerNewUser(string);
    void deleteUser(string);

    ~Admin();
};

