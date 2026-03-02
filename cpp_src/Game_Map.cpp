#include "Game_Map.h"

Game_Map::Game_Map() : _mapId(0), _needsRefresh(false) {
}

Game_Map::~Game_Map() {
}

void Game_Map::setup(int mapId) {
    _mapId = mapId;
    _displayName = QString("Map %1").arg(mapId);
    setupEvents();
}

void Game_Map::setupEvents() {
}

int Game_Map::mapId() const {
    return _mapId;
}

QString Game_Map::displayName() const {
    return _displayName;
}

bool Game_Map::isNameDisplayAllowed() const {
    return true;
}

bool Game_Map::isDarkAreaLarge() const {
    return false;
}

bool Game_Map::defaultCollider() const {
    return false;
}

int Game_Map::encounterStep() const {
    return 30;
}

QList<int> Game_Map::encounterList() const {
    return QList<int>();
}

int Game_Map::encounter() const {
    return 0;
}

bool Game_Map::isAllowAvoidance() const {
    return true;
}

QString Game_Map::mapNote() const {
    return QString();
}

int Game_Map::battleBack1Name() const {
    return 0;
}

int Game_Map::battleBack2Name() const {
    return 0;
}

bool Game_Map::needsRefresh() const {
    return _needsRefresh;
}

void Game_Map::refresh() {
    _needsRefresh = false;
}

void Game_Map::autoplay() {
}

bool Game_Map::isLoopHorizontal() const {
    return false;
}

bool Game_Map::isLoopVertical() const {
    return false;
}

bool Game_Map::isScrollDown() const {
    return false;
}

bool Game_Map::isScrollLeft() const {
    return false;
}

bool Game_Map::isScrollRight() const {
    return false;
}

bool Game_Map::isScrollUp() const {
    return false;
}

int Game_Map::screenTileX() const {
    return 17;
}

int Game_Map::screenTileY() const {
    return 13;
}

int Game_Map::adjustX(int x) const {
    return x;
}

int Game_Map::adjustY(int y) const {
    return y;
}

int Game_Map::roundX(int x) const {
    return x % (isLoopHorizontal() ? 100 : 1000);
}

int Game_Map::roundY(int y) const {
    return y % (isLoopVertical() ? 100 : 1000);
}

bool Game_Map::isValid(int x, int y) const {
    return x >= 0 && y >= 0 && x < 100 && y < 100;
}

bool Game_Map::checkPassage(int x, int y, int bit) const {
    return true;
}

bool Game_Map::isPassable(int x, int y, int d) const {
    return true;
}

bool Game_Map::isBoatPassable(int x, int y) const {
    return true;
}

bool Game_Map::isShipPassable(int x, int y) const {
    return true;
}

bool Game_Map::isAirshipLandOk(int x, int y) const {
    return true;
}

bool Game_Map::checkLayeredTiles(int x, int y, int bit) const {
    return false;
}

bool Game_Map::isBush(int x, int y) const {
    return false;
}

bool Game_Map::isCounter(int x, int y) const {
    return false;
}

bool Game_Map::isDamageFloor(int x, int y) const {
    return false;
}

bool Game_Map::isTerrain(int x, int y, int terrainTag) const {
    return false;
}

bool Game_Map::isRegion(int x, int y, int regionId) const {
    return false;
}

int Game_Map::terrainTag(int x, int y) const {
    return 0;
}

int Game_Map::regionId(int x, int y) const {
    return 0;
}

bool Game_Map::eventsXy(int x, int y) const {
    return false;
}

int Game_Map::tileId(int x, int y, int z) const {
    return 0;
}

bool Game_Map::isAnyEventStarting() const {
    return false;
}
