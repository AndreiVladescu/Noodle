#ifndef CONNMANAGEREXCEPTION_H
#define CONNMANAGEREXCEPTION_H

#include "aexceptions.h"
class ConnManagerException :
    public AExceptions
{
public:
    ConnManagerException(string exceptionMessage);
    ~ConnManagerException();
};
#endif // CONNMANAGEREXCEPTION_H
