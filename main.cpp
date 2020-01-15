#include <iostream>
#include "Server.h"
#include "SerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "StringReverser.h"
#include "MyClientHandler.h"

int main() {
    Server *server = new SerialServer();
    ClientHandler* clientTest = new MyClientHandler();
    server->open(5600,clientTest);
    return 0;
}