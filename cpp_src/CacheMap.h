#ifndef CACHE_MAP_H
#define CACHE_MAP_H

#include <string>
#include <map>
#include "CacheEntry.h"

class CacheMap {
public:
    CacheMap();
    ~CacheMap();
    
    void checkTTL();
    void* getItem(const std::string& key);
    void clear();
    CacheEntry* setItem(const std::string& key, void* item);
    void update(int ticks, double delta);
    
private:
    std::map<std::string, CacheEntry*> _cache;
};

#endif // CACHE_MAP_H
