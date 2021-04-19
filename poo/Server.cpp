#include "Server.h"

Server::Server(int PORT)
{
	WSADATA wsaData;

	ListenSocket = INVALID_SOCKET;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		exit(0);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, std::to_string(PORT).c_str(), &hints, &result);
	if (iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		exit(0);
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		exit(0);
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Bind failed with error: " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}

	freeaddrinfo(result);

	//listen for incoming connection
	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}

	serverPtr = this;
}

bool Server::ListenForNewConnection()
{
	SOCKET ClientSocket = INVALID_SOCKET;
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET)
	{
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return false;
	}

	else // sucessfull connection
	{
		std::cout << "Client connected" << std::endl;
		Connections[ConnectionCounter] = ClientSocket;

		// authentify user
		// + loads into memory and sends the client user data
		if (!Authentify(ConnectionCounter)) {
			return false;
		}

		connectionThreads[ConnectionCounter] = thread(ClientHandler, ConnectionCounter);

		ConnectionCounter++;
		return true;
	}
}

bool Server::SendInt(int id, int value)
{
	int returnCheck = send(Connections[id], (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetInt(int id, int& value)
{
	int returnCheck = recv(Connections[id], (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::SendBool(int id, bool value)
{
	int returnCheck = send(Connections[id], (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetBool(int id, bool& value)
{
	int returnCheck = recv(Connections[id], (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::SendString(int id,string& value)
{
	int bufferLength = value.size();
	if (!SendInt(id, bufferLength))
		return false;

	ENCRYPT->encrypt(value);

	int returnCheck = send(Connections[id], value.c_str(), bufferLength, NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetString(int id, string& value)
{
	int bufferLength = 0;
	if (!GetInt(id, bufferLength))
		return false;

	char* buffer = new char[bufferLength + 1]; // +1 tro allow for terminating '/0'

	int returnCheck = recv(Connections[id], buffer, bufferLength, NULL);
	buffer[bufferLength] = '\0';
	value = buffer;
	delete[] buffer;

	if (returnCheck == SOCKET_ERROR)
		return false;

	ENCRYPT->decrypt(value);

	return true;
}

//This function is responsible for all the processing
//Make a protocol
//E.g. 1$data$in$parsed$mode
// 1-> function name, i.e. give me my student grades
// the next data parsed by the delimiter "$" is the one which is to be processed by the respective function
// getStudentGrade(...), the params are the data to be given by the unparsed packet
// 1$UserID$SubjectID
// getStudentGrade(int userID, int SubjectID) => returns grade for the user with userID 
// at subject with subjectID

bool Server::ProcessString(int index, string value)
{
	//It is configured in listening all strings for now
	/*if (!GetString(index, value))
		return false;
	cout << value << endl;
	return true;*/


	/*if (!GetString(index, value))
		return false;

	vector<string> unparsedString = PARSER->unparseString(value, '$');

	FunctionCalls functionCall = (FunctionCalls)atoi(unparsedString[0].c_str());
	string sendString;
	vector<string> sendVectString;

	switch (functionCall) {
		case(FunctionCalls::GetAllUserData):
		{
			sendVectString.push_back(this->userList[index]->getUserFullName());
			PARSER->protocoliseString(1, sendVectString);
			sendString = PARSER->parseString(sendVectString, '$');

			if (!SendString(index, sendString))
				return false;

			break;
		}

	}*/

	return true;
}

void Server::LoadUserInfo(int index, string uEmail)
{
	//tempUser->setUserEmail(uEmail);
	int uID = SQL_MANAGER->getUserID(uEmail);
	int uRole = SQL_MANAGER->getUserRole(uEmail);

	IUser* tempUser;

	//differentiating between Users
	switch (uRole){
		case 1: { // Student
			tempUser = FactoryUser::createUserStudent();
			break;
		}
		case 2: {// Professor
			tempUser = FactoryUser::createUserProfesor();
			break;
		}
		case 3: {// Admin
			tempUser = FactoryUser::createUserAdmin();
			break;
		}
		default:
			tempUser = FactoryUser::createUserStudent(); //if i write no default case at all the compiler screams
	}

	//using setters
	tempUser->setConnectionData(SQL_MANAGER->getUserLastName(uID),
		SQL_MANAGER->getUserFirstName(uID),
		uEmail,
		SQL_MANAGER->getUserJoinedDate(uID),
		uID,
		uRole);

	//dynamic casts for Student class
	dynamic_cast<Student*>(tempUser)->setStudyGroup(SQL_MANAGER->getUserStudyGroup(uID));
	dynamic_cast<Student*>(tempUser)->setStudyYear(SQL_MANAGER->getUserStudyYear(uID));

	userList.push_back(tempUser);
}

//Sending the user it's vital info at connection time, so it can be displayed/manipulated faster
bool Server::SendUserInfo(int index)
{
	vector<string> sendMessageVector = {
		to_string(userList[index]->getUserID()),
		userList[index]->getUserLastName(),
		userList[index]->getUserFirstName(),
		userList[index]->getUserEmail(),
		userList[index]->getUserJoinDate(),
		to_string(userList[index]->getUserRole())
	};
	
	//For Student, you get 2 more fields : studyGroup, studyYear
	if (userList[index]->getUserRole() == 1) {
		sendMessageVector.push_back(dynamic_cast<Student*>(userList[index])->getStudyGroup());
		sendMessageVector.push_back(to_string(dynamic_cast<Student*>(userList[index])->getStudyYear()));
	}

	string parsedString = PARSER->parseString(PARSER->protocoliseString((int)FunctionCode::SendClientAllUserData, sendMessageVector), '$');

	if (!SendString(index, parsedString)) {
		cout << "Sending user " + to_string(index) + " data failed." << endl;
		return false;
	}

	return true;
}

bool Server::CloseConnection(int index)
{
	if (closesocket(Connections[index]) == SOCKET_ERROR)
	{
		cout << "Failed closing Error: " << WSAGetLastError() << endl;
		return false;
	}

	return true;
}

bool Server::Authentify(int index)
{
	string usernameString;
	string userpassString;
	do
	{
		if (!GetString(index, usernameString))
		{
			SendBool(index, false);
			return false;
		}
		SendBool(index, true); //Handshake

		if (!GetString(index, userpassString))
		{
			SendBool(index, false);
			return false;
		}
		SendBool(index, true);

		if (!SQL_MANAGER->authentifyUser(usernameString, userpassString))
			SendBool(index, false);
		else {
			SendBool(index, true);
			break;
		}
	} while (true);

	cout << "Connection succesful" << endl;

	//Loads into memory
	LoadUserInfo(ConnectionCounter, usernameString);
	SendUserInfo(ConnectionCounter);
}

	//serverPtr->usernames.push_back("");
	//PACKET packetType;

	////Get Username
	/*bool usernameSaved = true;
	do
	{*/
	//	usernameSaved = true;
	//	/*if (!serverPtr->GetPacketType(index, packetType))
	//	{
	//		cout << "Could not get username" << endl;
	//		break;
	//	}

	//	if (!packetType == P_ChatMessage)
	//	{
	//		cout << "Getting username is not a message Package" << endl;
	//		break;
	//	}*/

	//	string userName;
	//	serverPtr->GetString(index, userName);
	//	for (auto var : serverPtr->usernames)
	//	{
	//		if (var == userName)
	//		{
	//			usernameSaved = false;
	//			break;
	//		}
	//	}
	//	if (usernameSaved)
	//	{
	//		serverPtr->usernames[index] = userName;
	//		cout << "Username " << userName << " stored at " << index << endl;
	//	}
	//	serverPtr->SendBool(index, usernameSaved);

	//} while (!usernameSaved);

	//SQLManager::getInstance()->authentifyUser();

//Bulk of work
void Server::ClientHandler(int index)
{
	string receiveString;
	while (true)
	{
		//Receive Messages
		//if (!serverPtr->GetPacketType(index, packetType))
			//break;

		if (!serverPtr->ProcessString(index, receiveString))
			break;

		//cout << receiveString << endl;
	}

	cout << "Lost contact with client: id = " << index << endl;
	serverPtr->CloseConnection(index);
}
