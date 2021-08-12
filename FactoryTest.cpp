#include "FactoryTest.h"
#include "Test.h"
ITest* FactoryTest::createTest(string testName, IUser* owner, vector<IUser*> toStudents, string testTime)
{
    return new Test(testName, owner, toStudents, testTime);
}

ITest* FactoryTest::createTest(string testName, IUser* owner, string testTime)
{
    return new Test(testName, owner, testTime);
}

ITest* FactoryTest::createTest(string testName, string subjectName, string testTime)
{
    return new Test(testName, subjectName, testTime);
}
