#include "Game_CommonEvent.h"

Game_CommonEvent::Game_CommonEvent(int id) : _eventId(id), _active(true), _trigger(0) {
}

Game_CommonEvent::~Game_CommonEvent() {
}

int Game_CommonEvent::eventId() const {
    return _eventId;
}

QString Game_CommonEvent::name() const {
    return _name;
}

void Game_CommonEvent::setName(const QString &name) {
    _name = name;
}

void Game_CommonEvent::update() {
}

void Game_CommonEvent::start() {
    _active = true;
}

void Game_CommonEvent::stop() {
    _active = false;
}

bool Game_CommonEvent::isActive() const {
    return _active;
}

bool Game_CommonEvent::isTrigger(int trigger) const {
    return _trigger == trigger;
}

void Game_CommonEvent::setTrigger(int trigger) {
    _trigger = trigger;
}
