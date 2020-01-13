cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex4 main.cpp Searcher.cpp Searcher.h Problem.cpp Problem.h Solution.cpp Solution.h Searchable.cpp Searchable.h)