//
// Created by yuval on 21/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H


#include <queue>
#include <iostream>
#include "Searcher.h"
//#include "Node.h"

using namespace std;

template<typename T>
class AStar : public Searcher<T> {

public:
AStar(){

}
    AStar (AStar const &){

    }
    AStar * clone () const        // Virtual constructor (copying)
    {
        return new AStar (*this);
    }

    void sortVector() {
        sort(this->openList.begin(), this->openList.end(),
             [](State<T> *u, State<T> *v) {
                 return
                         (u->getHValue() + u->getCost()) < (v->getHValue() + v->getCost());
             }
        );
    }

    double heuristic(State<T> *state, Searchable<T> *matrix) {
        return matrix->huristicsFunc(state, matrix->getGoalState());
    }

    int Search(Searchable<T> *matrix) override {
        State<T> *initial = matrix->getInitialState();
        this->addToOpenlist(initial);
        while (!this->openList.empty()) {
            this->sortVector();
            State<T> *u = this->popMin();
            if (matrix->isGoalState(*u)) {
                break;
            }
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                State<T> *child = adj[i];
                double fatherAddition = u->getCost();
                if (fatherAddition == 0) { // means it's the initial state
                    fatherAddition = u->getValue();
                }
                double successor_current_cost = fatherAddition + child->getValue();
                if (this->foundInOpenList(child)) {
                    if (child->getValue() <= successor_current_cost) {
                        continue;
                    }
                } else if (this->foundInClosed(child)) {
                    if (child->getValue() <= successor_current_cost) {
                        continue;
                    }
                    this->addToOpenlist(child);
                    this->closed.erase(this->closed.find(child));
                } else {
                    this->addToOpenlist(child);
                    child->setHValue(this->heuristic(child, matrix));
                }
                child->setCost(successor_current_cost);
                child->setCameFrom(u);
            }
            this->closed.insert(u);
        }
        return this->closed.size();
    }

};


#endif //EX4_ASTAR_H
