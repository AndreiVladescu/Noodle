#pragma once
#include <string>
#include <iostream>
#include<vector>

using namespace std;
class IQuestion;

class ITest
{
public:
	virtual void printTest() = 0;
	virtual IQuestion* getQuestion() = 0;
	virtual void addQuestion(IQuestion* q) = 0;
	virtual void calculateMaxPoints() = 0;
	virtual void checkTest(string bufferClient) = 0;


	virtual void setSuppPoint(int x) = 0;
	virtual int getSuppPoint() = 0;
	virtual int getMaxPoints() = 0;
	
};

