#include "Profesor.h"

Profesor::Profesor(string userData) :
	AUser(userData)
{

}

Profesor::Profesor()
{
}

void Profesor::makeNewTest(string)
{

}

void Profesor::addQuestionToTest(IQuestion* quest, ITest* t)
{
}

void Profesor::printSubject()
{
	cout << subject;
}

Profesor::~Profesor()
{
}


