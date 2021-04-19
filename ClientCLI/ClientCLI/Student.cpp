#include "Student.h"

Student::Student(string userData):
		AUser(userData)
{
	//seteaza studyYear, studyGroup
}

Student::Student()
{

}

string Student::getStudentTests()
{
	
	return string();
}

void Student::seeGrades()
{
}

void Student::seeGradesPerSem()
{
}

void Student::seeTests()
{
}

void Student::answerTest(ITest*)
{
}

void Student::setStudyGroup(string newStudyGroup)
{
	studyGroup = newStudyGroup;
}

void Student::setStudyYear(int newStudyYear)
{
	studyYear = newStudyYear;
}

Student::~Student()
{

}


