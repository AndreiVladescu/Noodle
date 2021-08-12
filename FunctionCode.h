#pragma once
enum class FunctionCode
{
	SendClientAllUserData = 1,
	InsertNewTest = 2,
	InsertNewUser = 3,
	SendClientTestList = 4,
	ChangeUserPassword = 5,
	InsertNewQuestion = 6,
	InsertNewGrade = 7,
	SendClientHisGrades = 8,
	SendAllOnlineClients = 9,
	ModifyGradeOfStudent = 10,
	SendProfessorHisSubject = 11,
	SendClientStatistics = 12,
	SendClientGradesPerStudyGroup = 13,
	AssignTestToStudent = 14,
	AssignTestToStudyGroup = 15,
	SendProfessorTests = 16,
	Authentify = 17,
	MakeProfessorOwnerOfSubject = 18,
	LogoutUser = 19,
	SendAllRegisteredUsers = 20,
	DeleteUser = 21
};