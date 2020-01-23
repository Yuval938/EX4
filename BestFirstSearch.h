//
// Created by valdman40 on 1/20/20.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H


#include <queue>
#include <iostream>
#include "Searcher.h"
#include <unordered_set>
#include <list>

using namespace std;

template<typename T>
class BestFirstSearch : public Searcher<T> {

public:
    BestFirstSearch() {
    }
    BestFirstSearch (BestFirstSearch const &){

    }
    BestFirstSearch * clone () const        // Virtual constructor (copying)
    {
        return new BestFirstSearch (*this);
    }
    void sortVector() {
        sort(this->openList.begin(), this->openList.end(),
             [](State<T> *u, State<T> *v) { return u->getCost() < v->getCost(); }
        );
    }

    int Search(Searchable<T> *matrix) override {

        this->addToOpenlist(matrix->getInitialState());
        while (!this->openList.empty()) {
            this->sortVector();
            State<T> *u = this->popMin();
            this->closed.insert(u);
            if (matrix->isGoalState(*u)) {
                return this->closed.size();;
            }
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                // didn't find neither in closed or open, so we add to open
                if (!this->foundInClosed(adj[i]) && !this->foundInOpenList(adj[i])) {
                    adj[i]->setCameFrom(u);
                    this->setCost(adj[i], u);
                    this->openList.push_back(adj[i]);
                }
            }
        }
    }


};


#endif //EX4_BESTFIRSTSEARCH_H
