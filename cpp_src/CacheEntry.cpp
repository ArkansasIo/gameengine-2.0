#include "CacheEntry.h"

CacheEntry::CacheEntry(CacheMap* cache, const std::string& key, void* item)
    : _cache(cache), key(key), item(item), _ticks(0), _seconds(0), _freed(false) {
}

CacheEntry::~CacheEntry() {
}

void CacheEntry::free(bool byTTL) {
    _freed = true;
    item = nullptr;
}

CacheEntry* CacheEntry::allocate() {
    _freed = false;
    return this;
}

CacheEntry* CacheEntry::setTimeToLive(int ticks, int seconds) {
    _ticks = ticks;
    _seconds = seconds;
    return this;
}

bool CacheEntry::isStillAlive() const {
    return !_freed;
}

void CacheEntry::touch() {
    if (_freed) {
        _freed = false;
    }
}
