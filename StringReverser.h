//
// Created by yuval on 15/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include <algorithm>
#include "Solver.h"
#include <string>

class StringReverser : public Solver<std::string, std::string> {
public:
    std::string solve(std::string problem) override {

        std::reverse(problem.begin(), problem.end());
        return problem;
    }
};


#endif //EX4_STRINGREVERSER_H
