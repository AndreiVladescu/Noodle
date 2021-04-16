#pragma once
#include <iostream>
#include <locale>
#include <codecvt>
#include <string>

#include "Query.h"

using namespace std;


#define STR_TO_WSTR(str) wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(str) //normal string to wide string convertor
#define WSTR_TO_STR(str) wstring_convert<codecvt_utf8<wchar_t>>().to_bytes(str); //wide string to normal string convertor

class SQLManager
{
private:
    SQLManager();
    ~SQLManager();
    SQLManager(SQLManager& copyInstance) = delete; // no access for another instance


    static SQLManager* instance;
    string makeRangedQuery(const wchar_t* query, int column_start, int column_finish);
    string makeCustomQuery(const wchar_t* query, int column); //E.g. query: "SELECT * FROM Employees", /// column e coloana pe care o vreau
 
    void destroyInstance();
public:

    static SQLManager* getInstance();

   
    string getAllUserNames();
    

    bool authentifyUser(string mail_string, string password_string);

    void insertNewStudent(string queryBuffer); //it must contain every column except UserID

   
};
