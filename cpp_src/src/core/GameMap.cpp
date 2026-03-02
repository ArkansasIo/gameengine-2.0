#include "../../include/core/GameMap.h"

namespace LunaLite {
namespace Core {

GameMap::GameMap(int mapId)
    : GameObject(mapId), _mapId(mapId), _width(20), _height(15),
      _tilesetId(1), _allowDashing(true), _encounterEnabled(true),
      _encounterRate(5), _parallaxLooping(false) {
    initialize();
}

GameMap::~GameMap() {
}

int GameMap::getMapId() const {
    return _mapId;
}

QString GameMap::getMapName() const {
    return _mapName;
}

int GameMap::getWidth() const {
    return _width;
}

int GameMap::getHeight() const {
    return _height;
}

int GameMap::getTilesetId() const {
    return _tilesetId;
}

QString GameMap::getBattleback1Name() const {
    return _battleback1;
}

QString GameMap::getBattleback2Name() const {
    return _battleback2;
}

bool GameMap::isAllowDashing() const {
    return _allowDashing;
}

bool GameMap::isEncounterEnabled() const {
    return _encounterEnabled;
}

int GameMap::getEncounterRate() const {
    return _encounterRate;
}

int GameMap::getEventCount() const {
    return _events.size();
}

bool GameMap::hasEvent(int eventId) const {
    return _events.contains(eventId);
}

bool GameMap::setTile(int x, int y, int layer, int tileId) {
    if (x >= 0 && x < _width && y >= 0 && y < _height) {
        QString key = QString::number(x) + "," + QString::number(y) + "," + QString::number(layer);
        _mapData[key] = tileId;
        return true;
    }
    return false;
}

int GameMap::getTile(int x, int y, int layer) const {
    if (x >= 0 && x < _width && y >= 0 && y < _height) {
        QString key = QString::number(x) + "," + QString::number(y) + "," + QString::number(layer);
        return _mapData.value(key, 0);
    }
    return 0;
}

bool GameMap::hasParallax() const {
    return !_parallaxName.isEmpty();
}

QString GameMap::getParallaxName() const {
    return _parallaxName;
}

bool GameMap::isParallaxLooping() const {
    return _parallaxLooping;
}

void GameMap::initialize() {
    _mapName = "Map " + QString::number(_mapId);
}

void GameMap::update() {
}

} // namespace Core
} // namespace LunaLite
