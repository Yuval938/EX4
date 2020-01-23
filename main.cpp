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

int main() {
    Server *server = new ParallelServer();
    ClientHandler *clientTest = new MyClientHandler(new MatrixSolver(new BestFirstSearch<pair<int, int>>()));
    server->open(5402, clientTest);
    return 0;
}