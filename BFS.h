//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H


#include <queue>
#include <iostream>
#include "Searcher.h"
#include <unordered_set>

using namespace std;

template<typename T>
class BFS : public Searcher<T> {
    queue<State<T> *> Q;
    unordered_set<State<T> *> closed; // to keep track on states we visited already

public:
    bool foundInClosed(State<T> *state) {
        return (closed.count(state));
    }
    void Search(Searchable<T> *matrix) override {

        State<T> *initialState = matrix->getInitialState();
        initialState->setCost(0);
        closed.insert(initialState);
        Q.push(initialState);
        while (!Q.empty()) {
            State<T> *u = Q.front(); // Node *u = Q.pop()
            Q.pop();
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                if (!this->foundInClosed(adj[i])) {
                    closed.insert(adj[i]);
                    adj[i]->setCameFrom(u);
                    adj[i]->setCost(u->getCost() + u->getValue());
                    Q.push(adj[i]);
                }
            }
        }
    }

};


#endif //EX4_BFS_H
