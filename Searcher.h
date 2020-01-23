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
    vector<State<T> *> openList;
    unordered_set<State<T> *> closed; // to keep track on states we visited already

public:
    bool foundInOpenList(State<T> *state) {
        return (find(this->openList.begin(), this->openList.end(), state) != this->openList.end());
    }

    void addToOpenlist(State<T> *initialState) {
        this->openList.push_back(initialState);
    }

    State<T> *popMin() { // erase first element (in our case the min) and return it
        State<T> *min = this->openList[0];
        this->openList.erase(this->openList.begin(), this->openList.begin() + 1);
        return min;
    }

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
