

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <conio.h>

#include <iostream>
#include <vector>

#include "Client.h"

Client* myClient;

#define DEFAULT_PORT 42069

using namespace std;

//enum PACKET;

void Auth()
{
	// Make client have a username
	bool usernameReceived = false;
	bool passwordReceived = false;
	bool authAccepted = false;
	do
	{
		cout << "Please provide a username" << endl;
		string str;
		getline(cin, str);
		myClient->SendString(str);

		if (!myClient->GetBool(usernameReceived)) {
			cout << "Authentication failed. Leaving..." << endl;
			exit(EXIT_FAILURE);
		}
		
		cout << "Please provide a password" << endl;

		getline(cin, str);
		myClient->SendString(str);

		if (!myClient->GetBool(passwordReceived)) {
			cout << "Authentication failed. Leaving..." << endl;
			exit(EXIT_FAILURE);
		}

		// verify authentification

		if (!myClient->GetBool(authAccepted)) {
			cout << "Password or Username incorrect." << endl;
		}
	} while (!authAccepted);
}

int main(int argc, char** argv)
{
	myClient = new Client(argc, argv, DEFAULT_PORT);

	if (!myClient->Connect())
	{
		system("pause");
		return 1;
	}

	// if the program gets past this successfully, it resumes as normal
	Auth();

	system("pause");
	system("cls");

	if (myClient->LoadUserInfo()) {
		myClient->printUserInfo();
	}

	myClient->StartSubRoutine();

	system("pause");

	//Receive and create messages
	string buffer;
	//while (true)
	//{
		//cout << "Enter option:" << endl;
		//cout << "1. Display User Info" << endl;
		//cout << "2. Insert a new User (Works for Admin only): LastName FirstName Email Password UserRole" << endl;
		//cout << "(UserRole : 1-Student, 2-Professor, 3-Admin)" << endl;
		//cout << "If student, add StudyGroup and StudyYear also" << endl;

		//char choice;
		//choice = _getch();
		////getline(cin, buffer); // get line from cmd console
		///*if (!myClient->SendString(buffer))
		//	break;*/
		//if (choice - '0' == 1) {
		//	string sendBuffer = "1";
		//	if (!myClient->SendString(sendBuffer))
		//		break;

		//	if (!myClient->GetString(buffer))
		//		break;
		//	vector<string> vectString = PARSER->unparseString(buffer, '$');

		//	for (int i = 0; i < vectString.size(); i++)
		//		cout << vectString[i] + ' ';
		//}
		//else if (choice - '0' == 2)
		//{
		//	cout << "Feature not implemented... Yet" << endl;
		//	_getch();
		//}
		
		

		//system("cls");
	//}
	
	// cleanup
	WSACleanup();

	system("pause");

	exit(EXIT_SUCCESS);
}