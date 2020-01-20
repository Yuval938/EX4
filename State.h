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
    State<T> *cameFrom = NULL; // father
    char color = 'w';

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

    void setColor(char c) {
        this->color = c;
    }

    char getColor() {
        return this->color;
    }

};


#endif //EX4_STATE_H
