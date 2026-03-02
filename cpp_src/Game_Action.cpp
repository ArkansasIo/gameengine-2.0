#include "Game_Action.h"

Game_Action::Game_Action(int subjectIndex)
    : _subjectActorIndex(subjectIndex), _isPlugin(false) {
}

Game_Action::~Game_Action() {
}

void Game_Action::clear() {
    _itemObject.clear();
    _item.clear();
    _targets.clear();
}

void Game_Action::setSubject(int subjectIndex) {
    _subjectActorIndex = subjectIndex;
}

int Game_Action::subject() const {
    return _subjectActorIndex;
}

int Game_Action::friendsUnit() const {
    return _subjectActorIndex / 4;
}

int Game_Action::opponentsUnit() const {
    return 1 - friendsUnit();
}

bool Game_Action::isValid() const {
    return !_item.isEmpty();
}

bool Game_Action::isForOpponent() const {
    return _item.contains("forOpponent");
}

bool Game_Action::isForFriend() const {
    return _item.contains("forFriend");
}

bool Game_Action::isForDeadFriend() const {
    return _item.contains("forDeadFriend");
}

bool Game_Action::isForUser() const {
    return _item.contains("forUser");
}

bool Game_Action::isForOne() const {
    return _item.contains("forOne");
}

bool Game_Action::isForRandom() const {
    return _item.contains("forRandom");
}

bool Game_Action::isForAll() const {
    return _item.contains("forAll");
}

int Game_Action::numTargets() const {
    if (isForOne()) return 1;
    return 0;
}

void Game_Action::setItemObject(const QString &item) {
    _itemObject = item;
}

QString Game_Action::itemObject() const {
    return _itemObject;
}

int Game_Action::speed() const {
    return 1;
}

int Game_Action::makeTargets() const {
    if (isForUser()) {
        return subject();
    }
    return 0;
}

bool Game_Action::testApply(int targetIndex) const {
    return testLifeAndDeath(targetIndex);
}

bool Game_Action::testLifeAndDeath(int targetIndex) const {
    return true;
}

void Game_Action::apply(int targetIndex) {
    itemEffectApply(targetIndex);
}

bool Game_Action::testSkillEffect(int targetIndex) const {
    return true;
}

bool Game_Action::testItemEffect(int targetIndex) const {
    return true;
}

void Game_Action::itemEffectApply(int targetIndex) {
}

void Game_Action::itemEffectRecovery(int targetIndex) {
}

void Game_Action::itemEffectCommonDamage(int targetIndex) {
}

void Game_Action::itemEffectCommonRecovery(int targetIndex) {
}

void Game_Action::itemEffectRemoving(int targetIndex) {
}

void Game_Action::itemEffectRecoveringHP(int targetIndex) {
}

void Game_Action::itemEffectRecoveringMP(int targetIndex) {
}

void Game_Action::itemEffectGainTP(int targetIndex) {
}

void Game_Action::itemEffectAddingState(int targetIndex) {
}

void Game_Action::itemEffectRemovingState(int targetIndex) {
}

void Game_Action::itemEffectAddingBuff(int targetIndex) {
}

void Game_Action::itemEffectAddingDebuff(int targetIndex) {
}

void Game_Action::itemEffectRemovingBuff(int targetIndex) {
}

void Game_Action::itemEffectRemovingDebuff(int targetIndex) {
}

void Game_Action::itemEffectSpecial(int targetIndex) {
}

void Game_Action::itemEffectGrowth(int targetIndex) {
}

void Game_Action::itemEffectLearnSkill(int targetIndex) {
}

bool Game_Action::testActionEffect() const {
    return true;
}

bool Game_Action::testItemStateEffect() const {
    return true;
}
