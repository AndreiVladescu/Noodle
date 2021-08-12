#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include<stdio.h>
#include<string.h>

using namespace std;

class Parser
{
private:
    Parser();
    ~Parser();

    static Parser* instance;
public:
    static Parser* getInstance();
    static void destroyInstance();


    string parseString(vector<string>& unparsedVectorOfStrings,char stringDelimiter);
    vector<string > unparseString(string& parsedString, string delim);

};

#endif // PARSER_H
