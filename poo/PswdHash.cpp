#include "PswdHash.h"

#define SIZE 1000000000 //9 cifre

PswdHash* PswdHash::instance = 0;
int PswdHash::seed = 131; //setare de seed

PswdHash::PswdHash()
{
}

unsigned long PswdHash::getPasswordHash(string unhashedPassword)
{
	unsigned long hash = 0;
	for (int i = 0; i < unhashedPassword.length(); i++)
	{
		hash = (hash * seed) + unhashedPassword[i];
	}
	return hash % SIZE;
}

PswdHash::~PswdHash()
{
}
