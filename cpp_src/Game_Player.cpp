#include "Game_Player.h"

Game_Player::Game_Player()
    : _x(0), _y(0), _direction(2), _moving(false), _dashing(false), _vehicleType(0) {
}

Game_Player::~Game_Player() {
}

void Game_Player::initialize() {
}

void Game_Player::refresh() {
}

void Game_Player::reserveTransfer(int mapId, int x, int y, int d) {
}

void Game_Player::requestMapReload() {
}

void Game_Player::setDirection(int d) {
    _direction = d;
}

int Game_Player::direction() const {
    return _direction;
}

bool Game_Player::isStopping() const {
    return !_moving;
}

int Game_Player::x() const {
    return _x;
}

int Game_Player::y() const {
    return _y;
}

bool Game_Player::perform_transfer() {
    return false;
}

bool Game_Player::is_transfer_requesting() const {
    return false;
}

void Game_Player::check_event_trigger_there(int triggers) {
}

void Game_Player::check_event_trigger_touch(int x, int y) {
}

void Game_Player::update() {
    updateDashing();
}

void Game_Player::updateDashing() {
}

void Game_Player::updateNonmoving(bool wasMoving) {
}

bool Game_Player::canMove() const {
    return true;
}

bool Game_Player::isAboutToDash() const {
    return false;
}

bool Game_Player::isDashing() const {
    return _dashing;
}

bool Game_Player::isDebugThrough() const {
    return false;
}

void Game_Player::straighten() {
}

bool Game_Player::isMoving() const {
    return _moving;
}

bool Game_Player::isMovementSucceeded(int x, int y) const {
    return true;
}

bool Game_Player::canPassDiagonally(int horz, int vert) const {
    return true;
}

int Game_Player::getInputDirection() const {
    return 0;
}

void Game_Player::executeMove(int direction) {
    _direction = direction;
}

void Game_Player::updateScroll(int lastScrolledX, int lastScrolledY) {
}

void Game_Player::makeEncounter() {
}

bool Game_Player::triggerAction() {
    return false;
}

bool Game_Player::triggerTouchAction() {
    return false;
}

QString Game_Player::triggerTouchActionD3(int x1, int y1) {
    return QString();
}

QString Game_Player::triggerTouchActionD4(int x1, int y1, int x2, int y2) {
    return QString();
}

QString Game_Player::triggerTouchActionD5(int x1, int y1) {
    return QString();
}

QString Game_Player::startMapEvent(int x, int y, const QString &triggers) {
    return QString();
}

bool Game_Player::isInVehicle() const {
    return _vehicleType > 0;
}

bool Game_Player::isInBoat() const {
    return _vehicleType == 1;
}

bool Game_Player::isInShip() const {
    return _vehicleType == 2;
}

bool Game_Player::isInAirship() const {
    return _vehicleType == 3;
}

bool Game_Player::isIncapacitated() const {
    return false;
}
