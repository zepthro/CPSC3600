#include "UDPServer.h"
#include "UDPClient.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }
    else
    {
        if ((argv[1][0] - '0') == 0)
        {
            IServer *server = new UDPServer("5000");
            server->testForStartupError();
            server->launchServer();
        }
        else
        {
            IClient *client = new UDPClient("5000", argv[1]);
            client->sendMessage((void *)"Hello");
        }
    }

    return EXIT_SUCCESS;
}
