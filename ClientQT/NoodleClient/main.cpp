#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "mainwindow.h"
#include "serverconnection.h"
#include <QDebug>
#include "connmanagerexception.h"
#include "parser.h"
#include "IException.h"
#include "connmanagerexception.h"

#include <QApplication>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#pragma comment(lib, "AdvApi32.lib")

using namespace std;

serverConnection* conn= new serverConnection();

int main(int argc, char *argv[])
{
    try
    {
        if(!conn->connectToServer())
        {
            throw (IException*)new ConnManagerException("Connection failed.");
        }
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
    catch (IException* e)
    {
        cout<<e->getExceptionMessage()<<endl;
        return e->getExceptionCode();
    }
    catch(...)
    {
        cout<<"Error";
        return -1;

    }


    /*
    if (!conn->connectToServer())
    {
        cout<<"Eroare conectare server\n";
        return 1;
    }
    else
    {
    //
    }
*/



}
