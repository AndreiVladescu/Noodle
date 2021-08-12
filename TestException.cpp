#include "TestException.h"

TestException::TestException(string exceptionMessage) :
	AException("Test Exception: " + exceptionMessage, 101)
{
}

TestException::~TestException()
{
}
