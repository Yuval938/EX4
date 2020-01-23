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
    double hValue = 0;
    State<T> *cameFrom = NULL; // father

public:
    State(T givenState) {
        this->state = givenState;
        cost = 0;
    }

    double getCost() {
        return this->cost;
    }

    void setCost(double newCost) {
        this->cost = newCost;
    }

    double getHValue() {
        return this->hValue;
    }

    void setHValue(double newHvalue) {
        this->hValue = newHvalue;
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

#endif //EX4_STATE_H
