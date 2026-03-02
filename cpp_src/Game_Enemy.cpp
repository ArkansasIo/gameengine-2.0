#include "Game_Enemy.h"

Game_Enemy::Game_Enemy(int enemyId, int x, int y)
    : _enemyId(enemyId), _screenX(x), _screenY(y) {
}

Game_Enemy::~Game_Enemy() {
}

void Game_Enemy::setup(int enemyId, int x, int y) {
    _enemyId = enemyId;
    _screenX = x;
    _screenY = y;
    initialize();
}

void Game_Enemy::initialize() {
    Game_BattlerBase::initialize();
}

int Game_Enemy::enemyId() const {
    return _enemyId;
}

QString Game_Enemy::name() const {
    return "Enemy";
}

int Game_Enemy::level() const {
    return 1;
}

int Game_Enemy::maxHp() const {
    return 100;
}

int Game_Enemy::maxMp() const {
    return 50;
}

int Game_Enemy::exp() const {
    return 100;
}

int Game_Enemy::gold() const {
    return 50;
}

QList<int> Game_Enemy::makeDropItems() {
    return QList<int>();
}

int Game_Enemy::battlerName() const {
    return 0;
}

int Game_Enemy::battlerHue() const {
    return 0;
}

int Game_Enemy::param() const {
    return 100;
}

double Game_Enemy::paramBase(int paramId) const {
    return 100.0;
}

int Game_Enemy::isSpriteVisible() const {
    return 1;
}

int Game_Enemy::shouldPopupDamage() const {
    return 1;
}

bool Game_Enemy::escapeRate() const {
    return false;
}

bool Game_Enemy::canDropLoot() const {
    return true;
}

int Game_Enemy::corpseX() const {
    return _screenX;
}

int Game_Enemy::corpseY() const {
    return _screenY;
}
