#include "UDPServer.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Server *server = new UDPServer("5001");
    server->testForStartupError();

    /* code */
    return 0;
}
