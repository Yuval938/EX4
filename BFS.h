//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H


#include <queue>
#include <iostream>
#include "Searcher.h"


using namespace std;

template<typename T>
class BFS : public Searcher<T> {
    queue<State<T> *> Q;
public:
    BFS(){

    }
    BFS (BFS const &){

    }
    BFS * clone () const        // Virtual constructor (copying)
    {
        return new BFS (*this);
    }
    int Search(Searchable<T> *matrix) override {

        State<T> *initialState = matrix->getInitialState();
        initialState->setCost(0);
        this->closed.insert(initialState);
        Q.push(initialState);
        while (!Q.empty()) {
            State<T> *u = Q.front(); // Node *u = Q.pop()
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


#endif //EX4_BFS_H
