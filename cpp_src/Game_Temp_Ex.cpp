#include "Game_Temp_Ex.h"

Game_Temp::Game_Temp()
    : _playtest(false), _mapEditorInitialized(false), _needsMapLoader(false),
      _newMapId(0), _transferring(false), _transferMapId(0), _transferX(0),
      _transferY(0), _transferDirection(2) {
}

Game_Temp::~Game_Temp() {
}

bool Game_Temp::isPlaytest() const {
    return _playtest;
}

void Game_Temp::setPlaytest(bool value) {
    _playtest = value;
}

QString Game_Temp::mapEditorInitialized() const {
    return QString();
}

void Game_Temp::setMapEditorInitialized(bool value) {
    _mapEditorInitialized = value;
}

bool Game_Temp::needsMapLoader() const {
    return _needsMapLoader;
}

void Game_Temp::setNeedsMapLoader(bool value) {
    _needsMapLoader = value;
}

int Game_Temp::newMapId() const {
    return _newMapId;
}

void Game_Temp::setNewMapId(int mapId) {
    _newMapId = mapId;
}

bool Game_Temp::isTransferring() const {
    return _transferring;
}

void Game_Temp::setTransferring(bool value) {
    _transferring = value;
}

int Game_Temp::transferMapId() const {
    return _transferMapId;
}

void Game_Temp::setTransferMapId(int mapId) {
    _transferMapId = mapId;
}

int Game_Temp::transferX() const {
    return _transferX;
}

void Game_Temp::setTransferX(int x) {
    _transferX = x;
}

int Game_Temp::transferY() const {
    return _transferY;
}

void Game_Temp::setTransferY(int y) {
    _transferY = y;
}

int Game_Temp::transferDirection() const {
    return _transferDirection;
}

void Game_Temp::setTransferDirection(int direction) {
    _transferDirection = direction;
}

bool Game_Temp::isEncounterEffectEnabled() const {
    return true;
}

void Game_Temp::setEncounterEffectEnabled(bool value) {
}

QString Game_Temp::battleSe() const {
    return QString();
}

void Game_Temp::setBattleSe(const QString &name) {
}

QString Game_Temp::commonEventId() const {
    return QString();
}

void Game_Temp::setCommonEventId(const QString &id) {
}
