//
// Created by yuval on 24/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H


template <typename P,typename S>
class Cachemanager {
public:
    virtual void insert(P problem,S solution)=0;
    virtual S get(P problem)=0;
};


#endif //EX4_CACHEMANAGER_H
