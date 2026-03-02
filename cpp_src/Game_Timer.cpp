#include "Game_Timer.h"

Game_Timer::Game_Timer() : _working(false), _frames(0) {
}

Game_Timer::~Game_Timer() {
}

void Game_Timer::initialize() {
    _working = false;
    _frames = 0;
}

void Game_Timer::update() {
    if (_working && _frames > 0) {
        _frames--;
        if (_frames == 0) {
            _working = false;
        }
    }
}

void Game_Timer::start(int count) {
    _frames = count;
    _working = true;
}

void Game_Timer::stop() {
    _working = false;
}

bool Game_Timer::isWorking() const {
    return _working;
}

int Game_Timer::seconds() const {
    return _frames / 60;
}
