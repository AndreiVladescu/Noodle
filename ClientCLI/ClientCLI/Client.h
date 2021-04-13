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

using namespace std;

class Client
{
public:
	Client(int argc, char** argv, int PORT);
	bool Connect();
	inline void StartSubRoutine() { clientThread = thread(ClientHandler); }

	bool SendString(const string& value);
	//bool SendDirectMessage(const string& value);
	bool GetBool(bool& value);
	bool DM_Failed;

	static void ClientHandler();

	bool SendInt(const int& value) const;
	bool GetInt(int& value);
	bool SendBool(bool value);
	bool GetString(string& value);
	bool CloseConnection();

	int iResult;
	SOCKET ServerConnection;
	addrinfo* result = NULL;
	addrinfo* ptr = NULL;
	addrinfo hints;
	std::thread clientThread;
};

static Client* clientPtr;
