#pragma once
#include "IClient.h"

class UDPClient : public IClient
{
private:
    int fdsock = -1;
    int errVal = -1;
    struct addrinfo *servAddr;
    struct sockaddr_storage fromAddr;
    int rc = -1;
    char *Txbuffer;

public:
    UDPClient(std::string port = "5000", std::string address = "");
    void sendMessage(void * message);
};