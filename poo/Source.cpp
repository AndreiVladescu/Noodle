#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <iostream>
#include <thread>

#include "Server.h"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 42069

int main(void)
{
	srand(time(NULL));

	Server server(DEFAULT_PORT);

	cout << "Server up and running." << endl;

	for (int i = 0; i < 100; i++)
	{
		server.ListenForNewConnection();
	}
	
	//cout << SQL_MANAGER->getAllUserData(10000);

	/*if (SQL_MANAGER->authentifyUser("vladescu.andrei@mta.ro", "bannerlord"))
		cout << "@@@@@@@@@@@@ Merge @@@@@@@@@@@@" << endl;
	else
		cout << "@@@@@@@@@@@@ Nu merge @@@@@@@@@@@@" << endl;*/

	/*string userString = "('Iosub','Andrei','iosub.andrei@mta.ro','parolaIosub',GETDATE(), 1, 'C112A', 2)";

	SQL_MANAGER->insertNewStudent(userString);*/

	//cout << SQL_MANAGER->getAllUserNames();

	//string myString = "Andreiaasdasdasdeqasda";


	/*string hashedPassword = PswdHash::getInstance()->getPasswordHash(myString, 5);
	cout << PswdHash::getInstance()->getPasswordHash(myString, PswdHash::getInstance()->extractSeed(hashedPassword)) << endl;
	cout << hashedPassword;*/
	/*cout << PswdHash::getInstance()->getPasswordHash(myString) << endl;
	cout << PswdHash::getInstance()->getPasswordHash(myString) << endl;
	cout << PswdHash::getInstance()->getPasswordHash(myString) << endl;*/

	//vector<string> vect = {"my","command" };

	//Parser::getInstance()->protocoliseString(1, vect);
	//cout << Parser::getInstance()->parseString(Parser::getInstance()->protocoliseString(1, vect), '$') << endl;

	system("pause"); // halt exit

	return 0;
}