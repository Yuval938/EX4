//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include <vector>
#include "Node.h"
#include "Searchable.h"

using namespace std;

class Matrix : public Searchable<Node<pair<int, int>> *> {
    vector<vector<Node<pair<int, int>> *>> Nodes;
    Node<pair<int, int>> *Target_Node;
    Node<pair<int, int>> *Starting_Node;
public:
    Matrix(vector<vector<Node<pair<int, int>> *>> Nodes1, Node<pair<int, int>> *start, Node<pair<int, int>> *end) {
        this->Nodes = Nodes1;
        this->Starting_Node = start;
        this->Target_Node = end;
    }

    Node<pair<int, int>> *getInitialState() {
        return this->Starting_Node;
    }

    bool isGoalState(Node<pair<int, int>> *givenStateNode) {
        pair<int, int> TN = this->Target_Node->getState();
        pair<int, int> GS = givenStateNode->getState();

        return (GS.first == TN.first && GS.second == TN.second);
    }

    vector<vector<Node<pair<int, int>> *>> getAllPossibleStates() override {
        return this->Nodes;
    }

};


#endif //EX4_MATRIX_H
