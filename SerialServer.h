//
// Created by yuval on 13/01/2020.
//

#ifndef EX4_SERIALSERVER_H
#define EX4_SERIALSERVER_H
#include "Server.h"
class SerialServer: public Server {
int open(int PORT, ClientHandler* cHandler);
void stop(){}
};


#endif //EX4_SERIALSERVER_H
