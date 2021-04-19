#pragma once
#include "AException.h"
#include "Test.h"
class TestException :
    public AException
{
public:
    TestException(string exceptionMessage);
    ~TestException();
};
