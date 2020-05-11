#pragma once
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <netinet/in.h> /* for in_addr */
#include <arpa/inet.h>  /* for inet_addr ... */
#include <string>
#include <sys/types.h> /* getaddrinfo()*/
#include <netdb.h>
#include <memory.h> /* memset(...) */

class IClient
{
public:
    virtual void sendMessage(void *message) = 0;
    // virtual void confirmMessage();
};