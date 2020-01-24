//
// Created by yuval on 24/01/2020.
//

#ifndef EX4_MYCACHEMANAGER_H
#define EX4_MYCACHEMANAGER_H

#include <string>
#include <fstream>
#include "Cachemanager.h"
#include <unordered_map>
#include <list>
#include <mutex>
#include <iostream>

using namespace std;
class MyCacheManager : public Cachemanager<string,string>{
    unordered_map<string, string> answers;
    mutex mx;
    // cache size
    int cacheSize = 2;
    // <key, <value, key iterator>>
    unordered_map<string, pair<string, list<string>::iterator>> cacheMap;
    // list of keys, 1st- first used, last- last used
    // we use it to controll cacheMap order
    list<string> lru;
public:
    void useElement(typename unordered_map<string, pair<string, list<string>::iterator>>::iterator &it) {
        this->mx.lock();
        lru.erase(it->second.second);
        lru.push_front(it->first);
        it->second.second = lru.begin();
        this->mx.unlock();
    }

    void insert(string problemAsString,string solution){
        this->mx.lock();
        auto item = cacheMap.find(problemAsString);
        // if the item exists we just going to update it
        if (item != cacheMap.end()) {
            useElement(item);
            cacheMap[problemAsString] = {solution, lru.begin()};
            return;
        }
        int currentMapSize = cacheMap.size();
        if (currentMapSize == cacheSize) {
            // need to kick out item
            cacheMap.erase(lru.back());
            lru.pop_back();
        }
        lru.push_front(problemAsString);
        cacheMap.insert({problemAsString, {solution, lru.begin()}});
        // insert new key value pair
        ofstream data;
        data.open(problemAsString, ios_base::app);
        data << solution << endl;
        data.close();
        this->mx.unlock();
    }
    string get(string key) {
        this->mx.lock();
        auto item = cacheMap.find(key);

        // if the key doesn't exist in cache, return it from the files
        if (item == cacheMap.end()) {
            this->mx.unlock();
            string solution;
            ifstream infoFromTheFile;
            infoFromTheFile.open(key);
            if (!infoFromTheFile) {
                // if not in data
                return "";
            }
            getline(infoFromTheFile, solution);
            insert(key, solution);
            std::cout<<"from file"<<std::endl;
            return solution;
        }
        this->mx.unlock();
        // if the key does exist return his value
        // update the lru list so this element will be the first
        useElement(item);
        std::cout<<"from map"<<std::endl;
        return item->second.first;
    }
};


#endif //EX4_MYCACHEMANAGER_H
