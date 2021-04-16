#pragma once
#include "AException.h"
#include "IServer.h"
class ServerException :
    public AException
{
public:
    ServerException(string exceptionMessage);
    ~ServerException();
};