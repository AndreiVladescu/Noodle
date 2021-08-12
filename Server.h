#pragma once
#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <thread>

#include "IServer.h"
#include "SQLManager.h"
#include "Encryptor.h"
#include "Parser.h"
#include "IUser.h"
#include "FactoryUser.h"
#include "Student.h"
#include "Profesor.h"
#include "Admin.h"
#include "FunctionCode.h"
#include "TrustedTime.h"
#include "ITest.h"
#include "FactoryTest.h"
#include "Protocol.h"
#include "IQuestion.h"
#include "FactoryQuestion.h"

#define SQL_MANAGER SQLManager::getInstance()
#define ENCRYPT Encryptor::getInstance()
#define TIME TrustedTime::getInstance()

using namespace std;

class Server
{
public:
	Server(int PORT);
	bool ListenForNewConnection();

	vector<ITest*> testList = {};
	vector<IUser*> userList = {};

private:
	SOCKET Connections[100];
	thread connectionThreads[100];

	addrinfo* result;
	addrinfo hints;
	SOCKET ListenSocket;
	int iResult;
	int ConnectionCounter = 0;

	//User-level functions
	bool Authentify(int id, vector<string> vStr);
	void LoadUserInfo(int index, string uEmail);
	bool SendUserInfo(int index);
	void LoadTests();

	void ChangeUserPassword(int index, vector<string> vStr);
	void InsertNewTest(int index, vector<string> vStr);
	void InsertNewQuestion(int index, vector<string> vStr);
	void InsertNewUser(int index, vector<string> vStr);
	void InsertNewGrade(int index, vector<string> vStr);
	void SendClientHisGrades(int index);
	void SendAllOnlineClients(int index);
	void ModifyGradeOfStudent(int index, vector<string> vStr);
	void SendClientGradesPerStudyGroup(int index, vector<string> vStr);
	void SendProfessorHisSubject(int index, vector<string> vStr);
	void AssignTestToStudent(int index, vector<string> vStr);
	void AssignTestToStudyGroup(int index, vector<string> vStr);
	void SendProfessorTests(int index);
	void MakeProfessorOwnerOfSubject(int index, vector<string> vStr);
	void LogoutUser(int index);
	void SendClientTestList(int index);
	void SendAllRegisteredUsers(int index);
	void DeleteUser(int index, vector<string> vStr);
	//Deprecated
	// {
	//void SendClientAllUserData(int index, string str);
	//

	// }

	//Server-level functions
	bool GetInt(int id, int& value);
	bool SendInt(int id, int value);
	bool SendBool(int id, bool value);
	bool GetBool(int id, bool& value);
	bool SendString(int id, string& value);
	bool GetString(int id, string& value);
	//bool SpecialSendString(int id, string& value);
	bool CloseConnection(int index);

	bool ProcessString(int index, string value);
	
	static void ClientHandler(int index);
};

static Server* serverPtr;