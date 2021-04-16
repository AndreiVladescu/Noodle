#include "Query.h"


Query::Query()
{

    //initializations
    sqlConnHandle = NULL;
    sqlStmtHandle = NULL;
    //allocations
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
        this->terminateQuery();
        return;
    }
    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
        this->terminateQuery();
        return;
    }
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
        this->terminateQuery();
        return;
    }
    //output
    cout << "Attempting connection to SQL Server...";
    cout << "\n";
    //connect to SQL Server  

    switch (SQLDriverConnect(sqlConnHandle,
        NULL,
        (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=Noodle;Trusted=true;", //Precizeaza baza de date / database-ul
        SQL_NTS,
        retconstring,
        1024,
        NULL,
        SQL_DRIVER_NOPROMPT)) {
    case SQL_SUCCESS:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;
    case SQL_SUCCESS_WITH_INFO:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;
    case SQL_INVALID_HANDLE:
        cout << "Could not connect to SQL Server";
        cout << "\n";
        this->terminateQuery();
        return;

    case SQL_ERROR:
        cout << "Could not connect to SQL Server";
        cout << "\n";
        this->terminateQuery();
        return;

    default:
        break;
    }
    //if there is a problem connecting then exit application
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle)) {
        this->terminateQuery();
    }
    return;
    //output
    cout << "\n";
    cout << "Executing T-SQL query...";
    cout << "\n";
}

string Query::getAllUserNames()
{
    return makeCustomQuery(L"SELECT FirstName + ' ' + LastName FROM Users", 1 , QueryDelimiter::NewLine);
}

string Query::makeRangedQuery(const wchar_t* query, int column_start, int column_finish, QueryDelimiter query_delimiter)
{
    char delimiter;
    initDelimiter(delimiter, query_delimiter);

    wstring ws;
    string return_buffer;
    ws += query;

    //if there is a problem executing the query then exit application
    //else display query result
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)ws.c_str(), SQL_NTS)) {
        cout << "Error querying SQL Server";
        cout << "\n";
        //this->terminateQuery();
        return NULL;
    }
    else {
        //declare output variable and pointer
        SQLCHAR sqlVersion[SQL_RESULT_LEN];

        SQLINTEGER ptrSqlVersion;
        while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
            //template pentru ciclarea mai multor coloane
            for (int index = column_start; index < column_finish; index++) {
                SQLGetData(sqlStmtHandle, index, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                return_buffer += (string((const char*)sqlVersion)) + delimiter;
            }

            //return_buffer += "\n";
        }
    }
    return return_buffer;
}

string Query::makeCustomQuery(const wchar_t* query, int column, QueryDelimiter query_delimiter)
{
    char delimiter;
    initDelimiter(delimiter, query_delimiter);

    //ws is the wide string used for queries
    wstring ws;
    string return_buffer;
    ws += query;

    //if there is a problem executing the query then exit application
    //else display query result
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)ws.c_str(), SQL_NTS)) {
        cout << "Error querying SQL Server";
        cout << "\n";
        //this->terminateQuery();
        return NULL;
    }
    else {
        //declare output variable and pointer
        SQLCHAR sqlVersion[SQL_RESULT_LEN];

        SQLINTEGER ptrSqlVersion;
        while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
            SQLGetData(sqlStmtHandle, column, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
            return_buffer += (string((const char*)sqlVersion)) + delimiter;
            //display query result
        }
    }
    return return_buffer;
   
}

void Query::insertData(wstring queryBuffer)
{
    SQLExecDirect(sqlStmtHandle,
        (SQLWCHAR*)queryBuffer.c_str(),
        SQL_NTS);
}

//void Query::insertNewStudent(wstring queryBuffer)
//{
//    wstring temp_wstring = L"USE Noodle INSERT INTO Users(LastName, FirstName, Email, PasswordHash, JoinDate, UserRole, StudyGroup, StudyYear) VALUES ";
//    temp_wstring += queryBuffer;
//
//    SQLExecDirect(sqlStmtHandle,
//        (SQLWCHAR*)temp_wstring.c_str(),
//        SQL_NTS);
//}

void Query::terminateQuery()
{
    //close connection and free resources
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

void Query::initDelimiter(char& delimiter, QueryDelimiter queryDelimiter)
{
    switch (queryDelimiter){
    case (QueryDelimiter::NewLine): {
        delimiter = '\n';
        break;
    }
    case (QueryDelimiter::Space): {
        delimiter = ' ';
        break;
    }
    default:
    {
        delimiter = ' ';
    }
    }
}

Query::~Query()
{
    //close connection and free resources
    this->terminateQuery();
}
