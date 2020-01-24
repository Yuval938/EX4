//
// Created by yuval on 15/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Matrix.h"
#include "Cachemanager.h"
#include <vector>

using namespace std;

class MyClientHandler : public ClientHandler {
    Solver<vector<string>, string> *solver;
    Cachemanager<string,string>* cm;
    hash<string> HashFunc;
public:

    MyClientHandler(Solver<vector<string>, string>* solver1,Cachemanager<string,string>* cache) {
        this->solver = solver1;
        this->cm = cache;
    }
    MyClientHandler (MyClientHandler const & a){
        this->solver = a.solver->clone();
        this->cm = a.cm;
    }

    MyClientHandler* clone()  override {
        return new MyClientHandler(*this);
    }

    /*
     * now we will transform the data into a object called matrix - the object will contain a list of nodes Objects
     * step 1 -  transform the data into a vector<vector<double>> - that will hold the matrix values and positions
     * step 2 - now we will scan this structure and for each value we will make a node with the information
     *          required and we will store it in a data structure (something like a vector probably)
     * step 3 - we will make a matrix object that contains the initial pos and the end pos
     *          and also a node data structure.
     */
    void handleClient(int clientsocket);
};


#endif //EX4_MYCLIENTHANDLER_H
