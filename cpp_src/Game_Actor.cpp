#include "Game_Actor.h"

Game_Actor::Game_Actor(int actorId)
    : _actorId(actorId), _level(1), _exp(0), _hp(100), _mp(50), _tp(0) {
}

Game_Actor::~Game_Actor() {
}

void Game_Actor::setup(int actorId) {
    _actorId = actorId;
    _name = "Actor";
    _nickname = "";
    _level = 1;
    _exp = 0;
}

QString Game_Actor::name() const {
    return _name;
}

QString Game_Actor::nickname() const {
    return _nickname;
}

int Game_Actor::profile() const {
    return 0;
}

int Game_Actor::actorId() const {
    return _actorId;
}

bool Game_Actor::isBattleMember() const {
    return true;
}

bool Game_Actor::isFormationChangeOk() const {
    return true;
}

int Game_Actor::faceIndex() const {
    return 0;
}

QString Game_Actor::charIndex() const {
    return QString();
}

QString Game_Actor::battlerName() const {
    return QString();
}

int Game_Actor::exp() const {
    return _exp;
}

void Game_Actor::changeExp(int exp, bool display) {
    _exp = exp;
}

int Game_Actor::nextRequiredExp() const {
    return 100 * _level;
}

int Game_Actor::nextLevelExp() const {
    return nextRequiredExp();
}

int Game_Actor::currentLevelExp() const {
    return _exp;
}

void Game_Actor::levelUp() {
    _level++;
}

void Game_Actor::levelDown() {
    if (_level > 1) _level--;
}

void Game_Actor::initEquips(const QList<int> &equips) {
    _equips = equips;
}

void Game_Actor::changeEquip(int slotId, int weaponId) {
    if (slotId < _equips.size()) {
        _equips[slotId] = weaponId;
    }
}

void Game_Actor::forceChangeEquip(int slotId, int armorId) {
    changeEquip(slotId, armorId);
}

void Game_Actor::changeEquipById(int equipId, int slotId) {
    changeEquip(slotId, equipId);
}

bool Game_Actor::isEquipped(int itemId) const {
    return _equips.contains(itemId);
}

void Game_Actor::discardEquip(int itemId) {
    int index = _equips.indexOf(itemId);
    if (index >= 0) {
        _equips[index] = 0;
    }
}

bool Game_Actor::canEquip(int itemId) const {
    return true;
}

int Game_Actor::weaponTypes() const {
    return 1;
}

int Game_Actor::armorTypes() const {
    return 1;
}

bool Game_Actor::isSkillLearned(int skillId) const {
    return _skills.contains(skillId);
}

void Game_Actor::learnSkill(int skillId) {
    if (!_skills.contains(skillId)) {
        _skills.append(skillId);
    }
}

void Game_Actor::forgetSkill(int skillId) {
    _skills.removeAll(skillId);
}

bool Game_Actor::hasStrongRecoverySkill() const {
    return false;
}

int Game_Actor::skillPoints() const {
    return 0;
}

void Game_Actor::setSkillPoints(int sp) {
}

bool Game_Actor::isStrongWeapon(int weaponId) const {
    return false;
}

bool Game_Actor::isHigherLevel(int level) const {
    return _level >= level;
}

int Game_Actor::param(int paramId) const {
    int base = 100;
    return base + (_level - 1) * 5;
}

void Game_Actor::addParam(int paramId, int value) {
    if (_params.contains(paramId)) {
        _params[paramId] += value;
    } else {
        _params[paramId] = value;
    }
}

void Game_Actor::setParam(int paramId, int value) {
    _params[paramId] = value;
}

QList<int> Game_Actor::equips() const {
    return _equips;
}

int Game_Actor::weapon(int index) const {
    return index < _equips.size() ? _equips[index] : 0;
}

int Game_Actor::armor(int index) const {
    return index < _equips.size() ? _equips[index] : 0;
}

bool Game_Actor::hasArmor(int armorId) const {
    return _equips.contains(armorId);
}

int Game_Actor::atk() const {
    return param(2);
}

int Game_Actor::def() const {
    return param(3);
}

int Game_Actor::mat() const {
    return param(4);
}

int Game_Actor::mdf() const {
    return param(5);
}

int Game_Actor::agi() const {
    return param(6);
}

int Game_Actor::luk() const {
    return param(7);
}

void Game_Actor::initTp() {
    _tp = 0;
}

void Game_Actor::maxTp() const {
}

void Game_Actor::resetTp() {
    _tp = 0;
}

int Game_Actor::tpRate() const {
    return _tp;
}

int Game_Actor::hide() const {
    return 0;
}

void Game_Actor::setHide(int isHide) {
}

int Game_Actor::performActionStart() {
    return 0;
}

int Game_Actor::performAttack() const {
    return 0;
}

int Game_Actor::performGuard() const {
    return 0;
}

int Game_Actor::performLossyAction() const {
    return 0;
}

QString Game_Actor::makeAutoBattleActions() {
    return QString();
}

QString Game_Actor::name2() const {
    return _nickname;
}

int Game_Actor::makeCommandList() const {
    return 0;
}

int Game_Actor::getMultipleHits() const {
    return 1;
}
