#include "Scene_Battle.h"

Scene_Battle::Scene_Battle() : _logWindow(nullptr), _battlePhase(0) {
}

Scene_Battle::~Scene_Battle() {
}

void Scene_Battle::initialize() {
    Scene_Base::initialize();
}

void Scene_Battle::create() {
    Scene_Base::create();
}

void Scene_Battle::start() {
    Scene_Base::start();
}

void Scene_Battle::update() {
    Scene_Base::update();
    updateBattleProcess();
}

void Scene_Battle::stop() {
    Scene_Base::stop();
}

void Scene_Battle::terminate() {
    Scene_Base::terminate();
}

void Scene_Battle::updateBattleProcess() {
}

void Scene_Battle::changeInputWindow() {
}

void Scene_Battle::startPartyCommandSelection() {
}

void Scene_Battle::startActorCommandSelection() {
}

void Scene_Battle::selectNextCommand() {
}

void Scene_Battle::selectPreviousCommand() {
}

void Scene_Battle::startActorSelection() {
}

void Scene_Battle::startEnemySelection() {
}

void Scene_Battle::onActorOk() {
}

void Scene_Battle::onActorCancel() {
}

void Scene_Battle::onEnemyOk() {
}

void Scene_Battle::onEnemyCancel() {
}
