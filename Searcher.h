//
// Created by valdman40 on 1/13/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
#include "ISearcher.h"
#include <unordered_set>

template<class T>
class Searcher : public ISearcher<T> {

protected:

    unordered_set<State<T> *> closed; // to keep track on states we visited already

public:

    void setCost(State<T> *son, State<T> *father){
        double fatherAddition = father->getCost();
        if(fatherAddition == 0){ // means it's the initial state
            fatherAddition = father->getValue();
        }
        son->setCost(fatherAddition + son->getValue());
    }
    bool foundInClosed(State<T> *state) {
        return (closed.count(state));
    }
    virtual Searcher * clone () const = 0;


};


#endif //EX4_SEARCHER_H
