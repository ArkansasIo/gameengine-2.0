#include "../../include/graphics/Tilemap.h"

namespace LunaLite {
namespace Graphics {

Tilemap::Tilemap(Core::GameMap* gameMap)
    : Sprite(0), _gameMap(gameMap), _tilesetId(1),
      _scrollX(0), _scrollY(0) {
    for (int i = 0; i < 4; ++i) {
        _layerVisible[i] = true;
    }
}

Tilemap::~Tilemap() {
}

Core::GameMap* Tilemap::getGameMap() const {
    return _gameMap;
}

void Tilemap::setGameMap(Core::GameMap* gameMap) {
    _gameMap = gameMap;
    if (_gameMap) {
        _tilesetId = _gameMap->getTilesetId();
    }
}

int Tilemap::getLayerCount() const {
    return 4;  // Standard RPG Maker uses 4 layers
}

bool Tilemap::isLayerVisible(int layer) const {
    if (layer >= 0 && layer < 4) {
        return _layerVisible[layer];
    }
    return false;
}

void Tilemap::setLayerVisible(int layer, bool visible) {
    if (layer >= 0 && layer < 4) {
        _layerVisible[layer] = visible;
    }
}

int Tilemap::getTilesetId() const {
    return _tilesetId;
}

void Tilemap::setTilesetId(int id) {
    _tilesetId = id;
}

float Tilemap::getScrollX() const {
    return _scrollX;
}

float Tilemap::getScrollY() const {
    return _scrollY;
}

void Tilemap::setScroll(float x, float y) {
    _scrollX = x;
    _scrollY = y;
}

void Tilemap::scroll(float dx, float dy) {
    _scrollX += dx;
    _scrollY += dy;
}

int Tilemap::getViewportX() const {
    return static_cast<int>(_scrollX);
}

int Tilemap::getViewportY() const {
    return static_cast<int>(_scrollY);
}

int Tilemap::getViewportWidth() const {
    return 20;  // Typically 20 tiles wide
}

int Tilemap::getViewportHeight() const {
    return 15;  // Typically 15 tiles tall
}

void Tilemap::update() {
    Sprite::update();
}

} // namespace Graphics
} // namespace LunaLite
