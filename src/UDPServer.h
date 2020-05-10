#include "Server.h"

class UDPServer : public Server
{
private:
    int fdsock = -1;
    int errVal = -1;
    struct addrinfo *servAddr;
    struct addrinfo addrCriteria; // Criteria for address

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