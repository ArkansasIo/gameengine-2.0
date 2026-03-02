#include "EffectManager.h"

EffectManager& EffectManager::instance() {
    static EffectManager instance;
    return instance;
}

EffectManager::EffectManager() {
}

EffectManager::~EffectManager() {
}

void EffectManager::initialize() {
}

void EffectManager::playBattleObjectAnimation(int objectId, int animationId) {
}

void EffectManager::playBattleSystemAnimation(int animationId, int targetId) {
}

void EffectManager::playScreenFlash(int p1, int p2, int p3, int duration) {
}

void EffectManager::playScreenShake(int power, int speed, int duration) {
}
