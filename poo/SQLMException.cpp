#include "SQLMException.h"
SQLMException::SQLMException(string exceptionMessage) :
	AException("SQL Manager Exception: " + exceptionMessage, 501)
{
}

SQLMException::~SQLMException()
{
}
