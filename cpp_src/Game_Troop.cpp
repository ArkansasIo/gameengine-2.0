#include "Game_Troop.h"

Game_Troop::Game_Troop()
    : _troopId(0), _canEscape(true), _canLose(false) {
}

Game_Troop::~Game_Troop() {
}

void Game_Troop::initialize() {
    _troopId = 0;
    _enemies.clear();
    _canEscape = true;
    _canLose = false;
}

void Game_Troop::setup(int troopId) {
    _troopId = troopId;
}

int Game_Troop::troopId() const {
    return _troopId;
}

QString Game_Troop::name() const {
    return "Troop";
}

bool Game_Troop::canEscape() const {
    return _canEscape;
}

bool Game_Troop::canLose() const {
    return _canLose;
}

QList<int> Game_Troop::members() const {
    return _enemies;
}

int Game_Troop::size() const {
    return _enemies.size();
}

bool Game_Troop::isEmpty() const {
    return _enemies.isEmpty();
}

bool Game_Troop::isEventRunning() const {
    return false;
}

bool Game_Troop::needsPageCheck() const {
    return false;
}

int Game_Troop::currentPageIndex() const {
    return 0;
}

void Game_Troop::setupBattleEvent() {
}

void Game_Troop::updateInterpreter() {
}

void Game_Troop::turnCount() const {
}

void Game_Troop::makeUniqueNames() {
}

void Game_Troop::replaceMemberImage(int index, const QString &characterName, int characterIndex) {
}

void Game_Troop::clearAllBattleResults() {
}

void Game_Troop::displayDropItems() {
}

void Game_Troop::displayExp() {
}

void Game_Troop::displayGold() {
}

void Game_Troop::displayLevelUp() {
}
