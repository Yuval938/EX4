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

    queue<State<T> *> Q;
    vector<State<T> *> openList;
    //  priority_queue<State<T> *, vector<State<T> *>, compreByFValue<T>> Open;
    //   priority_queue<State<T> *, vector<State<T> *>, compreByFValue<T>> Close;

public:

    void sortVector() {
        sort(openList.begin(), openList.end(),
             [](State<T> *u, State<T> *v) {
                 return
                         (u->getHValue() + u->getCost()) < (v->getHValue() + v->getCost());
             }
        );
    }

    bool foundInOpenList(State<T> *state) {
        return (find(openList.begin(), openList.end(), state) != openList.end());
    }

    void addToOpenlist(State<T> *initialState) {
        this->openList.push_back(initialState);
    }

    double heuristic(State<T> *state, Searchable<T> *matrix) {
        return matrix->huristicsFunc(state, matrix->getGoalState());
    }

    State<T> *popMin() { // erase first element (in our case the min) and return it
        this->sortVector();
        State<T> *min = this->openList[0];
        this->openList.erase(this->openList.begin(), this->openList.begin() + 1);
        return min;
    }

    double fFunction(State<T> *state, Searchable<T> *matrix) {
        return (this->heuristic(state, matrix) + state->getCost());
    }

    void Search(Searchable<T> *matrix) override {
        State<T> *initial = matrix->getInitialState();
        this->addToOpenlist(initial);
        while (!this->openList.empty()) {
/*
 *             cout << "size of openList: " << this->openList.size() <<
                 " size of closeList: " << this->closed.size() <<
                 endl;
 */
            State<T> *u = this->popMin();
            if (matrix->isGoalState(*u)) {
                break;
            }
            vector<State<T> *> adj = matrix->getAllPossibleStates(*u);
            int numOfNeighbors = adj.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                State<T> *child = adj[i];
                // double successor_current_cost = u->getCost() + u->getValue() + child->getValue();
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
    }


// f function - h + g
// h- manhathen
// g- cost


/*
 *
 *        bool isInQueue(priority_queue<State<T> *, vector<State<T> *>, compreByFValue<T>> *pq, State<T> *state) {
        bool isInQueue = false;
        priority_queue<State<T> *, vector<State<T> *>, compreByFValue<T>> tempQueue;
        State<T> *tempState;
        while (!pq->empty()) {
            tempState = pq->top();
            pq->pop();
            if (tempState->Equals(*state)) {
                isInQueue = true;
            }
            tempQueue.push(tempState);
        }
        pq->swap(tempQueue);
        return isInQueue;

    }
 *    void setPriority(priority_queue<State<T> *, vector<State<T> *>, compreByFValue<T>> *pq, State<T> *state) {
        priority_queue<State<T> *, vector<State<T> *>, compreByFValue<T>> tempQueue;
        State<T> *tempState;
        while (!pq->empty()) {
            tempState = pq->top();
            pq->pop();
            if (tempState->Equals(*state)) {
                tempState->setCost(state->getCost());
                tempState->setFValue(state->getFValue());
            }
            tempQueue.push(tempState);
        }
        pq->swap(tempQueue);
    }
 */

};


#endif //EX4_ASTAR_H
