#include "../../include/core/CombatCalculator.h"
#include "../utils/MathUtils.h"

namespace LunaLite {
namespace Combat {

CombatCalculator& CombatCalculator::instance() {
    static CombatCalculator calc;
    return calc;
}

CombatCalculator::CombatCalculator() {
}

CombatCalculator::~CombatCalculator() {
}

int CombatCalculator::calculateDamage(const Parameter &attacker, 
                                      const Parameter &defender, 
                                      int power, int accuracy) {
    float baseDamage = (attacker.atk * 4 - defender.def * 2) / 4.0f;
    baseDamage = Math::Utils::clamp(baseDamage, 0.0f, 9999.0f);
    
    float variance = baseDamage * 0.15f;
    float randomVariance = Math::Utils::randomFloat(-variance, variance);
    float totalDamage = baseDamage + randomVariance;
    
    if (!checkHit(accuracy, defender.agi)) {
        return 0;
    }
    
    return Math::Utils::clamp(static_cast<int>(totalDamage), 0, 9999);
}

int CombatCalculator::calculateHealing(int basePower, int mat) {
    return Math::Utils::clamp(basePower + (mat * 2), 1, 9999);
}

bool CombatCalculator::isCritical(int agi, float critRate) {
    float critChance = critRate + (agi * 0.01f);
    return Math::Utils::randomChance(critChance);
}

bool CombatCalculator::checkHit(int accuracy, int evasion) {
    float hitRate = 1.0f - (evasion - accuracy) * 0.01f;
    hitRate = Math::Utils::clamp(hitRate, 0.0f, 1.0f);
    return Math::Utils::randomChance(hitRate);
}

bool CombatCalculator::applyState(int stateRate) {
    return Math::Utils::randomChance(stateRate / 100.0f);
}

int CombatCalculator::calculateExp(int enemyLevel, int difference) {
    int base = 10 + (enemyLevel * 2);
    float rate = 1.0f;
    
    if (difference < 0) {
        rate = 1.0f + (difference * 0.05f);
    } else if (difference > 0) {
        rate = 1.0f + (difference * 0.1f);
    }
    
    return Math::Utils::clamp(static_cast<int>(base * rate), 1, 9999);
}

int CombatCalculator::calculateGold(int baseGold, float multiplier) {
    int gold = static_cast<int>(baseGold * multiplier);
    int variance = gold / 4;
    return Math::Utils::clamp(
        gold + Math::Utils::randomInt(-variance, variance), 
        1, 9999
    );
}

Parameter CombatCalculator::calculateActorParams(Parameter base, int level, 
                                                const Damage &equips) {
    Parameter result = base;
    result.hp = Math::Utils::clamp(result.hp + (level - 1) * 5, 1, 9999);
    result.mp = Math::Utils::clamp(result.mp + (level - 1) * 5, 0, 9999);
    return result;
}

int CombatCalculator::calculateSkillCost(int baseMpCost, int mat) {
    int cost = baseMpCost - (mat / 4);
    return Math::Utils::clamp(cost, 1, 9999);
}

float CombatCalculator::getBuffRate(int buffLevel) const {
    float base = 1.0f;
    return base + (buffLevel * 0.25f);
}

} // namespace Combat
} // namespace LunaLite
