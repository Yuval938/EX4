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
    vector<std::string> matrixString;
    while (true) {
        char buffer[1024] = {0};
        int valread = read(clientsocket, buffer, 1024);
        std::string line = std::string(buffer);
        if (strcmp(line.c_str(), "end") == 0) {
            break;
        }
        matrixString.push_back(line);
    }
    string result = this->solver->solve(matrixString);
    int valsent = send(clientsocket, result.c_str(), result.size(), 0);
}




