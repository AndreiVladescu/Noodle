#include "ServerException.h"

ServerException::ServerException(string exceptionMessage) :
	AException("Server Exception: " + exceptionMessage, 401)
{
}

ServerException::~ServerException()
{
}
