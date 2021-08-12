#pragma once
#include <iostream>

using namespace std;

class IException
{
public:
	virtual std::string getMessage() = 0;
	virtual int getCode() = 0;
};