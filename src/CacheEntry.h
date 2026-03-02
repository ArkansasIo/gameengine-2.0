#ifndef CACHE_ENTRY_H
#define CACHE_ENTRY_H

#include <string>

class CacheMap;

class CacheEntry {
public:
    CacheEntry(CacheMap* cache, const std::string& key, void* item);
    ~CacheEntry();
    
    void free(bool byTTL = false);
    CacheEntry* allocate();
    CacheEntry* setTimeToLive(int ticks = 0, int seconds = 0);
    bool isStillAlive() const;
    void touch();
    
    std::string key;
    void* item;
    
private:
    CacheMap* _cache;
    int _ticks;
    int _seconds;
    bool _freed;
};

#endif // CACHE_ENTRY_H
