#include "parser.h"

Parser* Parser::instance=nullptr;

Parser::Parser()
{

}

Parser::~Parser()
{
    destroyInstance();
}

Parser *Parser::getInstance()
{
    if(instance==nullptr)
        instance = new Parser;
    return instance;
}

void Parser::destroyInstance()
{
    if(instance!=nullptr)
    {
        delete instance;
        instance=nullptr;
    }
}

string Parser::parseString(vector<string>& unparsedVectorOfStrings, char stringDelimiter)
{
    string parsedString;
    for(int i=0;i<unparsedVectorOfStrings.size();i++)
    {
        parsedString+=unparsedVectorOfStrings[i];
        if(!(i==unparsedVectorOfStrings.size()-1))
            parsedString+=stringDelimiter;
    }
    return parsedString;

}

vector<string> Parser::unparseString(string& parsedString,string delim)
{
    /*vector<string> tokens;
    char delims[]= "$";

    char* p = new char[parsedString.size()+1];
    strcpy(p,parsedString.c_str());
    p=strtok(p,delims);
    while(p!=nullptr)
    {
        string aux(p);
        tokens.push_back(aux);
        p =strtok(NULL,delims);
    }
    return tokens;
    */

    vector<string> vectorTokens;
    string token = "";
    int i = 0;
    auto start = 0u;
    auto end = parsedString.find(delim);
    while (end != string::npos)
    {
        token = parsedString.substr(start, end - start);
        vectorTokens.push_back(token);
        start = end + delim.length();
        end = parsedString.find(delim, start);
    }
    token = parsedString.substr(start, end);
    vectorTokens.push_back(token);

    return vectorTokens;
}
