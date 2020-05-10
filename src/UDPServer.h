#pragma once
#include "IServer.h"
#include <iostream>

class UDPServer : public IServer
{
private:
    int fdsock = -1;
    int errVal = -1;
    int bindVal = -1;
    struct addrinfo *servAddr;
    struct sockaddr_storage fromAddr;
    int rc = -1;
    char *buffer;

public:
    /*
    @pre port >= 5000 and [address is valid IPv4 or IPv6] 

    default behavior: 
        address = "" assigns the address of the current host... (e.g., 192.168.*.*)
        port = "5000" in general assign port values >= 5000
    */
    UDPServer(std::string port = "5000", std::string address = "");
    void testForStartupError();
    void launchServer();
};