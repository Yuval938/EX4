//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H

#include <string>
#include <algorithm>
#include "Solver.h"
#include "Matrix.h"
#include "Searcher.h"

using namespace std;
class MatrixSolver : public Solver<vector<string>,string> {
    Searcher<Node*,string>* searcher;
public:


    MatrixSolver(Searcher<Node*,string>* searcher1){
        this->searcher = searcher1;
    }
    string solve(vector<string> problem) override {
        vector<vector<Node *>> matrixDouble;
        int matrixSize = problem.size();
        int i;
        for (i = 0; i < matrixSize - 2; i++) {
            string numString = "";
            int j = 0, lineSize = problem[i].size();
            vector<Node *> lineVector;
            while (j < lineSize) {
                while (j < lineSize && problem[i].at(j) != ',') {
                    numString += problem[i].at(j);
                    j++;
                }
                double num = atof(numString.c_str());
                lineVector.push_back(new Node(num));
                j++;
                numString = "";
            }

            if (lineVector.size() > 0) {
                matrixDouble.push_back(lineVector);
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

        Searchable<Node*>* X =  new Matrix(matrixDouble, matrixDouble[0][0], matrixDouble[36][36]);
        return this->searcher->Search(X);

    }
};



#endif //EX4_MATRIXSOLVER_H
