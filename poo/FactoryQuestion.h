#pragma once

class IQuestion;

class FactoryQuestion
{
public:
	static IQuestion* CreateNewQuestion();

};

