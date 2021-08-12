#ifndef CLIENTEXCEPTION_H
#define CLIENTEXCEPTION_H
#include "aexceptions.h"


class ClientException :
    public AExceptions
{
public:
    ClientException(string);


    virtual ~ClientException();
};
#endif // CLIENTEXCEPTION_H
