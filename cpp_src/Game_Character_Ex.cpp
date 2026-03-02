#include "Game_Character_Ex.h"

Game_Character::Game_Character() : _characterIndex(0) {
}

Game_Character::~Game_Character() {
}

void Game_Character::initialize() {
    Game_CharacterBase::initialize();
}

void Game_Character::update() {
    Game_CharacterBase::update();
}

void Game_Character::setMovementRoute(const QVector<int> &route) {
}

void Game_Character::setWalkerImage(const QString &name) {
    _characterName = name;
}

void Game_Character::setProfile(int characterId, int characterIndex) {
    _characterIndex = characterIndex;
}

void Game_Character::moveRandom() {
}

void Game_Character::moveTowardActor(int actorId) {
}

void Game_Character::moveAwayFromActor(int actorId) {
}

void Game_Character::moveForward() {
}

void Game_Character::moveBackward() {
}

int Game_Character::direction() const {
    return 0;
}

void Game_Character::setDirection(int direction) {
}

bool Game_Character::isTurning() const {
    return false;
}
