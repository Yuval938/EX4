//
// Created by yuval on 24/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H
#include <iostream>
#include "Server.h"
#include "SerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "StringReverser.h"
#include "MyClientHandler.h"
#include "MatrixSolver.h"
#include "Searcher.h"
#include "Searchable.h"
#include "BFS.h"
#include "Matrix.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "ParallelServer.h"
#include "DFS.h"
#include "MyCacheManager.h"
#include "Cachemanager.h"
namespace boot {
    class Main;
}

class boot :: Main{

public:
    Main(){};
    ~Main(){};
    int main(int arg) {
        Server *server = new ParallelServer();
        Cachemanager<string, string> *cache = new MyCacheManager();
        // cache->insert(123,"dassda");
        // Server *server = new SerialServer();
        ClientHandler *clientTest = new MyClientHandler(new MatrixSolver(new AStar<pair<int, int>>()),cache);
        server->open(arg, clientTest);
    };
};
#endif //EX4_BOOT_H