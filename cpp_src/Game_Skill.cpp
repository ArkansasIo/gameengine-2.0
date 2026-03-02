#include "Game_Skill.h"

Game_Skill::Game_Skill(int skillId) : _skillId(skillId) {
}

Game_Skill::~Game_Skill() {
}

int Game_Skill::skillId() const {
    return _skillId;
}

QString Game_Skill::name() const {
    return "";
}

QString Game_Skill::description() const {
    return "";
}

int Game_Skill::type1() const {
    return 0;
}

int Game_Skill::type2() const {
    return 0;
}

int Game_Skill::mpCost() const {
    return 0;
}

int Game_Skill::scope() const {
    return 0;
}

bool Game_Skill::isSkill() const {
    return true;
}

bool Game_Skill::isDamage() const {
    return false;
}

bool Game_Skill::isRecover() const {
    return false;
}
