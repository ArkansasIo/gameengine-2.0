#include "CacheMap.h"

CacheMap::CacheMap() {
}

CacheMap::~CacheMap() {
    clear();
}

void CacheMap::checkTTL() {
    for (auto it = _cache.begin(); it != _cache.end();) {
        if (!it->second->isStillAlive()) {
            delete it->second;
            it = _cache.erase(it);
        } else {
            ++it;
        }
    }
}

void* CacheMap::getItem(const std::string& key) {
    auto it = _cache.find(key);
    if (it != _cache.end()) {
        return it->second->item;
    }
    return nullptr;
}

void CacheMap::clear() {
    for (auto& pair : _cache) {
        delete pair.second;
    }
    _cache.clear();
}

CacheEntry* CacheMap::setItem(const std::string& key, void* item) {
    auto it = _cache.find(key);
    if (it != _cache.end()) {
        delete it->second;
    }
    
    CacheEntry* entry = new CacheEntry(this, key, item);
    _cache[key] = entry;
    return entry;
}

void CacheMap::update(int ticks, double delta) {
    checkTTL();
}
