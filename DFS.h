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
   stack<State<T> *> Q;
public:
    DFS(){

    }
    DFS (DFS const &){

    }
    DFS * clone () const        // Virtual constructor (copying)
    {
        return new DFS (*this);
    }
    int Search(Searchable<T> *matrix) override {

        State<T> *initialState = matrix->getInitialState();
        initialState->setCost(0);
        this->closed.insert(initialState);
        Q.push(initialState);
        while (!Q.empty()) {
            State<T> *u = Q.top(); // Node *u = Q.pop()
            Q.pop();
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                if (!this->foundInClosed(adj[i])) {
                    this->closed.insert(adj[i]);
                    adj[i]->setCameFrom(u);
                    adj[i]->setCost(u->getCost() + u->getValue());
                    Q.push(adj[i]);
                }
            }
        }
        return this->closed.size();
    }

};


#endif //EX4_DFS_H
