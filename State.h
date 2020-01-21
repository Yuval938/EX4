//
// Created by valdman40 on 1/20/20.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include <clocale>

template<typename T>
class State {

    T state; // usually position
    double cost; // cost of path
    double value = 0;
    double FValue = 0;
    State<T> *cameFrom = NULL; // father

public:
    State(T givenState) {
        this->state = givenState;
    }

    bool Equals(State<T> s) {
        return this->state == s.state;
    }

    double getCost() {
        return this->cost;
    }

    void setCost(double newCost) {
        this->cost = newCost;
    }
    double getFValue() {
        return this->FValue;
    }

    void setFValue(double FValue1) {
        this->FValue = FValue1;
    }

    double getValue() {
        return this->value;
    }

    void setValue(double newVal) {
        this->value = newVal;
    }

    T getState() {
        return this->state;
    }

    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    void setCameFrom(State<T> *father) {
        this->cameFrom = father;
    }

};

//we might need to change these classes from pointer to a &
template<class T>
class compreByCost{
public:
    bool operator()(const State<T>* s1,const State<T>* s2 )const{
        return s1->getCost() > s2->getCost();
    }
};

template<class T>
class compreByFValue{
public:
    bool operator()(const State<T>* s1,const State<T>* s2 )const{
        return s1->getPriority() > s2->getPriority();
    }
};


#endif //EX4_STATE_H
