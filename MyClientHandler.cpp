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
    vector<std::string> matrixStringVector;
    string line = "";
    string matrixAsString = "";
    while (flag) {
        char buffer[1024] = {0};
        read(clientsocket, buffer, 1024);
        string check = string(buffer);
        for (int i = 0; i < 1024; i++) {
            if (buffer[i] == '\n') {
                matrixStringVector.push_back(line);
                matrixAsString+=line;
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
    string key = to_string(this->HashFunc(matrixAsString));
    string result = cm->get(key);
    string noSolution = "";
    if(result==noSolution) {
        cout<<"using solver"<<endl;
         result = this->solver->solve(matrixStringVector);
        cm->insert(key,result);
    }else{
        cout<<"not using solver"<<endl;
    }
    send(clientsocket, result.c_str(), result.size(), 0);
}




