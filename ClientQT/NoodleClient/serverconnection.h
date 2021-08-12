#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include<stdlib.h>
#include <stdio.h>

#include<iostream>
#include<string>
#include <vector>

using namespace std;

#define DEFAULT_PORT "42069"
#define DEFAULT_IP "86.126.120.149"
//#define DEFAULT_IP "127.0.0.1"

#define ENCRYPT Encryptor::getInstance()

class serverConnection
{
private:
    int m_iResult; // result of Socket


    struct addrinfo* m_result = NULL;
    struct addrinfo* m_ptr = NULL;
    struct addrinfo m_hints;

    static SOCKET m_ServerConnection; //conn
    static string m_StringReveived;
    static string m_StringToSend;

public:
    serverConnection();
    bool connectToServer();
    bool closeConnection();

    static void sendMethod(vector<string>&v);
    static vector<string> recvMethod();


    static void sendStringToServer(string& value);
    static void receiveStringFromServer(string& value);
    static void sendIntToServer(int& value);
    static void receiveIntFromServer(int& value);
    static void sendBoolToServer(bool& value);
    static void receiveBoolFromServer(bool& value);


};

#endif // SERVERCONNECTION_H
