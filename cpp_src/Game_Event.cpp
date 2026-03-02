#include "Game_Event.h"

Game_Event::Game_Event(int mapId, int eventId)
    : _mapId(mapId), _eventId(eventId), _x(0), _y(0), _direction(2),
      _starting(false), _erased(false) {
}

Game_Event::~Game_Event() {
}

void Game_Event::initialize(int mapId, int eventId) {
    _mapId = mapId;
    _eventId = eventId;
}

void Game_Event::refresh() {
}

void Game_Event::setupPageSettings() {
}

void Game_Event::clearPageSettings() {
}

void Game_Event::setupMoveRoute(const QString &route) {
}

int Game_Event::eventId() const {
    return _eventId;
}

QString Game_Event::event() const {
    return QString();
}

int Game_Event::x() const {
    return _x;
}

int Game_Event::y() const {
    return _y;
}

void Game_Event::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

int Game_Event::direction() const {
    return _direction;
}

void Game_Event::setDirection(int direction) {
    _direction = direction;
}

bool Game_Event::isJumping() const {
    return false;
}

void Game_Event::jump(int deltaX, int deltaY) {
}

bool Game_Event::isMoveRouteForcing() const {
    return false;
}

void Game_Event::forceMoveRoute(const QString &route) {
}

void Game_Event::cancelMoveRoute() {
}

bool Game_Event::isStarting() const {
    return _starting;
}

bool Game_Event::isErased() const {
    return _erased;
}

void Game_Event::start() {
    _starting = true;
}

void Game_Event::erase() {
    _erased = true;
}

bool Game_Event::isTriggerIn(const QList<int> &triggers) const {
    return false;
}

void Game_Event::update() {
    updateSelfMovement();
    updateStop();
}

void Game_Event::updateSelfMovement() {
}

void Game_Event::updateStop() {
}

bool Game_Event::checkEventTriggerTouch(int x, int y) {
    return false;
}
