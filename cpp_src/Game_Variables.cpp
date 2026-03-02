#include "Game_Variables.h"

Game_Variables::Game_Variables() {
    initialize();
}

Game_Variables::~Game_Variables() {
}

void Game_Variables::initialize() {
    _data.clear();
    _data.resize(1000, 0);
}

void Game_Variables::clear() {
    initialize();
}

int Game_Variables::value(int variableId) const {
    if (variableId >= 0 && variableId < (int)_data.size()) {
        return _data[variableId];
    }
    return 0;
}

void Game_Variables::setValue(int variableId, int value) {
    if (variableId >= 0) {
        if (variableId >= (int)_data.size()) {
            _data.resize(variableId + 1, 0);
        }
        _data[variableId] = value;
    }
}
