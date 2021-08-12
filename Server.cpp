#include "Server.h"

Server::Server(int PORT)
{
	TIME->printTime();
	LoadTests();

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
		/*if (!Authentify(ConnectionCounter)) {
			return false;
		}*/

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

bool Server::ProcessString(int index, string value)
{
	//This function is responsible for all the processing
	//Make a protocol
	//E.g. 1$data$in$parsed$mode
	// 1-> function name, i.e. give me my student grades
	// the next data parsed by the delimiter "$" is the one which is to be processed by the respective function
	// getStudentGrade(...), the params are the data to be given by the unparsed string
	// 1$UserID$SubjectID
	// getStudentGrade(int userID, int SubjectID) => returns grade for the user with userID 
	// at subject with subjectID

	if (!GetString(index, value))
		return false;

	vector<string> unparsedStringVector = PARSER->unparseString(value, '$');

	FunctionCode functionCall = (FunctionCode)atoi(unparsedStringVector[0].c_str());

	Protocol protocol(functionCall, value);

	string sendString;
	vector<string> sendVectString;

	switch (functionCall) {
	case(FunctionCode::SendClientAllUserData):
	{
		/*sendVectString.push_back(this->userList[index]->getUserFullName());
		PARSER->protocoliseString(1, sendVectString);
		sendString = PARSER->parseString(sendVectString, '$');

		if (!SendString(index, sendString))
			return false;*/
		break;
	}
	case(FunctionCode::ChangeUserPassword):
	{
		ChangeUserPassword(index, unparsedStringVector);
		break;
	}
	case (FunctionCode::InsertNewTest):
	{
		InsertNewTest(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::InsertNewUser):
	{
		InsertNewUser(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::SendClientTestList):
	{
		SendClientTestList(index);
		break;
	}
	case(FunctionCode::InsertNewQuestion):
	{
		InsertNewQuestion(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::InsertNewGrade):
	{
		InsertNewGrade(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::SendClientHisGrades):
	{
		SendClientHisGrades(index);
		break;
	}
	case(FunctionCode::SendAllOnlineClients):
	{
		SendAllOnlineClients(index);
		break;
	}
	case(FunctionCode::ModifyGradeOfStudent):
	{
		ModifyGradeOfStudent(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::SendClientGradesPerStudyGroup):
	{
		SendClientGradesPerStudyGroup(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::SendProfessorHisSubject):
	{
		SendProfessorHisSubject(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::AssignTestToStudent):
	{
		AssignTestToStudent(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::AssignTestToStudyGroup):
	{
		AssignTestToStudyGroup(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::SendProfessorTests):
	{
		SendProfessorTests(index);
		break;
	}
	case(FunctionCode::Authentify):
	{
		Authentify(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::MakeProfessorOwnerOfSubject):
	{
		MakeProfessorOwnerOfSubject(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::LogoutUser):
	{
		LogoutUser(index);
		break;
	}
	case(FunctionCode::SendAllRegisteredUsers):
	{
		SendAllRegisteredUsers(index);
		break;
	}
	case(FunctionCode::DeleteUser):
	{
		DeleteUser(index, unparsedStringVector);
		break;
	}
	default:
	{
		cout << "******** Invalid Protocol Function Call ********" << endl;
		return false;
		break;
	}
	}

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
	if (uRole == 1) {
		dynamic_cast<Student*>(tempUser)->setStudyGroup(SQL_MANAGER->getUserStudyGroup(uID));
		dynamic_cast<Student*>(tempUser)->setStudyYear(SQL_MANAGER->getUserStudyYear(uID));
	}
	else if (uRole == 2) {
		dynamic_cast<Profesor*>(tempUser)->setSubject(SQL_MANAGER->getSubjectOfProfessor(uID));
	}
	userList.push_back(tempUser);
}

bool Server::SendUserInfo(int index)
{
	//Crapa aici de la index
	//Sending the user it's vital info at connection time, so it can be displayed/manipulated faster
	vector<string> sendMessageVector = {
		to_string(userList[index]->getUserID()),
		userList[index]->getUserLastName(),
		userList[index]->getUserFirstName(),
		userList[index]->getUserEmail(),
		userList[index]->getUserJoinDate(),
		to_string(userList[index]->getUserRole())
	};
	
	//For Student, you get 2 more fields : studyGroup, studyYear
	int userRole = userList[index]->getUserRole();
	if (userRole == 1) {
		sendMessageVector.push_back(dynamic_cast<Student*>(userList[index])->getStudyGroup());
		sendMessageVector.push_back(to_string(dynamic_cast<Student*>(userList[index])->getStudyYear()));
	}
	//For Professor, you get subjectName
	else if (userRole == 2) {
		sendMessageVector.push_back(dynamic_cast<Profesor*>(userList[index])->getSubject());
	}

	
	string parsedString = PARSER->parseString(PARSER->protocoliseString((int)FunctionCode::SendClientAllUserData, sendMessageVector), '$');

	Protocol protocol((FunctionCode)1, parsedString);

	if (!SendString(index, parsedString)) {
		cout << "Sending user " + to_string(index) + " data failed." << endl;
		return false;
	}

	return true;
}

void Server::LoadTests()
{
	//4 strings per test
	//testID, TestName, SubjectID, InboundDate, TimeToComplete
	// 0		1			2			3			  4
	vector<string> testVector = SQL_MANAGER->provideTestsForLoading();
	int numberOfTests = testVector.size() / 5;
	for (int indexTests = 0; indexTests < numberOfTests; indexTests++) {
		vector<string> questionVector = SQL_MANAGER->provideQuestionsForLoading(stoi(testVector[indexTests * 5])); //testID
		string subjectName = SQL_MANAGER->getSubjectName(stoi(testVector[indexTests * 5 + 2]));
		ITest* tempTest = FactoryTest::createTest(testVector[indexTests * 5 + 1],
			subjectName,
			testVector[indexTests * 5 + 3]);
		tempTest->setID(stoi(testVector[indexTests * 5]));
		tempTest->setTimeToComplete(stoi(testVector[indexTests * 5 + 4]));
		tempTest->assignTo(SQL_MANAGER->getAssignedStudents(tempTest->getID())); //get me the students
		tempTest->assignTo(SQL_MANAGER->getAssignedStudyGroups(tempTest->getID())); //get me the studygroups
		//4 strings per Question
		//questionID, QuestionBody, testID, points
		int numberOfQuestions = questionVector.size() / 4;
		for (int indexQuestions = 0; indexQuestions < numberOfQuestions; indexQuestions++) {
			//questionID
			IQuestion* tempQuestion;
			int numberOfAnswers = SQL_MANAGER->getNumberOfAnswersOfAQuestion(stoi(questionVector[indexQuestions * 4]));
			if (numberOfAnswers == 1) {
				// is an OpenEndedQuestion
				//4 per answer
				//answerID, Answer, questionID, truthness
				string answer = SQL_MANAGER->provideAnswersForLoading(stoi(questionVector[indexQuestions * 4]))[1];
				tempQuestion = FactoryQuestion::getOpenEndedQuestion(answer,
					questionVector[indexQuestions * 4 + 1], 
					stof(questionVector[indexQuestions * 4 + 3]));
			}
			else 
			{
				// is a MultipleChoiceQuestion
				vector<pair<string, bool>> answers;
				vector<string> vectStr = SQL_MANAGER->provideAnswersForLoading(stoi(questionVector[indexQuestions * 4]));
				for (int indexAnswers = 0; indexAnswers < numberOfAnswers; indexAnswers++) {
					answers.push_back(make_pair(vectStr[indexAnswers * 4 + 1],
						(bool)stoi(vectStr[indexAnswers * 4 + 3])));
				}
				tempQuestion = FactoryQuestion::getMultipleChoiceQuestion(answers,
					questionVector[indexQuestions * 4 + 1],
					stof(questionVector[indexQuestions * 4 + 3]));
			}

			tempTest->addQuestion(tempQuestion);
		}
		this->testList.push_back(tempTest);
	}
}

void Server::ChangeUserPassword(int index, vector<string> vStr)
{
	//userID, newPassword 
	SQL_MANAGER->setUserPassword(userList[index]->getUserID(), vStr[1]);

}

void Server::InsertNewTest(int index, vector<string> vStr)
{
	
	//Test(string testName, IUser* owner, vector<IUser*> toStudents, string testTime);
	//Test(string testName, IUser* owner, string testTime);
	// 
	//packet : $testName$testDate$subjectName$numberOfQuestions$timeToComplete
	//				1		2			3			4				  5
	//request more packets for questions
	// 
	//Phase 1: Get the Test
	//
	//load into database
	SQL_MANAGER->insertNewTest(vStr[3], vStr[1], vStr[2], stoi(vStr[5]));
	//load into memory
	ITest* tempTest = FactoryTest::createTest(vStr[1], userList[index], vStr[2]);

	if (vStr[3][vStr[3].size() - 1] != '\0') {
		vStr[3].push_back('\0');
	}

	tempTest->setSubject(vStr[3]);
	tempTest->setID(SQL_MANAGER->getLastTestID());
	// Pana aici e testul
	// 
	//Phase 2: Get the Questions
	tempTest->setNumberOfQuestions(stoi(vStr[4]));
	
	tempTest->setTimeToComplete(stoi(vStr[5]));
	this->testList.push_back(tempTest);
}

void Server::InsertNewQuestion(int index, vector<string> vStr)
{
	//primesc stringuri noi;
		//				1				2			3			4			5			6						n
		//packet :$ questionType $ questionBody $ points  +													testFinished = 1
		//divergenta cand e tip de intrebare diferita:
		//OpenEndedQuestion :								$answer
		//MultipleChoiceQuestion :							$numberOfAnswers$answer$truthness $answer....

	ITest* tempTest = testList[testList.size() - 1]; // last element
	//Insertie in baza de date a unei intrebari noi
	SQL_MANAGER->insertNewQuestion(tempTest->getID(), 
		vStr[2],
		stof(vStr[3]));

	IQuestion* tempQuestion = nullptr;

	switch ((QuestionType)stoi(vStr[1]))
	{
	case (QuestionType::OpenEndedQuestion): {

		tempQuestion = FactoryQuestion::getOpenEndedQuestion(vStr[4],
			vStr[2],
			stof(vStr[3]));

		SQL_MANAGER->insertNewAnswer(SQL_MANAGER->getLastQuestionID(),
			vStr[4]);
		//
		break;
	}
	case (QuestionType::MultipleChoiceQuestion): {

		int numberOfAnswers = stoi(vStr[4]);
		int j = 4;

		vector <pair<string, bool>> answerList;

		for (int i = 0; i < numberOfAnswers; i++) {
			answerList.push_back(make_pair(vStr[j + 1],
				(bool)stoi(vStr[j + 2])));

			SQL_MANAGER->insertNewAnswer(SQL_MANAGER->getLastQuestionID(),
				vStr[j + 1],
				stoi(vStr[j + 2]));
			j += 2;
		}

		tempQuestion = FactoryQuestion::getMultipleChoiceQuestion(answerList,
			vStr[2],
			stof(vStr[3]));

		break;
	}
	default:
	{
		tempQuestion = new Question("Invalid question", 404);
	}
	}

	tempTest->addQuestion(tempQuestion);
}

void Server::InsertNewUser(int index, vector<string> vStr)
{
	//userRole, LastName, FirstName, Email, Password + if it's the case
													// StudyGroup, StudyYear
	//it first returns a bool to make sure the mail is not used
	if (SQL_MANAGER->isMailAlreadyUsed(vStr[4]) == 0) {
		SendBool(index, true);
	}
	else {
		SendBool(index, false);
		return;
	}
	string buffer;
	
	{
		buffer += "(";
		buffer += vStr[1];
		buffer += ", '";
		buffer += vStr[2];
		buffer += "', '";
		buffer += vStr[3];
		buffer += "', '";
		buffer += vStr[4];
		buffer += "', '";
		buffer += HASH->getPasswordHash(vStr[5]);
		buffer += "', ";

		if (atoi(vStr[1].c_str()) == 1) {
			buffer += "'";
			buffer += vStr[6];
			buffer += "', ";
			buffer += vStr[7];
			buffer += ", ";
		}

		buffer += "GETDATE())";

	}

	switch (atoi(vStr[1].c_str()))
	{
	case(1):
	{

		SQL_MANAGER->insertNewStudent(buffer);
		break;
	}
	case(2):
	{

		SQL_MANAGER->insertNonStudent(buffer);
		break;
	}
	case(3):
	{

		SQL_MANAGER->insertNonStudent(buffer);
		break;
	}
	default:
	{
		cout << "Invalid Role" << endl; //throw me an exception
		return;
	}
	}
}

void Server::InsertNewGrade(int index, vector<string> vStr)
{
	//InsertNewGrade = 7 
	//subjectName$grade
	SQL_MANAGER->insertNewGrade(userList[index]->getUserID(), vStr[1], stoi(vStr[2]));
}

void Server::SendClientHisGrades(int index)
{
	//SendClientHisGrades = 8;
	//numberOfPairs$subjectName1$grade1$...
	vector<pair<string, int>> recvVect = SQL_MANAGER->getStudentGrades(userList[index]->getUserID());
	vector<string> unparsedVect = { to_string(8), to_string(recvVect.size()) };
	for (int i = 0; i < recvVect.size(); i++) {
		unparsedVect.push_back(recvVect[i].first);
		unparsedVect.push_back(to_string(recvVect[i].second));
	}
	string sendString = PARSER->parseString(unparsedVect, '$');

	//SendInt(index, sendString.size());
	SendString(index, sendString);
	//SendString(index, sendString);
}

void Server::SendAllOnlineClients(int index)
{
	//SendAllOnlineClients = 9
	// protocol$numberOfClients$fullUserName1$userID1$userRole1$...
	/*vector<IUser*> tempVector;
	for (int i = 0; i < userList.size(); i++) {
		if (userList[i]->getConnectionStatus())
			tempVector.push_back(userList[i]);
	}*/
	auto tempVector = userList;

	vector<string> unparsedVect = { to_string(9), to_string(tempVector.size()) };
	for (int i = 0; i < tempVector.size(); i++) {
		/*if (lastEmail.length() == 0)
			lastEmail = userList[i]->getUserEmail();
		if (userList[i]->getUserEmail() == lastEmail)
			continue;
		else
			lastEmail = userList[i]->getUserEmail();*/

		//if it got disconnected
		//quick-fix
		//if (userList[i]->getUserID() == -1)
		//	continue;
		unparsedVect.push_back(tempVector[i]->getUserFullName());
		unparsedVect.push_back(to_string(tempVector[i]->getUserID()));
		unparsedVect.push_back(to_string(tempVector[i]->getUserRole()));
	}
	string sendString = PARSER->parseString(unparsedVect, '$');
	//SendInt(index, 9);
	SendString(index, sendString);
}

void Server::ModifyGradeOfStudent(int index, vector<string> vStr)
{
	//modifyGradeOfStudent = 10
	//protocolNumber$userID$subjectName$grade
	//		0			1	   2		 3
	//
	SQL_MANAGER->modifyGradeOfStudent(stoi(vStr[1]),
		vStr[2],
		stoi(vStr[3]));
}

void Server::SendClientGradesPerStudyGroup(int index, vector<string> vStr)
{
	//SendClientGradesPerStudyGroup = 13
	//protocolNumber$StudyGroup$subjectName
	//	  0				  1			 2
	//
	auto stringVector = SQL_MANAGER->getStudentsGradesPerStudyGroup(vStr[1], vStr[2]);
	stringVector = PARSER->protocoliseString(13, stringVector);
	string sendString = PARSER->parseString(stringVector, '$');
	SendString(index, sendString);
}

void Server::SendProfessorHisSubject(int index, vector<string> vStr)
{
	//SendProfessorHisSubject = 11
	//protocolNumber$userID
	//		0			1
	string buffer = SQL_MANAGER->getSubjectOfProfessor(stoi(vStr[1]));
	auto vectString = { to_string(11), buffer };
	buffer = PARSER->parseString(vectString, '$');
	SendString(index, buffer);
}

void Server::AssignTestToStudent(int index, vector<string> vStr)
{
	//protocolCode$testID$userID
	//		0		 1		2
	SQL_MANAGER->assignTo(stoi(vStr[1]), stoi(vStr[2]));
}

void Server::AssignTestToStudyGroup(int index, vector<string> vStr)
{
	//protocolCode$testID$studyGroup
	//		0		 1		2

	for (int i = 0; i < testList.size(); i++)
	{
		if (testList[i]->getID() == atoi(vStr[1].c_str()))
		{
			testList[i]->assignTo(vStr[2]);
			break;
		}
	}

	SQL_MANAGER->assignTo(stoi(vStr[1]), vStr[2]);
}

void Server::SendProfessorTests(int index)
{
	//Complex send
	//SendProfessorTests = 16
	//protocolCode$nrteste$
	//		0		  1
	vector<ITest*> professorTests;
	if (userList[index]->getUserRole() != 2)
	{
		cout << "Not a valid contender" << endl;
		return;
	}
	string professorSubject = dynamic_cast<Profesor*>(userList[index])->getSubject();
	professorSubject.push_back('\0');
	for (int indexTeste = 0; indexTeste < testList.size(); indexTeste++) {
		string testSubject = this->testList[indexTeste]->getSubject();
		if (testSubject == professorSubject)
			professorTests.push_back(testList[indexTeste]);
	}
	//professorTests is full now

	vector<string> sendVect = { to_string(16), to_string(professorTests.size()) };
	string sendStr = PARSER->parseString(sendVect, '$');
	//SpecialSendString(index, sendStr);
	SendString(index, sendStr);
	//the user now knows of the test number
	//need to delvier each one separately

	//TestName, Date, ID, TimeToComplete NumberOfAssignedStudyGroups, studyGroups, NumberOfAssignedStudents, studentIDs, NumberOfQuestions,
	//									 questionBody, points, questionType,
	//																		answer --OpenEnded
	//																		numberOfAnswers, answer1, truthnessOfAnswer1, etc.
	for (int indexTeste = 0; indexTeste < professorTests.size(); indexTeste++) {
		sendVect.clear();
		ITest* currentTest = professorTests[indexTeste];
		sendVect.push_back(currentTest->getName());//name
		sendVect.push_back(currentTest->getTime());//dateTime
		sendVect.push_back(to_string(currentTest->getID()));//ID of test
		sendVect.push_back(to_string(currentTest->getTimeToComplete()));//TimeToComplete
		sendVect.push_back(to_string(currentTest->getNumberOfStudyGroups())); //nmbrOfStudyGroups loaded
		for (int i = 0; i < currentTest->getNumberOfStudyGroups(); i++) {
			sendVect.push_back(currentTest->getAssignedStudyGroups()[i]);
		} //studyGroups loaded

		/*
		sendVect.push_back(to_string(currentTest->getNumberOfStudents()));//nmbrOfStudents loaded
		for (int i = 0; i < currentTest->getNumberOfStudents(); i++) {
			sendVect.push_back(to_string(currentTest->getAssignedStudents()[i]));
		}*/
		//students loaded
		//Questions up next
		//  __
		// |  |
		// |  |
		// |  |
		//_|  |_
		//\    /
		// \  /
		//  \/
		//
		int numberOfQuestions = currentTest->getQuestions().size();
		sendVect.push_back(to_string(numberOfQuestions));//number of Questions
		//
		//That's it, release the second package
		//
		string sendStr = PARSER->parseString(sendVect, '$');
		//SpecialSendString(index, sendStr);
		SendString(index, sendStr);
		//
		/*
		auto vectQuestions = currentTest->getQuestions();
		for (int indexQuestions = 0; indexQuestions < numberOfQuestions; indexQuestions++) {
			sendVect.clear(); //clear the vector to allow for more packets
			sendVect.push_back(vectQuestions[indexQuestions]->getBody());
			sendVect.push_back(to_string(vectQuestions[indexQuestions]->getPoints()));
			sendVect.push_back(to_string((int)vectQuestions[indexQuestions]->getQuestionType()));
			QuestionType qType = vectQuestions[indexQuestions]->getQuestionType();

			switch (qType) {
				case(QuestionType::OpenEndedQuestion): {
					sendVect.push_back(dynamic_cast<OpenEndedQuestion*>(vectQuestions[indexQuestions])->getAnswer());
					break;
				}
				case(QuestionType::MultipleChoiceQuestion): {
					vector<pair<string, bool>> answerVect = dynamic_cast<MultipleChoiceQuestion*>(vectQuestions[indexQuestions])->getAllAnswers();
					for (int indexAnswers = 0; indexAnswers < answerVect.size(); indexAnswers++) {
						sendVect.push_back(answerVect[indexAnswers].first);
						sendVect.push_back(to_string(answerVect[indexAnswers].second));
					}
					break;
				}
			}
			string sendStr = PARSER->parseString(sendVect, '$');
			//SpecialSendString(index, sendStr);
			SendString(index, sendStr);
		}*/
	}

}

void Server::MakeProfessorOwnerOfSubject(int index, vector<string> vStr)
{
	//protocolCode$userID$subjectName
	//		0		 1		  2
	dynamic_cast<Profesor*>(userList[index])->setSubject(vStr[2]);
	SQL_MANAGER->makeProfessorOfSubject(stoi(vStr[1]), vStr[2]);
}

void Server::LogoutUser(int index)
{
	//protocolCode
	//		0		
	this->userList.erase(userList.begin() + index);
	//this->userList[index]->setConnectionStatus();
}

void Server::SendClientTestList(int index)
{
	// Complex send
		//SendClientTestList = 4
		//protocolCode$nrteste$
		//		0		  1
		vector<ITest*> studentTests;
	if (userList[index]->getUserRole() != 1)
	{
		cout << "Not a valid contender" << endl;
		return;
	}
	string studentGroup = dynamic_cast<Student*>(userList[index])->getStudyGroup();
	studentGroup.pop_back(); //surplus space
	int studentID = dynamic_cast<Student*>(userList[index])->getUserID();
	for (int indexTeste = 0; indexTeste < testList.size(); indexTeste++) {
		int numberOfStudents = testList[indexTeste]->getAssignedStudents().size();
		auto vectorStudents = testList[indexTeste]->getAssignedStudents();

		bool doneThat = false;
		for (int indexStudents = 0; indexStudents < numberOfStudents; indexStudents++) {
			if (vectorStudents[indexStudents] == studentID) {
				studentTests.push_back(testList[indexTeste]);
				doneThat = true;
				break;
			}
		}
		if (doneThat)
			continue; // i already included the solitary student

		int numberOfGroups = testList[indexTeste]->getAssignedStudyGroups().size();
		auto vectorStudyGroups = testList[indexTeste]->getAssignedStudyGroups();

		for (int indexGroups = 0; indexGroups < numberOfGroups; indexGroups++) {
			if (vectorStudyGroups[indexGroups] == studentGroup)
				studentTests.push_back(testList[indexTeste]);
		}
	}
	//studentTests is full now

	vector<string> sendVect = { to_string(4), to_string(studentTests.size()) };
	string sendStr = PARSER->parseString(sendVect, '$');
	//SpecialSendString(index, sendStr);
	SendString(index, sendStr);
	//the user now knows of the test number
	//need to delvier each one separately

	//TestName, Date, ID, TimeToComplete, NumberOfAssignedStudyGroups, studyGroups, NumberOfAssignedStudents, studentIDs, NumberOfQuestions,
	//									 questionBody, points, questionType,
	//																		answer --OpenEnded
	//																		numberOfAnswers, answer1, truthnessOfAnswer1, etc. --MultipleChoiceQuestion
	for (int indexTeste = 0; indexTeste < studentTests.size(); indexTeste++) {
		sendVect.clear();
		ITest* currentTest = studentTests[indexTeste];
		sendVect.push_back(currentTest->getName());//name
		sendVect.push_back(currentTest->getTime());//dateTime
		sendVect.push_back(to_string(currentTest->getID()));//ID of test
		sendVect.push_back(to_string(currentTest->getTimeToComplete()));//Time to Complete


		//sendVect.push_back(to_string(currentTest->getNumberOfStudyGroups())); //nmbrOfStudyGroups loaded
		//for (int i = 0; i < currentTest->getNumberOfStudyGroups(); i++) {
		//	sendVect.push_back(currentTest->getAssignedStudyGroups()[i]);
		//} //studyGroups loaded
		//sendVect.push_back(to_string(currentTest->getNumberOfStudents()));//nmbrOfStudents loaded
		//for (int i = 0; i < currentTest->getNumberOfStudents(); i++) {
		//	sendVect.push_back(to_string(currentTest->getAssignedStudents()[i]));
		//}//students loaded
		//Questions up next
		//  __
		// |  |
		// |  |
		// |  |
		//_|  |_
		//\    /
		// \  /
		//  \/
		//
		int numberOfQuestions = currentTest->getQuestions().size();
		sendVect.push_back(to_string(numberOfQuestions));//number of Questions
		//
		//That's it, release the second package
		//
		//
		sendVect.push_back(currentTest->getSubject());
		//
		string sendStr = PARSER->parseString(sendVect, '$');
		//SpecialSendString(index, sendStr);
		SendString(index, sendStr);
		//
		auto vectQuestions = currentTest->getQuestions();
		for (int indexQuestions = 0; indexQuestions < numberOfQuestions; indexQuestions++) {
			sendVect.clear(); //clear the vector to allow for more packets
			sendVect.push_back(vectQuestions[indexQuestions]->getBody());
			sendVect.push_back(to_string(vectQuestions[indexQuestions]->getPoints()));
			sendVect.push_back(to_string((int)vectQuestions[indexQuestions]->getQuestionType()));
			QuestionType qType = vectQuestions[indexQuestions]->getQuestionType();

			switch (qType) {
			case(QuestionType::OpenEndedQuestion): {
				sendVect.push_back(dynamic_cast<OpenEndedQuestion*>(vectQuestions[indexQuestions])->getAnswer());
				break;
			}
			case(QuestionType::MultipleChoiceQuestion): {
				vector<pair<string, bool>> answerVect = dynamic_cast<MultipleChoiceQuestion*>(vectQuestions[indexQuestions])->getAllAnswers();
				//
				sendVect.push_back(to_string(answerVect.size()));
				//
				for (int indexAnswers = 0; indexAnswers < answerVect.size(); indexAnswers++) {
					sendVect.push_back(answerVect[indexAnswers].first);
					sendVect.push_back(to_string(answerVect[indexAnswers].second));
				}
				break;
			}
			}
			string sendStr = PARSER->parseString(sendVect, '$');
			//SpecialSendString(index, sendStr);
			SendString(index, sendStr);
		}
	}

}

void Server::SendAllRegisteredUsers(int index)
{
	//protocolNumber = 20$numberOfUsers$user1: 
	//										userID $ lastname + firstname $ email $ userRole...
	auto sendVector = SQL_MANAGER->getRegisteredUsers();
	sendVector = PARSER->protocoliseString(sendVector.size(), sendVector);
	sendVector = PARSER->protocoliseString(20, sendVector);

	string sendString = PARSER->parseString(sendVector, '$');

	SendString(index, sendString);
}

void Server::DeleteUser(int index, vector<string> vStr)
{
	//protocol = 21
	SQL_MANAGER->deleteUser(stoi(vStr[1]));
}

bool Server::CloseConnection(int index)
{
	//this->userList.erase(userList.begin() + index);
	//userList[index - 1]->setUserID(-1);
	if (closesocket(Connections[index]) == SOCKET_ERROR)
	{
		cout << "Failed closing Error: " << WSAGetLastError() << endl;
		connectionThreads[index].detach();
		ConnectionCounter--;
		return false;
	}
	connectionThreads[index].detach();
	ConnectionCounter--;
	return true;
}

bool Server::Authentify(int index, vector<string> vStr)
{
	//protocolNumber$userName$userPassword
	//		0			1			2
	//
	if (!SQL_MANAGER->authentifyUser(vStr[1], vStr[2])) {
		SendBool(index, false);
		return false;
	}
	SendBool(index, true);
	cout << "Connection succesful." << endl;

	//Loads into memory
	LoadUserInfo(ConnectionCounter, vStr[1]);
	SendUserInfo(ConnectionCounter - 1);
}

//Bulk of work
void Server::ClientHandler(int index)
{
	string receiveString;
	while (true)
	{
		//Receive Messages
		if (!serverPtr->ProcessString(index, receiveString))
			break;
	}

	cout << "Lost contact with client: id = " << index << endl;

	serverPtr->CloseConnection(index);
}