#include "SQLManager.h"

SQLManager* SQLManager::instance = nullptr;

SQLManager::SQLManager()
{
    cout << "SQL Manager up and running." << endl;
}

SQLManager* SQLManager::getInstance()
{
     if (instance == nullptr)
        instance = new SQLManager;
    return instance;
}

string SQLManager::makeCustomQuery(const wchar_t* query, int column)
{
    Query* temp_query = new Query;

    return temp_query->makeCustomQuery(query, column);
}

void SQLManager::destroyInstance()
{
    if (instance != nullptr){
        delete instance;
        instance = nullptr;
    }
}

string SQLManager::getAllUserNames()
{
    Query* temp_query = new Query;

    return temp_query->getAllUserNames();
}

int SQLManager::getUserRole(string uEmail)
{
    Query* temp_query = new Query;
    string query;

    query = "select UserRole from Users where Email = '" + uEmail + "'";
    return atoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1).c_str());
}

int SQLManager::getUserID(string uEmail)
{
    Query* temp_query = new Query;
    string query;
        
    query = "select UserID from Users where Email = '" + uEmail + "'";
    string returnBuffer = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
    if (returnBuffer.size() == 0)
        return -1;
    return stoi(returnBuffer);
}

string SQLManager::makeRangedQuery(const wchar_t* query, int column_start, int column_finish)
{
    Query* temp_query = new Query;
    return temp_query->makeRangedQuery(query, column_start, column_finish);
}

string SQLManager::getFullUserName(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select LastName + FirstName from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getUserFirstName(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select FirstName from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getUserLastName(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select LastName from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getUserEmail(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select Email from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getUserJoinedDate(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select JoinDate from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

int SQLManager::getUserStudyYear(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select StudyYear from Users where UserID = " + to_string(userID);
    return atoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1).c_str());
}

string SQLManager::getUserStudyGroup(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select StudyGroup from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getPassword(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select PasswordHash from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null);
}

string SQLManager::getTestName(int testID)
{
    Query* temp_query = new Query;
    string query;

    query = "select TestName from Tests where TestID = " + to_string(testID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null);
}

string SQLManager::getTestDate(int testID)
{
    Query* temp_query = new Query;
    string query;

    query = "select InboundDate from Tests where TestID = " + to_string(testID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null);
}

string SQLManager::getAllAnswers()
{
    Query* temp_query = new Query;
    string query;

    query = "select Answer +' ' + CAST(QuestionID as varchar) from Answers";
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
}

string SQLManager::getAnswersOfQuestion(int questionID)
{
    Query* temp_query = new Query;
    string query;

    query = "select Answer from Answers where QuestionID = " + to_string(questionID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::DollarSign);
}

string SQLManager::getAnswersOfQuestionWithTruthness(int questionID)
{

    Query* temp_query = new Query;
    string query;

    query = "select CAST(Truthness as varchar) + '$' + Answer from Answers where QuestionID = " +
        to_string(questionID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::DollarSign);
}

float SQLManager::getQuestionPoints(int questionID)
{
    Query* temp_query = new Query;
    string query;

    query = "select Points from Questions where QuestionID = " + to_string(questionID);
    //stof = string to float
    return stof(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null).c_str());
}

float SQLManager::getTestPoints(int testID)
{
    Query* temp_query = new Query;
    string query;

    query = "select Points from Questions where TestID = " + to_string(testID);
    //stof = string to float
    string parsedString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::DollarSign).c_str();
    vector<string> unparsedVectorString = PARSER->unparseString(parsedString, '$');

    float sum = 0;
    for (int index = 0; index < unparsedVectorString.size(); index++)
        sum += stof(unparsedVectorString[index]);

    return sum;
}

string SQLManager::getSubjectOfProfessor(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select SubjectName from Subjects where ProfessorID = " + to_string(userID);
    //stof = string to float
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null).c_str();
}

string SQLManager::getAllSubjects()
{
    Query* temp_query = new Query;
    string query;

    query = "select SubjectName from Subjects";

    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
}

int SQLManager::getSubjectID(string subjectName)
{
    Query* temp_query = new Query;
    string query;

    string aux = subjectName.c_str();
    subjectName = aux;

    query = "select SubjectID from Subjects where SubjectName = '" +
        subjectName +
        "'";

    return atoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine).c_str());
}

int SQLManager::getLastTestIDofSubject(string subjectName)
{
    Query* temp_query = new Query;
    string query;

    int subjectID = getSubjectID(subjectName);

    query = "select top(1) TestID from Tests where SubjectId = " +
        to_string(subjectID) + 
        " order by TestId Desc";

    return atoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null).c_str());
}

int SQLManager::getLastQuestionID()
{
    Query* temp_query = new Query;
    string query;

    query = "select top(1) QuestionID from Questions order by QuestionID desc";

    return atoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null).c_str());
}

int SQLManager::getLastTestID()
{
    Query* temp_query = new Query;
    string query;

    query = "select top(1) TestID from Tests order by TestID desc";

    return atoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null).c_str());
}

vector<pair<string, int>> SQLManager::getStudentGrades(int userID)
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = " select S.SubjectName + ' ' + convert(nvarchar(15),G.Grade) from Grades as G inner join Subjects as S on S.SubjectID = G.SubjectID inner join Users as U on U.UserID = G.StudentID where U.UserID = " + 
        to_string(userID);

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1,QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    vector<pair<string, int>> resultedVector;
    for (int index = 0; index < returnVector.size(); index++) {
        auto tempVector = PARSER->unparseString(returnVector[index], ' ');
        resultedVector.push_back(make_pair(tempVector[0], stoi(tempVector[1])));
    }
    return resultedVector;
}

vector<string> SQLManager::getStudentsGradesPerStudyGroup(string studyGroup, string subjectName)
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select U.FirstName + ' ' + U.LastName  + '$' +  convert(nvarchar(15), G.Grade) + '$' +  convert(nvarchar(15), U.UserID) from Users as U inner join Grades as G on G.StudentID = U.UserID inner join Subjects as S on S.SubjectID = G.SubjectID where U.StudyGroup = '" +
        studyGroup +
        "' and S.SubjectName = '" +
        subjectName +
        "'";

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    vector<string> resultedVector;
    for (int index = 0; index < returnVector.size(); index++) {
        auto tempVector = PARSER->unparseString(returnVector[index], '$');
        resultedVector.push_back(tempVector[0]);
        resultedVector.push_back(tempVector[1]);
        resultedVector.push_back(tempVector[2]);
    }
    return resultedVector;
}

vector<string> SQLManager::provideTestsForLoading()
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select CONVERT(nvarchar(15),TestID) + '$' + TestName + '$' + CONVERT(nvarchar(15),SubjectID) + '$' + InboundDate + '$' +  CONVERT(nvarchar(15),TimeToComplete) from Tests";

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    vector<string> resultedVector;
    for (int index = 0; index < returnVector.size(); index++) {
        auto tempVector = PARSER->unparseString(returnVector[index], '$');
        resultedVector.push_back(tempVector[0]);//testid
        resultedVector.push_back(tempVector[1]);//testname
        resultedVector.push_back(tempVector[2]);//subjectid
        resultedVector.push_back(tempVector[3]);//date
        resultedVector.push_back(tempVector[4]);//timeToComplete
    }
    return resultedVector;
}

vector<string> SQLManager::provideQuestionsForLoading(int testID)
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select CONVERT(nvarchar(15),QuestionID) + '$' + Question + '$' + CONVERT(nvarchar(15),TestID) + '$' + CONVERT(nvarchar(15),Points) from Questions where TestID = " +
        to_string(testID);

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    vector<string> resultedVector;
    for (int index = 0; index < returnVector.size(); index++) {
        auto tempVector = PARSER->unparseString(returnVector[index], '$');
        resultedVector.push_back(tempVector[0]);
        resultedVector.push_back(tempVector[1]);
        resultedVector.push_back(tempVector[2]);
        resultedVector.push_back(tempVector[3]);
    }
    return resultedVector;
}

vector<string> SQLManager::provideAnswersForLoading(int QuestionID)
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select CONVERT(nvarchar(15),AnswerID) + '$' + Answer + '$' + CONVERT(nvarchar(15),QuestionID) + '$' + CONVERT(nvarchar(15),Truthness) from Answers where QuestionID = " +
        to_string(QuestionID);

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    vector<string> resultedVector;
    for (int index = 0; index < returnVector.size(); index++) {
        auto tempVector = PARSER->unparseString(returnVector[index], '$');
        resultedVector.push_back(tempVector[0]);
        resultedVector.push_back(tempVector[1]);
        resultedVector.push_back(tempVector[2]);
        resultedVector.push_back(tempVector[3]);
    }
    return resultedVector;
}

int SQLManager::getNumberOfAnswersOfAQuestion(int questionID)
{
    Query* temp_query = new Query;
    string query;

    query = "select count(*) from Answers where QuestionID = " +
        to_string(questionID);

    return stoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null));
}

string SQLManager::getSubjectName(int subjectID)
{
    Query* temp_query = new Query;
    string query;

    query = "select SubjectName from Subjects where SubjectID = " +
        to_string(subjectID);

    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null);
}

vector<string> SQLManager::getAssignedStudyGroups(int testID)
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select StudyGroup from AssignedTo where StudyGroup is not null and TestID = " +
        to_string(testID);

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    return returnVector;
}

vector<int> SQLManager::getAssignedStudents(int testID)
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select StudentID from AssignedTo where StudentID is not null and TestID = " +
        to_string(testID);

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    vector<int> resultedVector;
    for (int i = 0; i < returnVector.size(); i++){
        resultedVector.push_back(stoi(returnVector[i]));
    }
    return resultedVector;
}

vector<string> SQLManager::getRegisteredUsers()
{
    //userID $ lastname + firstname $ email $ userRole
    //  0               1               2        3
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select convert(nvarchar(20), UserID) + '$' + LastName + ' ' + FirstName + '$' + Email + '$' + convert(nvarchar(20), UserRole) from Users";


    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::NewLine);
    vector<string> returnVector = PARSER->unparseString(returnString, '\n');
    vector<string> resultedVector;
    for (int i = 0; i < returnVector.size(); i++) {
        auto tempVect = PARSER->unparseString(returnVector[i], '$');
        resultedVector.push_back(tempVect[0]);//id
        resultedVector.push_back(tempVect[1]);//name
        resultedVector.push_back(tempVect[2]);//mail
        resultedVector.push_back(tempVect[3]);//role
    }
    return resultedVector;
}

void SQLManager::deleteUser(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "delete Users where UserID = " +
        to_string(userID);

    temp_query->insertData(STR_TO_WSTR(query));
}

bool SQLManager::isMailAlreadyUsed(string email)
{
    Query* temp_query = new Query;
    string query;
    string returnString;

    query = "select UserID from Users where Email =  '" +
        email +
        "'";

    returnString = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null);

    if (returnString.size() == 0)
        return false;
    return true;
}

void SQLManager::assignTo(int testID, int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "Insert into AssignedTo(TestID, StudentID) values (" +
        to_string(testID) +
        ", " +
        to_string(userID) +
        ")";

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::assignTo(int testID, string studyGroup)
{
    Query* temp_query = new Query;
    string query;

    query = "Insert into AssignedTo(TestID, StudyGroup) values (" +
        to_string(testID) +
        ", '" +
        studyGroup +
        "')";

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::modifyGradeOfStudent(int userID, string subjectName, int grade)
{
    Query* temp_query = new Query;
    string query;
    //int subjectID = getSubjectID(subjectName);

    query = "update Grades set Grades.Grade = " +
        to_string(grade) +
        " from Grades as G inner join Subjects as S on G.SubjectID = S.SubjectID where S.SubjectName = '"+ 
        subjectName +
        "' and G.StudentID = " +
        to_string(userID);

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::insertNewGrade(int userID, string subjectName, int grade)
{
    Query* temp_query = new Query;
    string query;
    int subjectID = getSubjectID(subjectName);

    query = "Insert into Grades(StudentID, SubjectID, Grade) values (" +
        to_string(userID) +
        ", " +
        to_string(subjectID) +
        ", " +
        to_string(grade) +
        ")";

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::makeProfessorOfSubject(int userID, string subjectName)
{
    Query* temp_query = new Query;
    string query;
    //
    query = "update Subjects set ProfessorID = " +
        to_string(userID) +
        " where SubjectName = '" +
        subjectName +
        "'";

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::insertNewSubject(string SubjectName)
{
    Query* temp_query = new Query;
    string query;
    // update Tests

    query = "Insert into Subjects(SubjectName) values ('" +
        SubjectName +
        "')";

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::insertNewTest(string subjectName, string testName, string inboundDate, int timeToComplete)
{
    Query* temp_query = new Query;
    string query;
    // update Tests

    int subjectID = getSubjectID(subjectName);

    query = "insert into tests(testname, subjectid, inboundDate, timetocomplete) values ('" +
        testName +
        "', " +
        to_string(subjectID) +
        ", '" +
        inboundDate +
        "', '" +
        to_string(timeToComplete) +
        "')";

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::insertNewQuestion(int testID, string questionBody, float points)
{
    Query* temp_query = new Query;
    string query;
    // update Tests

    query = "insert into Questions(Question, TestID, Points) values ('" +
        questionBody +
        "', " +
        to_string(testID) +
        ", " +
        to_string(points) +
        ")";

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::insertNewAnswer(int questionID, string answer, int truthness)
{
    Query* temp_query = new Query;
    string query;
    // update Tests
    if (truthness == -1) {
        query = "insert into Answers(Answer, QuestionID) values ('" +
            answer +
            "', " +
            to_string(questionID) +
            ")";
    }
    else
    {
        query = "insert into Answers(Answer, QuestionID, Truthness) values ('" +
            answer +
            "', " +
            to_string(questionID) +
            ", " +
            to_string(truthness) +
            ")";
    }


    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::setQuestionPoints(int questionID, float points)
{
    Query* temp_query = new Query;
    string query;
    // update Tests

    query = "update Questions set Points = " +
        to_string(points) +
        " where QuestionID = " +
        to_string(questionID);

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::setTestDate(int testID, string date)
{
    Query* temp_query = new Query;
    string query;
    // update Tests

    query = "update Tests set InboundDate = '" +
        date + 
        "' where testID = " +
        to_string(testID);

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::setUserPassword(int userID, string newPassword)
{
    //Make use of Hasher
    Query* temp_query = new Query;
    string query;
    //
    query = "update Users set PasswordHash = '"  +
        HASH->getPasswordHash(newPassword) +
        "' where UserID = " +
        to_string(userID);

    temp_query->insertData(STR_TO_WSTR(query));
}

string SQLManager::getAllUserData(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select * from Users where UserID = " + to_string(userID);
    return temp_query->makeRangedQuery(STR_TO_WSTR(query).c_str(), 1, 9);
}

bool SQLManager::authentifyUser(string mail_string, string password_string)
{
    int userID = getUserID(mail_string);
    if (userID == -1)
        return false;
    int seed = HASH->extractSeed(getPassword(userID));


    Query* temp_query = new Query;
    wstring query_wstring;

    query_wstring = L"select Email + PasswordHash from Users where Email = '"  +
        STR_TO_WSTR(mail_string) +
        L"' and PasswordHash = '" +
        STR_TO_WSTR(HASH->getPasswordHash(password_string, seed)) +
        L"'";

    string return_string = temp_query->makeCustomQuery(query_wstring.c_str(), 1);

    if (return_string.length() != mail_string.length() + HASH->getPasswordHash(password_string, seed).length() + 1) // +1 accounts for the space after the query ends
        return false;
    return true;
  
}

void SQLManager::insertNewStudent(string queryBuffer)
{
    Query* temp_query = new Query;
    string query;
    
    query = "USE Noodle INSERT INTO Users(UserRole, LastName, FirstName, Email, PasswordHash, StudyGroup, StudyYear, JoinDate) VALUES " +
        queryBuffer;

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::insertNonStudent(string queryBuffer)
{
    Query* temp_query = new Query;
    string query;

    query = "USE Noodle INSERT INTO Users(UserRole, LastName, FirstName, Email, PasswordHash, JoinDate) VALUES " +
        queryBuffer;

    temp_query->insertData(STR_TO_WSTR(query));
}

SQLManager::~SQLManager()
{
    destroyInstance();
    cout << "SQL Manager shutting down." << endl;
}