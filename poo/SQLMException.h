#pragma once
#include "AException.h"
#include "SQLManager.h"
class SQLMException :
    public AException
{
public:
    SQLMException(string exceptionMessage);
    ~SQLMException();
};