#include "connmanagerexception.h"

ConnManagerException::ConnManagerException(string exceptionMessage) :
    AExceptions("ConnManager Exception: " + exceptionMessage, 701)
{
}

ConnManagerException::~ConnManagerException()
{
}

