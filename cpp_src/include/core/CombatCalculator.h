#ifndef COMBAT_CALCULATOR_H
#define COMBAT_CALCULATOR_H

#include "../utils/Types.h"

namespace LunaLite {
namespace Combat {

class CombatCalculator {
public:
    static CombatCalculator& instance();
    
    // Damage calculation
    int calculateDamage(const Parameter &attacker, const Parameter &defender, 
                        int power, int accuracy);
    int calculateHealing(int basePower, int mat);
    
    // Critical hit
    bool isCritical(int agi, float critRate);
    
    // Accuracy and evasion
    bool checkHit(int accuracy, int evasion);
    
    // State application
    bool applyState(int stateRate);
    
    // Experience and gold
    int calculateExp(int enemyLevel, int difference);
    int calculateGold(int baseGold, float multiplier = 1.0f);
    
    // Parameter calculation
    Parameter calculateActorParams(Parameter base, int level, 
                                   const Damage &equips);
    
    // Skill MP cost
    int calculateSkillCost(int baseMpCost, int mat);
    
    // Buff/Debuff effects
    float getBuffRate(int buffLevel) const;
    
private:
    CombatCalculator();
    ~CombatCalculator();
};

} // namespace Combat
} // namespace LunaLite

#endif // COMBAT_CALCULATOR_H
