#include "../../include/core/GameActorFull.h"
#include "../../include/utils/MathUtils.h"

namespace LunaLite {
namespace Core {

GameActorFull::GameActorFull(int actorId)
    : GameObject(actorId), _level(1), _exp(0), _hp(30), _maxHp(30),
      _mp(10), _maxMp(10), _tp(0), _weapon(0) {
    initialize();
}

GameActorFull::~GameActorFull() {
}

int GameActorFull::getLevel() const {
    return _level;
}

void GameActorFull::setLevel(int level) {
    _level = Math::Utils::clamp(level, 1, 99);
}

int GameActorFull::getExp() const {
    return _exp;
}

void GameActorFull::addExp(int amount) {
    _exp += amount;
    while (_exp >= getNextLevelExp() && _level < 99) {
        _level++;
        _exp -= getNextLevelExp();
    }
}

int GameActorFull::getNextLevelExp() const {
    return _level * 10 + (_level * _level);
}

int GameActorFull::getHp() const {
    return _hp;
}

void GameActorFull::setHp(int hp) {
    _hp = Math::Utils::clamp(hp, 0, _maxHp);
}

int GameActorFull::getMaxHp() const {
    return _maxHp;
}

int GameActorFull::getMp() const {
    return _mp;
}

void GameActorFull::setMp(int mp) {
    _mp = Math::Utils::clamp(mp, 0, _maxMp);
}

int GameActorFull::getMaxMp() const {
    return _maxMp;
}

int GameActorFull::getTp() const {
    return _tp;
}

void GameActorFull::setTp(int tp) {
    _tp = Math::Utils::clamp(tp, 0, 100);
}

Parameter GameActorFull::getParameters() const {
    Parameter params = _baseParams;
    params.hp += _paramBonuses.hp;
    params.mp += _paramBonuses.mp;
    params.atk += _paramBonuses.atk;
    params.def += _paramBonuses.def;
    params.mat += _paramBonuses.mat;
    params.mdf += _paramBonuses.mdf;
    params.agi += _paramBonuses.agi;
    params.luk += _paramBonuses.luk;
    return params;
}

int GameActorFull::getParam(int paramId) const {
    Parameter p = getParameters();
    switch (paramId) {
        case 0: return p.hp;
        case 1: return p.mp;
        case 2: return p.atk;
        case 3: return p.def;
        case 4: return p.mat;
        case 5: return p.mdf;
        case 6: return p.agi;
        case 7: return p.luk;
    }
    return 0;
}

void GameActorFull::addParameterBonus(int paramId, int value) {
    switch (paramId) {
        case 0: _paramBonuses.hp += value; break;
        case 1: _paramBonuses.mp += value; break;
        case 2: _paramBonuses.atk += value; break;
        case 3: _paramBonuses.def += value; break;
        case 4: _paramBonuses.mat += value; break;
        case 5: _paramBonuses.mdf += value; break;
        case 6: _paramBonuses.agi += value; break;
        case 7: _paramBonuses.luk += value; break;
    }
}

bool GameActorFull::isStateAffected(StateId stateId) const {
    return _states.contains(stateId);
}

void GameActorFull::addState(StateId stateId) {
    if (!_states.contains(stateId)) {
        _states.append(stateId);
    }
}

void GameActorFull::removeState(StateId stateId) {
    _states.removeAll(stateId);
}

void GameActorFull::clearStates() {
    _states.clear();
}

void GameActorFull::equip(WeaponId weaponId, const QVector<ArmorId> &armors) {
    _weapon = weaponId;
    _armors = armors;
}

WeaponId GameActorFull::getWeapon() const {
    return _weapon;
}

QVector<ArmorId> GameActorFull::getArmors() const {
    return _armors;
}

void GameActorFull::learnSkill(SkillId skillId) {
    if (!_skills.contains(skillId)) {
        _skills.append(skillId);
    }
}

void GameActorFull::forgetSkill(SkillId skillId) {
    _skills.removeAll(skillId);
}

bool GameActorFull::hasSkill(SkillId skillId) const {
    return _skills.contains(skillId);
}

QVector<SkillId> GameActorFull::getSkills() const {
    return _skills;
}

bool GameActorFull::isAlive() const {
    return _hp > 0 && !isStateAffected(1);  // 1 = death state
}

bool GameActorFull::isDead() const {
    return !isAlive();
}

bool GameActorFull::isCancel() const {
    return isStateAffected(2);  // 2 = cancel state
}

int GameActorFull::getBuff(int paramId) const {
    return _buffs.value(paramId, 0);
}

void GameActorFull::addBuff(int paramId, int stages) {
    _buffs[paramId] = Math::Utils::clamp(_buffs[paramId] + stages, -4, 4);
}

void GameActorFull::removeBuff(int paramId, int stages) {
    _buffs[paramId] = Math::Utils::clamp(_buffs[paramId] - stages, -4, 4);
}

void GameActorFull::clearBuffs() {
    _buffs.clear();
}

void GameActorFull::initialize() {
    _baseParams.hp = 30;
    _baseParams.mp = 10;
    _baseParams.atk = 10;
    _baseParams.def = 5;
    _baseParams.mat = 8;
    _baseParams.mdf = 6;
    _baseParams.agi = 7;
    _baseParams.luk = 4;
    
    clearStates();
    clearBuffs();
}

void GameActorFull::update() {
}

} // namespace Core
} // namespace LunaLite
