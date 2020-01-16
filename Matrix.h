//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include <vector>
#include "Node.h"
#include "Searchable.h"

using namespace std;

class Matrix:public Searchable<Node*> {
    vector<vector<Node *>> Nodes;
    Node *Target_Node = NULL;
    Node *Starting_Node = NULL;
public:
    Matrix(vector<vector<Node *>>& Nodes1, Node *start, Node *end) {
        this->Nodes = Nodes1;
        this->Starting_Node = start;
        this->Target_Node = end;
    }

    Node* getInitialState(){
        return this->Starting_Node;
    }
    bool isGoalState(Node* goalState){
        return false;
    }
    vector<vector<Node*>> getAllPossibleStates() override {
        return this->Nodes;
    }

};


#endif //EX4_MATRIX_H
