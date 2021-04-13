#pragma once
#include "IException.h"
class AException :
    public IException
{
private:
    string p_exceptionMessage;
    int p_exceptionCode;
public:
    AException(string exceptionMessage
        , int exceptionCode);

    string getMessage() override;
    int getCode() override;

    virtual ~AException();
};