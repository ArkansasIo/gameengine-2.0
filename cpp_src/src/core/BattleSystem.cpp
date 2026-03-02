#include "../../include/core/BattleSystem.h"
#include "../../include/core/CombatCalculator.h"

namespace LunaLite {
namespace Core {

BattleSystem& BattleSystem::instance() {
    static BattleSystem system;
    return system;
}

BattleSystem::BattleSystem()
    : _active(false), _turnCount(0), _currentActionIndex(0) {
}

BattleSystem::~BattleSystem() {
    endBattle();
}

void BattleSystem::startBattle(const QVector<GameActorFull*> &allies,
                               const QVector<GameActorFull*> &enemies) {
    _allies = allies;
    _enemies = enemies;
    _active = true;
    _turnCount = 0;
    _actionQueue.clear();
    _currentActionIndex = 0;
}

void BattleSystem::endBattle() {
    _allies.clear();
    _enemies.clear();
    _actionQueue.clear();
    _active = false;
    _turnCount = 0;
}

bool BattleSystem::isBattleActive() const {
    return _active;
}

void BattleSystem::nextTurn() {
    if (_active) {
        _turnCount++;
        _actionQueue.clear();
        _currentActionIndex = 0;
    }
}

int BattleSystem::getTurnCount() const {
    return _turnCount;
}

void BattleSystem::queueAction(GameActorFull* actor, const BattleAction &action) {
    if (_active && actor) {
        ActionEntry entry;
        entry.actor = actor;
        entry.action = action;
        _actionQueue.append(entry);
    }
}

void BattleSystem::executeNextAction() {
    if (_currentActionIndex >= _actionQueue.size()) {
        return;
    }
    
    ActionEntry &entry = _actionQueue[_currentActionIndex];
    GameActorFull* actor = entry.actor;
    BattleAction &action = entry.action;
    
    _lastResult = BattleResult();
    
    switch (action.type) {
        case BattleAction::Attack: {
            if (action.targetIndex < _enemies.size()) {
                GameActorFull* target = _enemies[action.targetIndex];
                CombatCalculator &calc = CombatCalculator::instance();
                
                Parameter actorParams = actor->getParameters();
                Parameter targetParams = target->getParameters();
                
                _lastResult.critical = calc.isCritical(actorParams.atk, 0);
                _lastResult.hit = calc.checkHit(100, targetParams.agi);
                
                if (_lastResult.hit) {
                    _lastResult.damage = calc.calculateDamage(
                        actorParams.atk, targetParams.def, 15, 100, 80
                    );
                    target->setHp(target->getHp() - _lastResult.damage);
                } else {
                    _lastResult.missed = true;
                }
            }
            break;
        }
        
        case BattleAction::Skill: {
            Parameter actorParams = actor->getParameters();
            if (actorParams.mp >= 5) {
                actor->setMp(actor->getMp() - 5);
                if (action.targetIndex < _enemies.size()) {
                    GameActorFull* target = _enemies[action.targetIndex];
                    CombatCalculator &calc = CombatCalculator::instance();
                    Parameter targetParams = target->getParameters();
                    
                    _lastResult.damage = calc.calculateDamage(
                        actorParams.mat * 2, targetParams.mdf, 20, 100, 85
                    );
                    target->setHp(target->getHp() - _lastResult.damage);
                }
            }
            break;
        }
        
        case BattleAction::Defend: {
            // Add defense buff - increases defense by 1 stage
            actor->addBuff(3, 1);  // paramId 3 = DEF
            _lastResult.hit = true;
            break;
        }
        
        case BattleAction::Item:
        case BattleAction::Escape:
        case BattleAction::None:
        default:
            _lastResult.hit = false;
            break;
    }
    
    _currentActionIndex++;
}

bool BattleSystem::hasActionsQueued() const {
    return _currentActionIndex < _actionQueue.size();
}

QVector<GameActorFull*> BattleSystem::getAllies() const {
    return _allies;
}

QVector<GameActorFull*> BattleSystem::getEnemies() const {
    return _enemies;
}

GameActorFull* BattleSystem::getCurrentActor() const {
    if (_currentActionIndex < _actionQueue.size()) {
        return _actionQueue[_currentActionIndex].actor;
    }
    return nullptr;
}

BattleResult BattleSystem::getLastResult() const {
    return _lastResult;
}

bool BattleSystem::isVictory() const {
    if (!_active) return false;
    for (auto enemy : _enemies) {
        if (enemy->isAlive()) {
            return false;
        }
    }
    return true;
}

bool BattleSystem::isDefeat() const {
    if (!_active) return false;
    for (auto ally : _allies) {
        if (ally->isAlive()) {
            return false;
        }
    }
    return true;
}

} // namespace Core
} // namespace LunaLite
