//
// Created by valdman40 on 1/13/20.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H


#include <vector>
#include "State.h"

using namespace std;

template<class T>
class Searchable {

public:

    virtual State<T> *getInitialState() = 0;

    virtual bool isGoalState(State<T>) = 0;

    virtual State<T>* getGoalState() = 0;

    virtual vector<State<T> *> getAllPossibleStates(State<T>) = 0; // like get neighbors

    virtual int huristicsFunc(State<T>* currentState, State<T>* goalState) = 0;
};


#endif //EX4_SEARCHABLE_H
