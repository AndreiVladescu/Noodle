#define _CRT_SECURE_NO_WARNINGS
#include "TrustedTime.h"
#include<time.h>
#include <string>
#include<iostream>
using namespace std;
TrustedTime* TrustedTime::pInstance = nullptr;

TrustedTime::TrustedTime()
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer1[80];
	char buffer2[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer1, 80, "%D.", timeinfo);

	strftime(buffer2, 80, "%R.", timeinfo);

	char* p;
	p = strtok(buffer1, "/");
	luna = atoi(p);
	p = strtok(nullptr, "/");
	zi = atoi(p);
	p = strtok(nullptr, ".");
	an = atoi(p);

	char* q;
	q = strtok(buffer2, ":");
	ora = atoi(q);
	q = strtok(nullptr, ".");
	minut = atoi(q);
}


TrustedTime::~TrustedTime()
{
}

void TrustedTime::DestroyInstance()
{
	if (pInstance != nullptr)
		delete pInstance;
	pInstance = nullptr;
}

TrustedTime* TrustedTime::GetInstance()
{
	if (pInstance == nullptr)
		pInstance = new TrustedTime();
	return pInstance;
}


void TrustedTime::afisare_ora()
{
	cout << zi << "/" << luna << "/" << an << " " << ora << ":" << minut << endl;
}

void TrustedTime::adauga_ore()
{
	if (ora < 23)
	{
		ora++;
	}
	else if (ora == 23)
	{
		ora = 8;
		if (zi == 31)
		{
			if (luna == 12)
			{
				an++;
				luna = 1;
			}
			else
			{
				luna++;
			}
			zi = 1;
		}
		else
		{
			zi++;
		}
	}
}

string TrustedTime::get_ora_exacta()
{

	char buff1[50];
	_itoa(zi, buff1, 10);
	char buff2[3];
	_itoa(luna, buff2, 10);
	char buff3[10];
	_itoa(an, buff3, 10);
	char buff4[10];
	_itoa(ora, buff4, 10);
	char buff5[10];
	_itoa(minut, buff5, 10);
	strcat(buff1, "/");
	strcat(buff1, buff2);
	strcat(buff1, "/");
	strcat(buff1, buff3);
	strcat(buff1, "*");
	strcat(buff1, buff4);
	strcat(buff1, ":");
	strcat(buff1, buff5);
	strcat(buff1, "*");


	string x = buff1;

	return x;

}

string TrustedTime::get_time()
{
	char buff1[50];
	_itoa(zi, buff1, 10);
	char buff2[3];
	_itoa(luna, buff2, 10);
	char buff3[10];
	_itoa(an, buff3, 10);
	char buff4[10];
	_itoa(ora, buff4, 10);

	strcat(buff1, "/");
	strcat(buff1, buff2);
	strcat(buff1, "/");
	strcat(buff1, buff3);
	strcat(buff1, "*");
	strcat(buff1, buff4);


	string x = buff1;

	return x;

}

