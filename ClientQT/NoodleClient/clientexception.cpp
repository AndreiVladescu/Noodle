#include "clientexception.h"

ClientException::ClientException(string exceptionMessage) :
    AExceptions("Client Exception: " + exceptionMessage, 601)
{

}


ClientException::~ClientException()
{
}
