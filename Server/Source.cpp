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

//Port to connect to from client
//Needs port forwarding from router
#define DEFAULT_PORT 42069 
#define DEFAULT_BUFLEN 512
#define MAX_CLIENTS 100

int main(void)
{
	srand(time(NULL));

	Server server(DEFAULT_PORT);

	cout << "Server up and running." << endl;

	for (int i = 0; i < MAX_CLIENTS; i++)
	{
		server.ListenForNewConnection();
	}
	
	//auto v = SQL_MANAGER->getRegisteredUsers();
	/*if (SQL_MANAGER->isMailAlreadyUsed("vladescu.andrei@mta.ro"))
		cout << "DA";
	else cout << "NU";*/
	//auto v = SQL_MANAGER->provideAnswersForLoading(27);
	/*vector<string> dest = { "1", "2" };
	vector<string> src = { "3", "4" };
	dest.insert(dest.end(),
		make_move_iterator(src.begin()),
		make_move_iterator(src.end())
	);*/
	//auto vect = SQL_MANAGER->getAssignedStudyGroups(26);
	//auto vect = SQL_MANAGER->getAssignedStudents(26);
	//auto vect = SQL_MANAGER->provideAnswersForLoading(22);
	//auto vect = SQL_MANAGER->provideQuestionsForLoading(26);
	//auto vect = SQL_MANAGER->provideTestsForLoading();
	//vector<string> vStr = SQL_MANAGER->provideTestsForLoading();
	//SQL_MANAGER->assignTo(26, 10002); //testID, userID
	//SQL_MANAGER->assignTo(26, "C112A");
	//SQL_MANAGER->assignTo(26, "C112E");
	//SQL_MANAGER->insertNewGrade(10001, "Filosofie", 6);
	/*auto vect = SQL_MANAGER->getStudentGrades(10001);
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i].first << " " << vect[i].second << endl;
	}*/
	//cout << SQL_MANAGER->getLastTestID();
	//cout << SQL_MANAGER->getLastQuestionID();
	//cout << SQL_MANAGER->getLastTestIDofSubject("Filosofie");
	//SQL_MANAGER->setQuestionPoints(8, 5.5);
	//SQL_MANAGER->insertNewAnswer(8, "niciunul");
	//SQL_MANAGER->insertNewQuestion(3, "Care este sensul vietii?", 4.5);
	//SQL_MANAGER->insertNewTest("Filosofie", "Test Filosofie", "0/15/5/4/2022");
	//SQL_MANAGER->makeProfessorOfSubject(10008, "Filosofie");
	//SQL_MANAGER->insertNewSubject("Geografie");
	//cout << SQL_MANAGER->getAllSubjects();
	//cout << SQL_MANAGER->getSubjectOfProfessor(10010);
	//cout << SQL_MANAGER->getTestPoints(1);
	//cout << SQL_MANAGER->getQuestionPoints(4);
	//cout << SQL_MANAGER->getAnswersOfQuestionWithTruthness(5);
	//cout << SQL_MANAGER->getAnswersOfQuestion(2);
	//SQL_MANAGER->setTestDate(1, TIME->getExactHour());
	//SQL_MANAGER->setTestDate(1, "0/12/6/4/2022");
	//cout << SQL_MANAGER->getAllAnswers();

	//cout << TIME->getExactHour() << endl;
	//cout << SQL_MANAGER->getTestDate(1);

	/*vector<string> timeUnparsed = PARSER->unparseString(SQL_MANAGER->getTestDate(1), '/');
	for (int i = 0; i < 5; i++)
		cout << timeUnparsed[i] << endl;*/

	//cout << TIME->getExactHour() << endl;
	// 
	//SQL_MANAGER->setUserPassword(10000, "rosmin_cosu");
	//int seed = HASH->extractSeed(SQL_MANAGER->getPassword(10003))  ;
	//cout << HASH->getPasswordHash("bannerlord");
	//cout << SQL_MANAGER->getAllUserData(10001);

	/*if (SQL_MANAGER->authentifyUser("rosu.cosmin@mta.ro", "rosmin_cosu"))
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