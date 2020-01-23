//
// Created by yuval on 23/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include <stack>
#include <iostream>
#include "Searcher.h"

using namespace std;

template<typename T>
class DFS : public Searcher<T> {
    stack<State<T> *> S;
public:
    DFS() {

    }

    DFS(DFS const &) {

    }

    DFS *clone() const        // Virtual constructor (copying)
    {
        return new DFS(*this);
    }

    int Search(Searchable<T> *matrix) override {

        State<T> *initialState = matrix->getInitialState();
        S.push(initialState);
        this->closed.insert(initialState);
        while (!S.empty()) {
            State<T> *u = S.top(); // Node *u = Q.pop()
            S.pop();
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                if(!this->foundInClosed(adj[i])){
                    adj[i]->setCameFrom(u);
                    this->setCost(adj[i], u);
                    S.push(adj[i]);
                    this->closed.insert(adj[i]);
                }
            }
        }
        return this->closed.size();
    }

};


#endif //EX4_DFS_H
