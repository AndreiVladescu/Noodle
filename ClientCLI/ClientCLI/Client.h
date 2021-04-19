#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <thread>

#include "Encryptor.h"
#include "Parser.h"
#include "IUser.h"
#include "FactoryUser.h"
#include "Student.h"
#include "Admin.h"
#include "Profesor.h"

using namespace std;

#define DEFAULT_IP "127.0.0.1"
#define ENCRYPT Encryptor::getInstance()
#define PARSER Parser::getInstance()

class Client
{
private:
	int iResult; // result of Socket
	SOCKET ServerConnection; //conn
	addrinfo* result = NULL;
	addrinfo* ptr = NULL;
	addrinfo hints;
	thread clientThread; //threads

	IUser* user;
public:
	Client(int argc, char** argv, int PORT);
	

	//user functions
	bool LoadUserInfo();
	void printUserInfo();
	//client-side functions
	bool Connect();

	static void ClientHandler();
	inline void StartSubRoutine() { clientThread = thread(ClientHandler); }

	bool SendString(string& value);
	bool GetBool(bool& value);
	bool SendInt(const int& value) const;
	bool GetInt(int& value);
	bool SendBool(bool value);
	bool GetString(string& value);
	bool CloseConnection();


};

static Client* clientPtr;
