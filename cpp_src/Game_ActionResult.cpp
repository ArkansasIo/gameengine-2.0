#include "Game_ActionResult.h"

Game_ActionResult::Game_ActionResult() : _hit(false), _critical(false), _damage(0), _successful(false) {
}

Game_ActionResult::~Game_ActionResult() {
}

void Game_ActionResult::clear() {
    _hit = false;
    _critical = false;
    _damage = 0;
    _successful = false;
}

bool Game_ActionResult::isHit() const {
    return _hit;
}

void Game_ActionResult::setHit(bool hit) {
    _hit = hit;
}

bool Game_ActionResult::isCritical() const {
    return _critical;
}

void Game_ActionResult::setCritical(bool critical) {
    _critical = critical;
}

int Game_ActionResult::damage() const {
    return _damage;
}

void Game_ActionResult::setDamage(int damage) {
    _damage = damage;
}

bool Game_ActionResult::isSuccessful() const {
    return _successful;
}

int Game_ActionResult::healEffect() const {
    return _damage > 0 ? -_damage : 0;
}

bool Game_ActionResult::isEvaded() const {
    return !_hit;
}

bool Game_ActionResult::isPhysical() const {
    return true;
}
