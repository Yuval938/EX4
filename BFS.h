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

template <typename T>
class BFS : public Searcher<Node<T> *, string> {
    queue<Node<T> *> Q;

public:
    void Search(Searchable<Node<T> *> *matrix) override {

        Node<T> *startingN = matrix->getInitialState();
        vector<vector<Node<T> *>> map = matrix->getAllPossibleStates();
        startingN->setPathValue(0);
        startingN->setColor('g');
        Q.push(startingN);
        while (!Q.empty()) {
            Node<T> *u = Q.front(); // Node *u = Q.pop()
            Q.pop();
            auto adj = u->getNeighbors();
            int numOfNeighbors = u->GetNumOfNeighbors();
            for (int i = 0; i < numOfNeighbors; i++) {
                if (adj[i]->getColor() == 'w') {
                    adj[i]->setColor('g');
                    adj[i]->setFather(u);
                    adj[i]->setPathValue(u->getPathValue() + u->getValue());
                    Q.push(adj[i]);
                }
            }
            u->setColor('b');

        }

    }



};


#endif //EX4_BFS_H
