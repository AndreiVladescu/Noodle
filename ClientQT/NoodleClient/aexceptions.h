#ifndef AEXCEPTIONS_H
#define AEXCEPTIONS_H

#include "IException.h"

class AExceptions :
    IException
{
protected:
    string p_exceptionMessage;
    int p_exceptionCode;

public:
    AExceptions(string, int);

    string getExceptionMessage();
    int getExceptionCode();

    virtual ~AExceptions();
};

#endif // AEXCEPTIONS_H
