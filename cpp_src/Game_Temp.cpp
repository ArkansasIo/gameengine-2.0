#include "Game_Temp.h"

Game_Temp::Game_Temp() 
    : _isPlaytest(false), _commonEventId(0), 
      _destinationX(-1), _destinationY(-1) {
}

Game_Temp::~Game_Temp() {
}

void Game_Temp::initialize() {
    _isPlaytest = false;
    _commonEventId = 0;
    _destinationX = -1;
    _destinationY = -1;
}

bool Game_Temp::isPlaytest() const {
    return _isPlaytest;
}

void Game_Temp::reserveCommonEvent(int commonEventId) {
    _commonEventId = commonEventId;
}

void Game_Temp::clearCommonEvent() {
    _commonEventId = 0;
}

bool Game_Temp::isCommonEventReserved() const {
    return _commonEventId > 0;
}

int Game_Temp::reservedCommonEvent() const {
    return _commonEventId;
}

void Game_Temp::setDestination(int x, int y) {
    _destinationX = x;
    _destinationY = y;
}

void Game_Temp::clearDestination() {
    _destinationX = -1;
    _destinationY = -1;
}

bool Game_Temp::isDestinationValid() const {
    return _destinationX >= 0 && _destinationY >= 0;
}

int Game_Temp::destinationX() const {
    return _destinationX;
}

int Game_Temp::destinationY() const {
    return _destinationY;
}
