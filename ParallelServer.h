//
// Created by yuval on 21/01/2020.
//

#ifndef EX4_PARALLELSERVER_H
#define EX4_PARALLELSERVER_H

#include <vector>
#include <thread>
#include "Server.h"
#include "MyClientHandler.h"
using namespace std;
class ParallelServer : public Server {
    bool stayOpen = true;
    bool firstClient = false;
public:
    int open(int PORT, ClientHandler *cHandler) {
        //create socket
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            //error
            std::cerr << "Could not create a socket" << std::endl;
            return -1;
        }

        //bind socket to IP address
        // we first need to create the sockaddr obj.
        sockaddr_in address; //in means IP4
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
        address.sin_port = htons(PORT);
        //we need to convert our number
        // to a number that the network understands.

        //the actual bind command
        if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
            std::cerr << "Could not bind the socket to an IP" << std::endl;
            return -2;
        }

        //making socket listen to the port
        if (listen(socketfd, 100) == -1) { //can also set to SOMAXCON (max connections)
            std::cerr << "Error during listening command" << std::endl;
            return -3;
        } else {
            std::cout << "Server is now listening ..." << std::endl;
        }

        while (stayOpen) {
            // accepting a client
            sockaddr_in addressClient;
            int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                       (socklen_t *) &address);
            if(firstClient){
                struct timeval tv;
                tv.tv_usec = 0;
                tv.tv_sec = 120;
                setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
            }

            if (client_socket == -1) {
                std::cerr << "timeout occurred (TWO MINUTES WITHOUT A CONNECTION)" << std::endl;
                stop();
               // return -4;
            }
          //  ClientHandler* clientHandler = new MyClientHandler(cHandler);
          this->firstClient=true;
          ClientHandler* clone = cHandler->clone();
            std::thread t2(&ClientHandler::handleClient, clone, client_socket);
            t2.detach();
            // cHandler->handleClient(client_socket);
            // close(client_socket); //closing the listening socket


        }


    }
    void stop(){
        this->stayOpen = false;
    }
};




#endif //EX4_PARALLELSERVER_H
