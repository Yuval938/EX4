//
// Created by yuval on 15/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include <vector>

using namespace std;
class MyClientHandler:public ClientHandler {
    Solver<std::string, std::string> *solver;
    //cache manage object
public:
    MyClientHandler() {
    }

    void handleClient(int clientsocket) override {
        vector<std::string> matrix;
        while(true) {
            char buffer[1024] = {0};
            int valread = read(clientsocket, buffer, 1024);
            std::string line = std::string(buffer);
            if(strcmp(line.c_str(),"end")==0){
                break;
            }
            matrix.push_back(line);

        }
            for(auto item=matrix.begin() ;item!=matrix.end();item++)
                cout<<*item<<endl;
    }

};


#endif //EX4_MYCLIENTHANDLER_H
