#include "Game_Vehicle.h"

Game_Vehicle::Game_Vehicle(int type) : _vehicleType(type), _mapId(0), _x(0), _y(0) {
}

Game_Vehicle::~Game_Vehicle() {
}

void Game_Vehicle::initialize(const QString &mapName, int x, int y) {
    _x = x;
    _y = y;
}

void Game_Vehicle::update() {
}

int Game_Vehicle::vehicleType() const {
    return _vehicleType;
}

void Game_Vehicle::setLocation(int mapId, int x, int y) {
    _mapId = mapId;
    _x = x;
    _y = y;
}

void Game_Vehicle::getOn() {
}

void Game_Vehicle::getOff() {
}

bool Game_Vehicle::isInside() const {
    return false;
}

bool Game_Vehicle::isMoving() const {
    return false;
}

bool Game_Vehicle::isValid() const {
    return true;
}
