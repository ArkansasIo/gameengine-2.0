#include "Game_Switches.h"

Game_Switches::Game_Switches() {
    initialize();
}

Game_Switches::~Game_Switches() {
}

void Game_Switches::initialize() {
    _data.clear();
    _data.resize(1000, false);
}

void Game_Switches::clear() {
    initialize();
}

bool Game_Switches::value(int switchId) const {
    if (switchId >= 0 && switchId < (int)_data.size()) {
        return _data[switchId];
    }
    return false;
}

void Game_Switches::setValue(int switchId, bool value) {
    if (switchId >= 0) {
        if (switchId >= (int)_data.size()) {
            _data.resize(switchId + 1, false);
        }
        _data[switchId] = value;
    }
}
