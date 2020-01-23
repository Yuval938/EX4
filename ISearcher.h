//
// Created by valdman40 on 1/22/20.
//

#ifndef EX4_ISEARCHER_H
#define EX4_ISEARCHER_H
#include "Searchable.h"

template<class T>
class ISearcher {

public:
    virtual int Search(Searchable<T>*) = 0;

};


#endif //EX4_ISEARCHER_H
