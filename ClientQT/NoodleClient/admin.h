#ifndef ADMIN_H
#define ADMIN_H
#include "auser.h"


class Admin : public AUser
{

public:
    Admin();
    Admin(vector<string>&,string& passw);

    bool insertUser(vector <string>&);
    vector<string> askForOnlineAccounts();
    vector<string> askForAllRegisteredUsers();
    void deleteUser(string& v);


    virtual ~Admin();

};

#endif // ADMIN_H
