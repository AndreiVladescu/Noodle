#pragma once
#include <iostream>
#include <locale>
#include <codecvt>
#include <string>

#include "Query.h"
#include "PswdHash.h"
#include "Parser.h"

using namespace std;


#define STR_TO_WSTR(str) wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(str) //normal string to wide string convertor
#define WSTR_TO_STR(str) wstring_convert<codecvt_utf8<wchar_t>>().to_bytes(str); //wide string to normal string convertor

#define PARSER Parser::getInstance()
#define HASH PswdHash::getInstance()

class SQLManager
{
private:
    SQLManager();
    ~SQLManager();
    SQLManager(SQLManager& copyInstance) = delete; // no access for another instance

    string makeRangedQuery(const wchar_t* query, int column_start, int column_finish);
    string makeCustomQuery(const wchar_t* query, int column); //E.g. query: "SELECT * FROM Employees", /// column e coloana pe care o vreau
    

    void destroyInstance();

    static SQLManager* instance;

public:
    static SQLManager* getInstance();

    string getAllUserNames();
    int getUserRole(string uEmail);
    int getUserID(string uEmail);
    string getFullUserName(int userID);
    string getUserFirstName(int userID);
    string getUserLastName(int userID);
    string getUserEmail(int userID);
    string getUserJoinedDate(int userID);
    int getUserStudyYear(int userID);
    string getUserStudyGroup(int userID);
    string getPassword(int userID);
    string getTestName(int testID);
    string getTestDate(int testID);
    string getAllAnswers();
    string getAnswersOfQuestion(int questionID);
    string getAnswersOfQuestionWithTruthness(int questionID);
    float getQuestionPoints(int questionID);
    float getTestPoints(int testID);
    string getSubjectOfProfessor(int userID);
    string getAllSubjects();
    int getSubjectID (string subjectName);
    int getLastTestIDofSubject(string subjectName);
    int getLastQuestionID();
    int getLastTestID();
    vector<pair<string, int>> getStudentGrades(int userID);
    vector<string> getStudentsGradesPerStudyGroup(string studyGroup, string subjectName);
    //string getQuestionBody(i)
    vector<string> provideTestsForLoading();
    vector<string> provideQuestionsForLoading(int testID);
    vector<string> provideAnswersForLoading(int QuestionID);
    int getNumberOfAnswersOfAQuestion(int questionID);
    string getSubjectName(int subjectID);
    vector<string> getAssignedStudyGroups(int testID);
    vector<int> getAssignedStudents(int testID);
    vector<string> getRegisteredUsers();

    void deleteUser(int userID);
    bool isMailAlreadyUsed(string email);
    void assignTo(int testID, int userID);
    void assignTo(int testID, string studyGroup);
    void modifyGradeOfStudent(int userID, string subjectName, int grade);
    void insertNewGrade(int userID, string subjectName, int grade);
    void makeProfessorOfSubject(int userID, string subjectName);
    void insertNewSubject(string SubjectName);
    void insertNewTest(string subjectName, string testName, string inboundDate, int timeToComplete);
    void insertNewQuestion(int testID, string questionBody, float points);
    void insertNewAnswer(int questionID, string answer, int truthness = -1);
    void setQuestionPoints(int questionID, float points);
    void setTestDate(int testID, string date);
    void setUserPassword(int userID, string newPassword);
    string getAllUserData(int userID);
    bool authentifyUser(string mail_string, string password_string);
    void insertNewStudent(string queryBuffer); //it must contain every column except UserID
    void insertNonStudent(string queryBuffer); // clone after insertNewStudent, without  StudyGroup, StudyYear
};
