#include "PongServer.h"

using namespace PongGame;
int main()
{
    int port = 6000;
    PongServer *server = new PongServer(port);

    server->Start();
};