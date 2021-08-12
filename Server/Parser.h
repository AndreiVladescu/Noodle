#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <sstream>

using namespace std;

class Parser
{
private:
	Parser();
	~Parser();
	Parser(Parser& copyInstance) = delete;

	static Parser* instance;
public:

	static Parser* getInstance();
	static void destroyInstance();

	vector<string> protocoliseString(int functionID, vector<string>& vectString); // process the vector so as to simplify my work ; adds int into first element
	string parseString(vector<string> unparsedVectorOfStrings, char stringDelimiter); //from vector of strings to parsed, i.e. : 1$my$protocol
	vector<string> unparseString(string parsedString, char stringDelimiter); // breaks down strings like 2$your$protocol into strings
	
};