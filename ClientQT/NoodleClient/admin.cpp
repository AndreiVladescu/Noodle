#include "admin.h"
#include "serverconnection.h"

Admin::Admin()
{

}

Admin::Admin(vector<string> &v, string& passw) :
    AUser(v,passw)
{

}

bool Admin::insertUser(vector<string>& v)
{
    bool check;
    serverConnection::sendMethod(v);
    serverConnection::receiveBoolFromServer(check);
    if(check)
    {
        return true;
    }
    else
    {
        return false;
    }

}

vector<string> Admin::askForOnlineAccounts()
{
    vector<string> v;
    v.push_back("9");
    serverConnection::sendMethod(v);
    return serverConnection::recvMethod();
}

vector<string> Admin::askForAllRegisteredUsers()
{
    vector<string> v;
    v.push_back("20");
    serverConnection::sendMethod(v);
    return serverConnection::recvMethod();
}

void Admin::deleteUser(string& s)
{
    vector<string> v;
    v.push_back("21");
    v.push_back(s);
    serverConnection::sendMethod(v);
}

Admin::~Admin()
{

}
