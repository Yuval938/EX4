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
    priority_queue<State<T>*, vector<State<T>*>, compreByFValue<T>> Open;
    priority_queue<State<T>*, vector<State<T>*>, compreByFValue<T>> Close;

public:
    void Search(Searchable<T> *matrix) override {
        State<T>* currentState=matrix->getInitialState();
        currentState->setCost(0);
        vector<State<T>*> succsseors;
        int new_cost;
        if(matrix->isGoalState(*currentState)){
            return;    //goal and start are the same
        }
// push the start state to open
        Open.push(currentState);
        while(!Open.empty()){
// pop from the queue the state with the best priority
            currentState = Open.top();
            Open.pop();
            Close.push(currentState);
// put in successesors all the possible states to go to from the current state
            succsseors = matrix->getAllPossibleStates(*currentState);
            for(State<T>* s: succsseors) {
// if this state is the goal state, finish
                if ((matrix->isGoalState(*s))){
                    s->setCameFrom(currentState);
                    s->setCost(currentState->getCost() + currentState->getValue());
                    return;
                }else{
// calculate the cost that could be
                    new_cost = currentState->getCost() + currentState->getValue();
// if its a new node or the new cost is better then the previews cost
                    if ((!this->isInQueue(&Open, s) && !this->isInQueue(&Close, s)) || new_cost < s->getCost()){
                        s->setCost(new_cost);
                        s->setFValue(matrix->huristicsFunc(s, matrix->getGoalState()) + new_cost);
                        if(this->isInQueue(&Open, s))
                        {
                            this->setPriority(&Open, s);
                        }else{
                            Open.push(s);
                        }
                        s->setCameFrom(currentState);
                    }
                }
            }
        }
        return;
    }

    bool isInQueue(priority_queue<State<T>*, vector<State<T>*>, compreByFValue<T>> *pq, State<T>* state) {
        bool isInQueue = false;
        priority_queue<State<T>*, vector<State<T>*>, compreByFValue<T>> tempQueue;
        State<T>* tempState;
        while(!pq->empty()){
            tempState = pq->top();
            pq->pop();
            if (tempState->Equals(*state)){
                isInQueue = true;
            }
            tempQueue.push(tempState);
        }
        pq->swap(tempQueue);
        return isInQueue;

    }
    void setPriority(priority_queue<State<T>*, vector<State<T>*>, compreByFValue<T>> *pq,State<T>* state) {
        priority_queue<State<T>*, vector<State<T>*>, compreByFValue<T>> tempQueue;
        State<T>* tempState;
        while(!pq->empty()){
            tempState = pq->top();
            pq->pop();
            if (tempState->Equals(*state)){
                tempState->setCost(state->getCost());
                tempState->setFValue(state->getFValue());
            }
            tempQueue.push(tempState);
        }
        pq->swap(tempQueue);
    }

};


#endif //EX4_ASTAR_H
