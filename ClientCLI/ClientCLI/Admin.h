#pragma once
#include "AUser.h"
class Admin :
    public AUser
{
public:
    Admin(string);
    Admin();

    void seeConnectedUsers();
    void registerNewUser(string);
    void deleteUser(string);

    ~Admin();
};

