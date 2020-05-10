#pragma once
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <netinet/in.h> /* for in_addr */
#include <arpa/inet.h>  /* for inet_addr ... */
#include <string>
#include <sys/types.h> /* getaddrinfo()*/
#include <netdb.h>
#include <memory.h> /* memset(...) */
const int MAX_BUFFER_SIZE = 520028;

class IServer
{
public:
    // virtual void summaryStatistics() = 0;
    // virtual void packBuffer(void *buffer, void *bufferPtr, void *message) = 0;
    virtual void testForStartupError() = 0;
    virtual void launchServer() = 0;
    void DieWithError(char *errorMessage) /* External error handling function */
    {
        perror(errorMessage);
        exit(1);
    }
};