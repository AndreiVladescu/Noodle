#include "aexceptions.h"

AExceptions::AExceptions(string exceptionMessage, int exceptionCode) :
    p_exceptionCode(exceptionCode), p_exceptionMessage(exceptionMessage)
{

}

string AExceptions::getExceptionMessage()
{
    return p_exceptionMessage;
}

int AExceptions::getExceptionCode()
{
    return p_exceptionCode;
}

AExceptions::~AExceptions()
{
    p_exceptionCode = 0;
    p_exceptionMessage.erase();
}
