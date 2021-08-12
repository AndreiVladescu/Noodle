#pragma once
#include "AException.h"

class UserException :
    public AException
{
    UserException(string exceptionMessage);
    ~UserException();
};

