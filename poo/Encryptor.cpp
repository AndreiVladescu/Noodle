#include "Encryptor.h"

Encryptor* Encryptor::instance = nullptr;

Encryptor::Encryptor()
{

}

Encryptor::~Encryptor()
{
	deleteInstance();
}

Encryptor* Encryptor::getInstance()
{
	if (instance == nullptr)
		instance = new Encryptor;
	return instance;
}

void Encryptor::deleteInstance()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void Encryptor::encrypt(string& str)
{
	for (int index = 0; index < str.length(); index++) {
		str[index] += 13;
	}
}

void Encryptor::decrypt(string& str)
{
	for (int index = 0; index < str.length(); index++) {
		str[index] -= 13;
	}
}
