//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include <vector>
#include "Node.h"
#include "Searchable.h"
#include "State.h"

using namespace std;

// pair<int,int> will represent the position of state

class Matrix : public Searchable<pair<int, int>> {
    vector<vector<State<pair<int, int>> *>> matrix;
    State<pair<int, int>> *goalState;
    State<pair<int, int>> *initialState;
public:
    Matrix(vector<vector<State<pair<int, int>> *>> mat, State<pair<int, int>> *start, State<pair<int, int>> *end) {
        this->matrix = mat;
        this->initialState = start;
        this->goalState = end;
    }

    State<pair<int, int>> *getInitialState() {
        return this->initialState;
    }

    bool isGoalState(State<pair<int, int>> givenState) {
        pair<int, int> goalState = this->goalState->getState();
        pair<int, int> checkState = givenState.getState();

        return (goalState.first == checkState.first && goalState.second == checkState.second);
    }

    // returning neighbors
    vector<State<pair<int, int>> *> getAllPossibleStates(State<pair<int, int>> s) override {
        vector<State<pair<int, int>> *> neighbors;
        int i = s.getState().first;
        int j = s.getState().second;
        int size = this->matrix.size(); // it's nXn array so colsSize and rowSize are the same
        if (j + 1 < size) {
            // State<pair<int, int>> *s = this->matrix[i][j];
            neighbors.push_back(this->matrix[i][j + 1]); // Right
        }
        if (j - 1 >= 0) {
            neighbors.push_back(this->matrix[i][j - 1]); // Left
        }
        if (i - 1 >= 0) {
            neighbors.push_back(this->matrix[i - 1][j]); // Up
        }
        if (i + 1 < size) {
            neighbors.push_back(this->matrix[i + 1][j]); // Down
        }
        return neighbors;
    }

};


#endif //EX4_MATRIX_H
