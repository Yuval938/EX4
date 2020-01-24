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

int main(int argc, char *argv[]) {
    int port = 5402;
    if(argc > 0) {
        port = atoi(argv[1]); // assuming that the only arg i'll get will be a port number
    }
    Server *server = new ParallelServer();
    ClientHandler *clientTest = new MyClientHandler(new MatrixSolver(new BestFirstSearch<pair<int, int>>()));
    server->open(port, clientTest);
    return 0;
}