//
// Created by valdman40 on 1/13/20.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H


#include <vector>

using namespace std;

template<class T>
class Searchable {

public:
    // using int instead of State for now
    virtual T getInitialState() = 0;

    virtual bool isGoalState(T) = 0;

    virtual vector<vector<T>> getAllPossibleStates() = 0;

};


#endif //EX4_SEARCHABLE_H
