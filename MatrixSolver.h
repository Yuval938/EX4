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
#include "State.h"

using namespace std;


class MatrixSolver : public Solver<vector<string>, string> {
    Searcher<pair<int, int>> *searcher;
    string returnString = "";
public:


    MatrixSolver(Searcher<pair<int, int>> *searcher1) {
        this->searcher = searcher1;
    }

    MatrixSolver(MatrixSolver const &a) {
        this->searcher = a.searcher->clone();
    }

    MatrixSolver *clone() const        // Virtual constructor (copying)
    {
        return new MatrixSolver(*this);
    }


    int printPath(State<pair<int, int>> *state) {
        if (state->getCameFrom() == NULL) { // got to the first startP - let's print all
            return 0;
        }

        State<pair<int, int>> *father = state->getCameFrom();
        int stepsCount = 1 + printPath(father);

        pair<int, int> fatherState = father->getState();
        pair<int, int> currentState = state->getState();
        string relativity = "";

        if (currentState.second - fatherState.second == 1) {
            relativity = "Right";
        } else if (currentState.second - fatherState.second == -1) {
            relativity = "Left";
        } else if (currentState.first - fatherState.first == 1) {
            relativity = "Down";
        } else if (currentState.first - fatherState.first == -1) {
            relativity = "Up";
        }

        //std::cout << relativity << " (" << state->getCost() << ") ," << std::flush;
        //this->returnString += to_string(stepsCount) + ". ";
        this->returnString += relativity + " (" + std::to_string((int) state->getCost()) + ") ,";
        return stepsCount;
    }

    string solve(vector<string> problem) override {
        vector<vector<double>> doubleMatrix;
        int matrixSize = problem.size();
        int i, j;
        for (i = 0; i < matrixSize - 2; i++) {
            string numString = "";
            int lineSize = problem[i].size();
            j = 0;
            vector<double> lineVector;
            while (j < lineSize) {
                while (j < lineSize && problem[i].at(j) != ',') {
                    numString += problem[i].at(j);
                    j++;
                }
                double value = atof(numString.c_str());
                // State<pair<int, int>> *state = new State<pair<int, int>>(value);
                // state->setCost(value);
                lineVector.push_back(value);
                j++;
                numString = "";
            }

            if (lineVector.size() > 0) {
                doubleMatrix.push_back(lineVector);
            }
        }

        // got all values in doubles array
        // now we need it in states matrix

        int doubleMatrixSize = doubleMatrix.size();
        vector<vector<State<pair<int, int>> *>> matrix;
        for (i = 0; i < doubleMatrixSize; i++) {
            vector<State<pair<int, int>> *> matrixLine;
            for (j = 0; j < doubleMatrix[i].size(); j++) {
                pair<int, int> state;
                state.first = i;
                state.second = j;
                int value = doubleMatrix[i][j];
                State<pair<int, int>> *newState = new State<pair<int, int>>(state);
                newState->setValue(value);
                matrixLine.push_back(newState);
            }
            matrix.push_back(matrixLine);
        }

        // to print the matrix
        /*
         *
         * for (i = 0; i < doubleMatrixSize; i++) {
            for (j = 0; j < doubleMatrix[i].size(); j++) {
                cout << setw(2);
                cout << matrix[i][j]->getValue() << " " << flush;
            }
            cout << endl;
        }
         */

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


        State<pair<int, int>> *startP = matrix[startY][startX];
        State<pair<int, int>> *endP = matrix[endY][endX];


        Searchable<pair<int, int>> *matrixToSolve = new Matrix(matrix, startP, endP);


        int numOfNodesVisited = this->searcher->Search(matrixToSolve);
        cout << setw(20);
        std::cout << "numOfNodesVisited: " << numOfNodesVisited << std::flush;
        cout << setw(15);
        std::cout << " total cost: " << endP->getCost() << std::endl;

        int stepsCount = printPath(endP); // print all path
        // st = myString.substr(0, myString.size()-1);
        this->returnString = this->returnString.substr(0, this->returnString.size() - 2); // to remove ", "
        // std::cout << this->returnString << endl;
        return this->returnString + "\n";
    }


};


#endif //EX4_MATRIXSOLVER_H
