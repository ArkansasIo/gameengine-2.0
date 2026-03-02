#include "Game_Variables_Ex.h"

Game_Variables::Game_Variables() {
}

Game_Variables::~Game_Variables() {
}

void Game_Variables::initialize() {
    _data.clear();
    _labels.clear();
}

int Game_Variables::value(int variableId) const {
    return _data.value(variableId, 0);
}

void Game_Variables::setValue(int variableId, int value) {
    if (_data.value(variableId, 0) != value) {
        _data[variableId] = value;
        onChange();
    }
}

QString Game_Variables::label(int variableId) const {
    return _labels.value(variableId, QString());
}

void Game_Variables::setLabel(int variableId, const QString &label) {
    _labels[variableId] = label;
}

void Game_Variables::clear() {
    _data.clear();
}

void Game_Variables::onChange() {
}
