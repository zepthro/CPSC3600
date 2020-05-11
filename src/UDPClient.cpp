#include "UDPClient.h"
#include <iostream>
UDPClient::UDPClient(std::string port, std::string address)
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
}
void UDPClient::sendMessage(void *message)
{
    Txbuffer = (char *)message;
    rc = sendto(fdsock, message, sizeof(message), 0, servAddr->ai_addr, servAddr->ai_addrlen);
    std::cout << "Message sent\n";
}