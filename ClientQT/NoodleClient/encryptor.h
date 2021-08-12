#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <iostream>

using namespace std;

class Encryptor // simple rot13 / Caesar's Cipher encryptor
{
private:
    Encryptor();
    ~Encryptor();
    Encryptor(Encryptor& copyInstance) = delete;


    static Encryptor* instance;

public:
    static Encryptor* getInstance();
    static void deleteInstance();

    void encrypt(string &str);
    void decrypt(string &str);
};

#endif // ENCRYPTOR_H
