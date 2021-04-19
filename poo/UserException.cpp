#include "UserException.h"
UserException::UserException(string exceptionMessage) :
	AException("User Exception: " + exceptionMessage, 201)
{
}

UserException::~UserException()
{
}
