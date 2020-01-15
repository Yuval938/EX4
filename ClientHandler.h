//
// Created by yuval on 13/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H
#include "Solver.h"
#include <sys/socket.h>
#include <string>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

//interface or abstract class
class ClientHandler
{
public:
    virtual void handleClient(int clientSocket) = 0;   //handleClient(InputStream,OutputStream)
};




#endif //EX4_CLIENTHANDLER_H
