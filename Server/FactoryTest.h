#pragma once
#include "ITest.h"
#include "IUser.h"

class FactoryTest
{
public:
	static ITest* createTest(string testName, IUser* owner, vector<IUser*> toStudents, string testTime);
	static ITest* createTest(string testName, IUser* owner, string testTime);
	static ITest* createTest(string testName, string subjectName, string testTime);
};

