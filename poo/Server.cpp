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
bool Server::ProcessString(int index, string value)
{
	//It is configured in listening all strings for now
	if (!GetString(index, value))
		return false;
	cout << value << endl;
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
