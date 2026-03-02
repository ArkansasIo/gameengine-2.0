#include "Game_Party.h"

Game_Party::Game_Party()
    : _gold(0), _steps(0), _inBattle(false) {
}

Game_Party::~Game_Party() {
}

void Game_Party::initialize() {
    _actors.clear();
    _items.clear();
    _gold = 0;
    _steps = 0;
    _inBattle = false;
}

void Game_Party::setupStartingMembers() {
}

void Game_Party::setupBattleTest() {
}

void Game_Party::setupBattleTestMembers() {
}

void Game_Party::addActor(int actorId) {
    if (!_actors.contains(actorId)) {
        _actors.append(actorId);
    }
}

void Game_Party::removeActor(int actorId) {
    _actors.removeAll(actorId);
}

bool Game_Party::contains(int actorId) const {
    return _actors.contains(actorId);
}

QList<Game_Actor*> Game_Party::allMembers() const {
    return QList<Game_Actor*>();
}

QList<Game_Actor*> Game_Party::battleMembers() const {
    return allMembers();
}

int Game_Party::numItems(int itemId) const {
    return _items.value(itemId, 0);
}

int Game_Party::maxItems() const {
    return 999;
}

bool Game_Party::hasItem(int itemId) const {
    return _items.contains(itemId) && _items[itemId] > 0;
}

bool Game_Party::canUse(int itemId) const {
    return hasItem(itemId);
}

int Game_Party::itemContainer(int itemId) const {
    return 0;
}

void Game_Party::gainItem(int itemId, int amount) {
    _items[itemId] = _items.value(itemId, 0) + amount;
}

void Game_Party::loseItem(int itemId, int amount) {
    _items[itemId] = qMax(0, _items.value(itemId, 0) - amount);
}

void Game_Party::consumeItem(int itemId) {
    loseItem(itemId, 1);
}

bool Game_Party::canConsume(int itemId) const {
    return canUse(itemId);
}

bool Game_Party::canPayCost(const QString &cost) const {
    return true;
}

void Game_Party::payWindowCost(const QString &cost) {
}

int Game_Party::gold() const {
    return _gold;
}

void Game_Party::gainGold(int amount) {
    _gold = qMin(_gold + amount, maxGold());
}

void Game_Party::loseGold(int amount) {
    _gold = qMax(_gold - amount, 0);
}

int Game_Party::maxGold() const {
    return 999999;
}

int Game_Party::steps() const {
    return _steps;
}

void Game_Party::increaseSteps() {
    _steps++;
}

bool Game_Party::inBattle() const {
    return _inBattle;
}

void Game_Party::onPlayerWalk() {
}

QString Game_Party::encounterProgressValue() const {
    return QString();
}
