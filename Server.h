//
// Created by yuval on 13/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H
#include "ClientHandler.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <exception>
//abstract class SERVER
//open(int port,ClientHandler)
//stop()
class Server {
public:
    virtual int open(int port, ClientHandler* c) = 0;
    virtual void stop() = 0;
};


#endif //EX4_SERVER_H
