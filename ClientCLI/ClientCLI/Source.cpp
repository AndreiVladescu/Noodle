#include "Client.h"




// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

Client* myClient;

#define DEFAULT_PORT 42069

using namespace std;

//enum PACKET;

void Auth()
{
	// Make client have a username
	bool authAccepted = false;
	do
	{
		cout << "Please provide a username" << endl;
		string str;
		getline(cin, str);
		myClient->SendString(str);

		myClient->GetBool(authAccepted);

		cout << "Please provide a password" << endl;

		getline(cin, str);
		myClient->SendString(str);

		myClient->GetBool(authAccepted);

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

	myClient->StartSubRoutine();

	//Receive and create messages
	string buffer;
	while (true)
	{
		getline(cin, buffer); // get line from cmd console
		if (!myClient->SendString(buffer))
			break;
	}

	// cleanup
	system("pause");

	WSACleanup();

	system("pause");

	return 0;
}