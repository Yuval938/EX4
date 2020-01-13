//
// Created by valdman40 on 1/13/20.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H


template<class T>
class Searchable {

public:
    // using int instead of State for now
    virtual int getInitialState() = 0;
    virtual bool isGoalState(int) = 0;
    virtual int* getAllPossibleStates(int) = 0;

};


#endif //EX4_SEARCHABLE_H
