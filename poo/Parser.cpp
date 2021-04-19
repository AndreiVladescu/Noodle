#include "Parser.h"

Parser* Parser::instance = nullptr;

Parser::Parser()
{

}

Parser::~Parser()
{
    destroyInstance();
}

Parser* Parser::getInstance()
{
    if (instance == nullptr)
        instance = new Parser;
    return instance;
}

void Parser::destroyInstance()
{
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

vector<string> Parser::protocoliseString(int functionID, vector<string>& vectString)
{
    vectString.insert(vectString.begin(), 1, to_string(functionID));
    return vectString;
}

string Parser::parseString(vector<string> unparsedVectorOfStrings, char stringDelimiter)
{
    string parsedString;

    for (int index = 0; index < unparsedVectorOfStrings.size(); index++) {
        parsedString += unparsedVectorOfStrings[index];
        if (!(index == unparsedVectorOfStrings.size() - 1))
            parsedString += stringDelimiter;
    }

    return parsedString;
}

vector<string> Parser::unparseString(string parsedString, char stringDelimiter)
{
    vector <string> tokens;
    stringstream check1(parsedString);

    string intermediate;

    // Tokenizing  space ' '
    while (getline(check1, intermediate, stringDelimiter)){
        tokens.push_back(intermediate);
    }

    return tokens;
}
