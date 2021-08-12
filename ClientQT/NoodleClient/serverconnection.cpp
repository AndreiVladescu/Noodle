#include "serverconnection.h"
#include "encryptor.h"
#include "connmanagerexception.h"
#include "parser.h"

SOCKET serverConnection::m_ServerConnection; //conn
string serverConnection::m_StringReveived; //string recv
string serverConnection::m_StringToSend; //string sent


serverConnection::serverConnection()
{
    WSADATA wsaData;

    // Validate the parameters
        //if (argc != 2) {
           // printf("usage: %s server-name\n", argv[0]);
        //}

    // Initialize Winsock
        m_iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (m_iResult != 0) {
            printf("WSAStartup failed with error: %d\n", m_iResult);
            exit(0);
        }

        ZeroMemory(&m_hints, sizeof(m_hints));
        m_hints.ai_family = AF_UNSPEC;
        m_hints.ai_socktype = SOCK_STREAM;
        m_hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
        m_iResult = getaddrinfo(DEFAULT_IP, DEFAULT_PORT, &m_hints, &m_result);
        if (m_iResult != 0) {
            printf("getaddrinfo failed with error: %d\n", m_iResult);
            WSACleanup();
        }

        //clientPtr = this;
}

bool serverConnection::connectToServer()
{
    bool connected = false;

        // Attempt to connect to an address until one succeeds
        for (m_ptr = m_result; m_ptr != NULL; m_ptr = m_ptr->ai_next)
        {

            // Create a SOCKET for connecting to server
            m_ServerConnection = socket(m_ptr->ai_family, m_ptr->ai_socktype,
                m_ptr->ai_protocol);
            if (m_ServerConnection == INVALID_SOCKET) {
                printf("socket failed with error: %ld\n", WSAGetLastError());
                WSACleanup();
                return false;
            }

            // Connect to server.
            m_iResult = connect(m_ServerConnection, m_ptr->ai_addr, (int)m_ptr->ai_addrlen);
            if (m_iResult == SOCKET_ERROR)
            {
                std::cout << "Could not connect to server, error: " << WSAGetLastError() << std::endl;
                closesocket(m_ServerConnection);
                m_ServerConnection = INVALID_SOCKET;
                continue;
            }
            else
            {
                connected = true;
                break;

            }
        }

        return connected;
}

bool serverConnection::closeConnection()
{
    if (closesocket(m_ServerConnection == SOCKET_ERROR))
        {
            if (WSAGetLastError() == WSAENOTSOCK)
                return true;

            std::cout << "Failed to close the socket. Winsock Error: " << std::to_string(WSAGetLastError()) << std::endl;
            return false;
        }

    return true;
}

void serverConnection::sendMethod(vector<string> &v)
{
    Parser* p=Parser::getInstance();
    m_StringToSend = p->parseString(v,'$');
    sendStringToServer(m_StringToSend);
}

vector<string> serverConnection::recvMethod()
{
    Parser* p=Parser::getInstance();
    receiveStringFromServer(m_StringReveived);
    return(p->unparseString(m_StringReveived,"$"));
}

void serverConnection::sendStringToServer(string &value)
{
    int bufferLength = value.size();

    sendIntToServer(bufferLength);

    ENCRYPT->encrypt(value);

    int returnCheck = send(m_ServerConnection, value.c_str(), bufferLength, NULL);
    if (returnCheck == SOCKET_ERROR)
    {
        /*cout << "Failed to send message!Error code: " << WSAGetLastError() << endl;
        closesocket(m_ServerConnection);
        WSACleanup();
        exit(1);*/

        throw (IException*)new ConnManagerException("Packet loss");

        //return false;
    }
}

void serverConnection::receiveStringFromServer(string &value)
{
    int bufferLength = 0;
    receiveIntFromServer(bufferLength);

    char* buffer = new char[bufferLength + 1]; // +1 to allow for terminating '/0'
    buffer[bufferLength] = '\0';


    int returnCheck = recv(m_ServerConnection, buffer, bufferLength, NULL);
    value = buffer;
    delete[] buffer;


    if (returnCheck == SOCKET_ERROR)
        throw (IException*)new ConnManagerException("Packet loss");

    ENCRYPT->decrypt(value);

}

void serverConnection::sendIntToServer(int &value)
{
    int returnCheck = send(m_ServerConnection, (char*)&value, sizeof(int), NULL);
    if (returnCheck == SOCKET_ERROR)
        throw (IException*)new ConnManagerException("Packet loss");
}

void serverConnection::receiveIntFromServer(int &value)
{
    int returnCheck = recv(m_ServerConnection, (char*)&value, sizeof(int), NULL);
    if (returnCheck == SOCKET_ERROR)
        throw (IException*)new ConnManagerException("Packet loss");
}

void serverConnection::sendBoolToServer(bool &value)
{
    int returnCheck = send(m_ServerConnection, (char*)&value, sizeof(bool), NULL);
    if (returnCheck == SOCKET_ERROR)
        throw (IException*)new ConnManagerException("Packet loss");
}

void serverConnection::receiveBoolFromServer(bool &value)
{
    int returnCheck = recv(m_ServerConnection, (char*)&value, sizeof(bool), NULL);
    if (returnCheck == SOCKET_ERROR)
        throw (IException*)new ConnManagerException("Packet loss");
}


