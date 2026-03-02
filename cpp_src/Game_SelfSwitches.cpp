#include "Game_SelfSwitches.h"

Game_SelfSwitches::Game_SelfSwitches() {
}

Game_SelfSwitches::~Game_SelfSwitches() {
}

void Game_SelfSwitches::initialize() {
    _data.clear();
}

bool Game_SelfSwitches::value(int mapId, int eventId, const QString &switchId) const {
    return _data.value(makeKey(mapId, eventId, switchId), false);
}

void Game_SelfSwitches::setValue(int mapId, int eventId, const QString &switchId, bool value) {
    QString key = makeKey(mapId, eventId, switchId);
    if (_data.value(key, false) != value) {
        _data[key] = value;
        onChange();
    }
}

void Game_SelfSwitches::clear() {
    _data.clear();
}

void Game_SelfSwitches::clearMap(int mapId) {
}

void Game_SelfSwitches::onChange() {
}

QString Game_SelfSwitches::makeKey(int mapId, int eventId, const QString &switchId) const {
    return QString("%1_%2_%3").arg(mapId).arg(eventId).arg(switchId);
}
