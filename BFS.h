//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H


#include <queue>
#include <iostream>
#include "Searcher.h"
#include "Node.h"

using namespace std;

class BFS : public Searcher<Node *, string> {
    queue<Node *> Q;

public:
    string Search(Searchable<Node *> *matrix) override {
        int counter = 0;
        Node *startingN = matrix->getInitialState();
        vector<vector<Node *>> map = matrix->getAllPossibleStates();
        startingN->setPathValue(0);
        startingN->setColor('g');
        Q.push(startingN);
        while (!Q.empty()) {
            Node *u = Q.front();
            Q.pop();
            auto adj = u->getNeighbors();
            int size = u->GetNumOfNeighbors();
            for (int i = 0; i < size; i++) {
                if (adj[i]->getColor() == 'w') {
                    adj[i]->setColor('g');
                    adj[i]->setFather(u);
                    adj[i]->setPathValue(u->getPathValue() + u->getValue());
                    Q.push(adj[i]);
                }
            }
            u->setColor('b');
            counter++;
        }
        std::cout << "result is    " + to_string(matrix->getAllPossibleStates()[36][36]->getPathValue())<<std::endl;
        std::cout<<to_string(counter)<<std::endl;
    }


};


#endif //EX4_BFS_H
