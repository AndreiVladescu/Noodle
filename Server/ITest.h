#pragma once
#include <string>
#include <iostream>
#include<vector>
#include "IQuestion.h"
#include "IUser.h"

using namespace std;

class ITest
{
public:
	virtual void printTest() = 0;
	virtual bool isStudentPartOf(IUser* student) = 0;

	virtual  vector <IQuestion*> getQuestions() = 0;
	virtual void addQuestion(IQuestion* q) = 0;
	virtual float calculateMaxPoints() = 0;
	virtual void setTime(string testTime) = 0;
	virtual void setID(int newID) = 0;
	virtual void setSubject(string subject) = 0;
	virtual void setNumberOfQuestions(int number) = 0;
	virtual void assignTo(string studyGroup) = 0;
	virtual void assignTo(int userID) = 0;
	virtual void assignTo(vector<string> studyGroups) = 0;
	virtual void assignTo(vector<int> studentIDs) = 0;
	virtual void setTimeToComplete(int time) = 0;

	virtual int getTimeToComplete() = 0;
	virtual vector<int> getAssignedStudents() = 0;
	virtual vector<string> getAssignedStudyGroups() = 0;
	virtual int getNumberOfStudents() = 0;
	virtual int getNumberOfStudyGroups() = 0;
	virtual int getNumberOfQuestions() = 0;
	//virtual vector <IQuestion*> getQuestions() = 0;
	virtual int getID() = 0;
	virtual string getTime() = 0;
	virtual void setSuppPoints(float x) = 0;
	virtual float getSuppPoints() = 0;
	virtual float getMaxPoints() = 0;
	virtual string getSubject() = 0;
	virtual string getName() = 0;
};

