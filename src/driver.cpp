#include "UDPServer.h"
#include "UDPClient.h"
#include <iostream>
void usuage()
{
    std::cout << "UDP Server/Client Program.\n"
              << "./UDP server <optional port>\n"
              << "./UDP client <optional server> <port of server>\n";
    exit(EXIT_FAILURE);
}
int main(int argc, char const *argv[])
{
    std::string message;
    if (argc >= 2)
    {
        if (std::string(argv[1]) == "server")
        {
            IServer *server = NULL;
            std::string port = (argc == 3) ? argv[2] : "";
            if (port.length())
            {
                server = new UDPServer(port);
            }
            else
            {
                server = new UDPServer();
            }
            server->testForStartupError();
            server->launchServer();
        }
        else if (std::string(argv[1]) == "client")
        {
            IClient *client = NULL;
            if (argc == 4)
            {
                std::string port = argv[3];
                std::string server = argv[2];
                client = new UDPClient(port, server);
                client->sendMessage((void *)message.c_str());
            }
            else if (argc == 3)
            {
                std::string port = argv[2];
                client = new UDPClient(port);
                client->sendMessage((void *)message.c_str());
            }
            else
            {
                usuage();
            }
        }
        else
        {
            usuage();
        }
    }
    else
    {
        usuage();
    }
    return EXIT_SUCCESS;
}
