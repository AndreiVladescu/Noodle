#include "AException.h"

AException::AException(string exceptionMessage
    , int exceptionCode) : p_exceptionCode(exceptionCode), p_exceptionMessage(exceptionMessage)
{

}

string AException::getMessage()
{
    return p_exceptionMessage;
}

int AException::getCode()
{
    return p_exceptionCode;
}

AException::~AException()
{
    p_exceptionMessage.erase();
    p_exceptionCode = 0;
}
