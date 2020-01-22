//
// Created by yuval on 15/01/2020.
//

#include "MyClientHandler.h"
#include "Matrix.h"

void replaceAll(std::string &str, const std::string &from, const std::string &to) {
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

void MyClientHandler::handleClient(int clientsocket) {
    bool flag = true;
    vector<std::string> matrixString;
    string line = "";
    while (flag) {
        char buffer[1024] = {0};
        read(clientsocket, buffer, 1024);
        string check = string(buffer);
        for (int i = 0; i < 1024; i++) {
            if (buffer[i] == '\n') {
                matrixString.push_back(line);
                line = "";
            } else {
                if (buffer[i] == 0) {
                    line = "";
                    break;
                }
                if(buffer[i] == 'e'){
                    flag = false;
                    break;
                }
                line += buffer[i];
            }
        }
    }
    string result = this->solver->solve(matrixString);
    send(clientsocket, result.c_str(), result.size(), 0);
}




