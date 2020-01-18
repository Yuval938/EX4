//
// Created by yuval on 13/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
    Solver<std::string, std::string> *solver;
public:
    MyTestClientHandler(Solver<std::string, std::string> *solver1) {
        this->solver = solver1;
    }

    void handleClient(int clientsocket) {
        char buffer[1024] = {0};
        int valread = read(clientsocket, buffer, 1024);
        std::string a = std::string(buffer);
        if (a.compare("end") != 0) {
            std::string r = solver->solve(a);
            int valsent = send(clientsocket, r.c_str(), r.size(), 0);
        } else {
            std::cout << "reached the \"end\" word" << std::endl;
        }
        //     out.write(r.c_str(),r.size());
    }
//cache manage object
};


#endif //EX4_MYTESTCLIENTHANDLER_H
