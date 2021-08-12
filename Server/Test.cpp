#include "Test.h"

Test::Test(string testName, IUser* owner, vector<IUser*> toStudents, string testTime) :
	ProfessorOwner(owner), students(toStudents), name(testName), time(testTime)
{
	
}

Test::Test(string testName, IUser* owner, string testTime) :
	ProfessorOwner(owner), name(testName), time(testTime)
{

}

Test::Test(string testName, string subjectName, string testTime) :
	name(testName), time(testTime), subject(subjectName)
{
	ProfessorOwner = nullptr;
}

float Test::calculateMaxPoints()
{
	float sum = 0;
	for (int index = 0; index < questions.size(); index++) {
		sum += questions[index]->getPoints();
	}
	return sum;
}

bool Test::isStudentPartOf(IUser* student)
{
	for (int index = 0; index < students.size(); index++)
		if (student->getUserID() == students[index]->getUserID())
			return true;
	return false;
}

void Test::assignTo(vector<string> studyGroups)
{
	assignedStudyGroups.insert(assignedStudyGroups.end(),
		make_move_iterator(studyGroups.begin()),
		make_move_iterator(studyGroups.end())
	);
}

void Test::assignTo(vector<int> studentIDs)
{
	assignedStudents.insert(assignedStudents.end(),
		make_move_iterator(studentIDs.begin()),
		make_move_iterator(studentIDs.end())
	);
}
