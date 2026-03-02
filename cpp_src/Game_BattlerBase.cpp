#include "Game_BattlerBase.h"

Game_BattlerBase::Game_BattlerBase()
    : _hp(0), _mp(0), _tp(0), _level(1), _hidden(0) {
}

Game_BattlerBase::~Game_BattlerBase() {
}

void Game_BattlerBase::initialize() {
    _hp = maxHp();
    _mp = maxMp();
    _tp = 0;
    resetStateCounts();
}

int Game_BattlerBase::level() const {
    return _level;
}

int Game_BattlerBase::exp() const {
    return 0;
}

int Game_BattlerBase::maxHp() const {
    return 100;
}

int Game_BattlerBase::maxMp() const {
    return 50;
}

int Game_BattlerBase::hp() const {
    return _hp;
}

void Game_BattlerBase::setHp(int value) {
    _hp = qMax(0, qMin(value, maxHp()));
}

int Game_BattlerBase::mp() const {
    return _mp;
}

void Game_BattlerBase::setMp(int value) {
    _mp = qMax(0, qMin(value, maxMp()));
}

int Game_BattlerBase::tp() const {
    return _tp;
}

void Game_BattlerBase::setTp(int value) {
    _tp = qMax(0, qMin(value, 100));
}

int Game_BattlerBase::mhp() const {
    return maxHp();
}

int Game_BattlerBase::mmp() const {
    return maxMp();
}

bool Game_BattlerBase::isAlive() const {
    return !isDead();
}

bool Game_BattlerBase::isDead() const {
    return hp() <= 0;
}

bool Game_BattlerBase::isActor() const {
    return false;
}

bool Game_BattlerBase::isEnemy() const {
    return false;
}

void Game_BattlerBase::refresh() {
}

void Game_BattlerBase::addState(int stateId) {
    if (!_states.contains(stateId)) {
        _states.append(stateId);
        _stateTurns.append(0);
    }
}

void Game_BattlerBase::removeState(int stateId) {
    int index = _states.indexOf(stateId);
    if (index >= 0) {
        _states.removeAt(index);
        _stateTurns.removeAt(index);
    }
}

bool Game_BattlerBase::isStateAffected(int stateId) const {
    return _states.contains(stateId);
}

bool Game_BattlerBase::isStateClear() const {
    return _states.isEmpty();
}

QList<int> Game_BattlerBase::states() const {
    return _states;
}

int Game_BattlerBase::stateTurns(int stateId) const {
    int index = _states.indexOf(stateId);
    return index >= 0 ? _stateTurns[index] : 0;
}

void Game_BattlerBase::minTurnsStateEffectRemoving(int stateId) {
    int index = _states.indexOf(stateId);
    if (index >= 0 && _stateTurns[index] > 0) {
        _stateTurns[index]--;
    }
}

void Game_BattlerBase::resetStateCounts() {
    _stateTurns.clear();
    for (int i = 0; i < _states.size(); ++i) {
        _stateTurns.append(0);
    }
}

QString Game_BattlerBase::mostImportantStateText() const {
    return QString();
}

QString Game_BattlerBase::iconIndex() const {
    return QString();
}

bool Game_BattlerBase::canInput() const {
    return !isDead() && !isConfused();
}

bool Game_BattlerBase::canMove() const {
    return !isDead();
}

int Game_BattlerBase::speed() const {
    return 1;
}

int Game_BattlerBase::param(int paramId) const {
    return 100;
}

int Game_BattlerBase::xparam(int xparamId) const {
    return 0;
}

int Game_BattlerBase::sparam(int sparamId) const {
    return 100;
}

bool Game_BattlerBase::isSkillTypeSealed(int skillTypeId) const {
    return false;
}

bool Game_BattlerBase::isEquipTypeSealed(int equipTypeId) const {
    return false;
}

bool Game_BattlerBase::isEquipLocked(int slotId) const {
    return false;
}

bool Game_BattlerBase::canEquip(int itemId) const {
    return true;
}

bool Game_BattlerBase::canUse(int itemId) const {
    return true;
}

int Game_BattlerBase::elementRate(int elementId) const {
    return 100;
}

double Game_BattlerBase::debuffRate(int paramId) const {
    return 100.0;
}

int Game_BattlerBase::stateRate(int stateId) const {
    return 100;
}

int Game_BattlerBase::stateResistSet() const {
    return 0;
}

int Game_BattlerBase::isStateResist(int stateId) const {
    return false;
}

bool Game_BattlerBase::isSkillWtypeOk(int skillId) const {
    return true;
}

bool Game_BattlerBase::isSkilledWeaponByType(int wtypeId) const {
    return true;
}

bool Game_BattlerBase::attackElements() const {
    return false;
}

bool Game_BattlerBase::guardElements() const {
    return false;
}

int Game_BattlerBase::debuffMax() const {
    return 2;
}

int Game_BattlerBase::stateGroups() const {
    return 0;
}

bool Game_BattlerBase::isGroupDefeat() const {
    return false;
}

int Game_BattlerBase::faceName() const {
    return 0;
}

int Game_BattlerBase::faceIndex() const {
    return 0;
}

int Game_BattlerBase::charIndex() const {
    return 0;
}

QString Game_BattlerBase::characterName() const {
    return QString();
}

bool Game_BattlerBase::isSpriteVisible() const {
    return true;
}

QString Game_BattlerBase::battlerName() const {
    return QString();
}

bool Game_BattlerBase::isConfused() const {
    return isStateAffected(1);
}

void Game_BattlerBase::performActionStart() {
}

void Game_BattlerBase::performAction() {
}

void Game_BattlerBase::performActionEnd() {
}

void Game_BattlerBase::performDamage() {
}

void Game_BattlerBase::performMiss() {
}

void Game_BattlerBase::performRecovery() {
}

void Game_BattlerBase::performEvasion() {
}

void Game_BattlerBase::performMagicEvasion() {
}

void Game_BattlerBase::performCounter() {
}

void Game_BattlerBase::performReflection() {
}

void Game_BattlerBase::performSubstitute() {
}
