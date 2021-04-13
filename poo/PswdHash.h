#pragma once
#include <iostream>
#include <list>
using namespace std;
class PswdHash
{
private:
	static int seed;
	static PswdHash* instance;
	PswdHash();
	PswdHash(PswdHash* copyInstance) {};
	~PswdHash();
public:

	static unsigned long getPasswordHash(string unhashedPassword);

};


