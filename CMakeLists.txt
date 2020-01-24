cmake_minimum_required(VERSION 3.15)
project(EX4)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(EX4 main.cpp MyTestClientHandler.h MyTestClientHandler.cpp SerialServer.h SerialServer.cpp Server.h Solver.h StringReverser.h StringReverser.cpp MyClientHandler.h MyClientHandler.cpp Matrix.h MatrixSolver.cpp MatrixSolver.h BFS.cpp BFS.h ClientHandler.h Searchable.h Searchable.cpp Searcher.h Searcher.cpp State.cpp State.h BestFirstSearch.cpp BestFirstSearch.h AStar.cpp AStar.h ISearcher.cpp ISearcher.h ParallelServer.h ParallelServer.cpp DFS.cpp DFS.h Cachemanager.cpp Cachemanager.h MyCacheManager.cpp MyCacheManager.h)

