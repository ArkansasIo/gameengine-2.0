#include "Tilemap.h"

Tilemap::Tilemap() : _mapId(0), _displayX(0), _displayY(0), _originX(0), _originY(0) {
}

Tilemap::~Tilemap() {
}

void Tilemap::initialize(int mapId) {
    _mapId = mapId;
}

void Tilemap::refresh() {
}

void Tilemap::update() {
}

void Tilemap::setBitmaps(const QStringList &filenames) {
}

void Tilemap::setDisplayPos(int x, int y) {
    _displayX = x;
    _displayY = y;
}

void Tilemap::setOrigin(int x, int y) {
    _originX = x;
    _originY = y;
}

int Tilemap::originX() const {
    return _originX;
}

int Tilemap::originY() const {
    return _originY;
}
