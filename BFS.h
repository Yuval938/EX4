//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H


#include <queue>
#include <iostream>
#include "Searcher.h"
//#include "Node.h"

using namespace std;

template<typename T>
class BFS : public Searcher<T> {
    queue<State<T> *> Q;

public:
    void Search(Searchable<T> *matrix) override {

        State<T> *initialState = matrix->getInitialState();
        initialState->setCost(0);
        initialState->setColor('g');
        Q.push(initialState);
        while (!Q.empty()) {
            State<T> *u = Q.front(); // Node *u = Q.pop()
            Q.pop();
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                if (adj[i]->getColor() == 'w') {
                    adj[i]->setColor('g');
                    adj[i]->setCameFrom(u);
                    adj[i]->setCost(u->getCost() + u->getValue());
                    Q.push(adj[i]);
                }
            }
            u->setColor('b');

        }
    }

};


#endif //EX4_BFS_H
