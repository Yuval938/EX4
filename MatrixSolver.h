//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H

#include <string>
#include <algorithm>
#include <iostream>
#include "Solver.h"
#include "Matrix.h"
#include "Searcher.h"
#include <iomanip>

using namespace std;

class MatrixSolver : public Solver<vector<string>, string> {
    Searcher<Node<pair<int, int>> *, string> *searcher;

public:


    MatrixSolver(Searcher<Node<pair<int, int>> *, string> *searcher1) {
        this->searcher = searcher1;
    }

    int printPath(Node<pair<int, int>> *node) {

        if (node->getFather() == NULL) { // got to the first startP - let's print all
            return 0;
        }

        Node<pair<int, int>> *father = node->getFather();
        int stepsCount = 1 + printPath(father);

        pair<int, int> fatherState = father->getState();
        pair<int, int> currentState = node->getState();
        string relativity = "";

        if (currentState.second - fatherState.second == 1) { // currentX - fatherX == 1
            relativity = "Right";
        } else if (currentState.second - fatherState.second == -1) {
            relativity = "Left";
        } else if (currentState.first - fatherState.first == 1) {
            relativity = "Down";
        } else if (currentState.first - fatherState.first == -1) {
            relativity = "Up";
        }

        std::cout << stepsCount << ". " << relativity << " (" << node->getPathValue() << "), "
                  << std::flush;
        if (stepsCount % 15 == 0) { // make \n every 15 steps
            std::cout << std::endl;
        }

        return stepsCount;

    }

    string solve(vector<string> problem) override {
        vector<vector<Node<pair<int, int>> *>> matrixDouble;
        int matrixSize = problem.size();
        int i, j;
        for (i = 0; i < matrixSize - 2; i++) {
            string numString = "";
            int lineSize = problem[i].size();
            j = 0;
            vector<Node<pair<int, int>> *> lineVector;
            while (j < lineSize) {
                while (j < lineSize && problem[i].at(j) != ',') {
                    numString += problem[i].at(j);
                    j++;
                }
                double value = atof(numString.c_str());
                Node<pair<int, int>> *newNode = new Node<pair<int, int>>(value);
                newNode->setValue(value);
                lineVector.push_back(newNode);
                j++;
                numString = "";
            }

            if (lineVector.size() > 0) {
                matrixDouble.push_back(lineVector);
            }
        }

        for (i = 0; i < matrixDouble.size(); i++) {
            for (j = 0; j < matrixDouble[i].size(); j++) {
                pair<int, int> state;
                state.first = i;
                state.second = j;
                matrixDouble[i][j]->setState(state);
            }
        }

        string numString = "";
        int count = 0;
        int lineSize;
        int startX, startY, endX, endY;

        for (i; i < matrixSize; i++) {
            lineSize = problem[i].size();
            j = 0;
            while (j < lineSize) {
                while (j < lineSize && problem[i].at(j) != ',') {
                    numString += problem[i].at(j);
                    j++;
                }
                if (count < 4) {
                    double num = atof(numString.c_str());
                    numString = "";
                    j++;
                    if (count == 0) {
                        startX = num;
                    } else if (count == 1) {
                        startY = num;
                    } else if (count == 2) {
                        endX = num;
                    } else if (count == 3) {
                        endY = num;
                    }
                    count++;
                }
            }
        }


        int pos = i;
        int lines = matrixDouble.size();


        int numOfRows = matrixDouble.size();
        //adding negibours;
        for (int i = 0; i < numOfRows; i++) {
            int sizeOfCol = matrixDouble[i].size();
            for (int j = 0; j < sizeOfCol; j++) {
                if (j + 1 < sizeOfCol) {
                    //adds i,[j+1]  RIGHT
                    matrixDouble[i][j]->addNeighbor(matrixDouble[i][j + 1]);
                }
                if (j - 1 >= 0) {
                    //adds i,[j-1]  LEFT
                    matrixDouble[i][j]->addNeighbor(matrixDouble[i][j - 1]);
                }
                if (i - 1 >= 0) {
                    //adds i-1,[j]  UP
                    matrixDouble[i][j]->addNeighbor(matrixDouble[i - 1][j]);
                }
                if (i + 1 < numOfRows) {
                    //adds i+1,[j]  DOWN
                    matrixDouble[i][j]->addNeighbor(matrixDouble[i + 1][j]);
                }


            }

        }

        Node<pair<int, int>> *startP = matrixDouble[startY][startX];
        Node<pair<int, int>> *endP = matrixDouble[endY][endX];

        Searchable<Node<pair<int, int>> *> *matrixToSolve = new Matrix(matrixDouble, startP, endP);

        this->searcher->Search(matrixToSolve);

        printPath(endP); // print all path
        std::cout << std::endl; // go down line

        return "";
    }
};


#endif //EX4_MATRIXSOLVER_H
