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

    vector<State<T> *> openList;
    unordered_set<State<T> *> closed; // to keep track on states we visited already

public:
    bool foundInOpenList(State<T> *state) {
        return (find(openList.begin(), openList.end(), state) != openList.end());
    }

    bool foundInClosed(State<T> *state) {
        return (closed.count(state));
    }

    void sortVector() {
        sort(openList.begin(), openList.end(),
             [](State<T> *u, State<T> *v) { return u->getCost() < v->getCost(); }
        );
    }

    void Search(Searchable<T> *matrix) override {
        State<T> *initialState = matrix->getInitialState();
        initialState->setCost(0);
        openList.push_back(initialState);
        while (!openList.empty()) {
            // cout << "openList size: " << openList.size() << endl; // just for check
            this->sortVector();
            State<T> *u = openList[0];
            openList.erase(openList.begin(), openList.begin() + 1); // erase first element (in our case the min)
            closed.insert(u);
            if (matrix->isGoalState(*u)) {
                return;
            }
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                // didn't find neither in closed or open, so we add to open
                if (!this->foundInClosed(adj[i]) && !this->foundInOpenList(adj[i])) {
                    adj[i]->setCameFrom(u);
                    adj[i]->setCost(u->getCost() + u->getValue());
                    openList.push_back(adj[i]);
                }
            }
        }
    }

};


#endif //EX4_BESTFIRSTSEARCH_H
