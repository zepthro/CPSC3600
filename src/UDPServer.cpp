#include "UDPServer.h"

void UDPServer::launchServer()
{
    buffer = new char[MAX_BUFFER_SIZE];
    while (1)
    {
        socklen_t fromAddrlen = sizeof(fromAddr);
        rc = recvfrom(fdsock, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&fromAddr, &fromAddrlen);
        std::cout << "From user ";
        struct sockaddr_in messAddr = *(struct sockaddr_in *)&fromAddr;
        std::cout << inet_ntoa(messAddr.sin_addr);
        std::cout << ": " << buffer << "\n";
    }
}

UDPServer::UDPServer(std::string port, std::string address)
{
    struct addrinfo addrCriteria;                   // Criteria for address
    memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure
    addrCriteria.ai_family = AF_UNSPEC;             // Any address family
    addrCriteria.ai_flags = AI_PASSIVE;             // Accept on any address/port
    addrCriteria.ai_socktype = SOCK_DGRAM;          // Only datagram socket
    addrCriteria.ai_protocol = IPPROTO_UDP;         // Only UDP socket
    /*
        This function call assigns all the possible address for the given
        port and ip address
    */
    errVal = getaddrinfo((address.length() ? address.c_str() : NULL), port.c_str(), &addrCriteria, &servAddr);
    fdsock = socket(servAddr->ai_family, servAddr->ai_socktype, servAddr->ai_protocol);
    bindVal = bind(fdsock, servAddr->ai_addr, servAddr->ai_addrlen);
    free(servAddr);
}

void UDPServer::testForStartupError()
{
    std::string errorMessage;
    if (errVal < 0)
    {
        errorMessage = "client: failed getaddrinfo, " + std::string(gai_strerror(errVal));
        DieWithError((char *)errorMessage.c_str());
    }

    if (fdsock < 0)
    {
        errorMessage = "socket bind failed. Use different port";
        DieWithError((char *)errorMessage.c_str());
    }

    if (bindVal < 0)
    {
        errorMessage = "bind() failed";
    }
}