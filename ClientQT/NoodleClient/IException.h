#ifndef IEXCEPTION_H
#define IEXCEPTION_H

#include<iostream>

using namespace std;

class IException
{
public:
    virtual string getExceptionMessage() = 0;
    virtual int getExceptionCode() = 0;

};

#endif // IEXCEPTION_H
