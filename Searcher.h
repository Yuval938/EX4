//
// Created by valdman40 on 1/13/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Solution.h"
#include "Searchable.h"


template<class T,class S>
class Searcher {

public:
    virtual void Search(Searchable<T>*) = 0;

};


#endif //EX4_SEARCHER_H
