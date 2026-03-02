#include "Scene_Gameover.h"

Scene_Gameover::Scene_Gameover() : _waitCount(0) {
}

Scene_Gameover::~Scene_Gameover() {
}

void Scene_Gameover::initialize() {
    Scene_Base::initialize();
}

void Scene_Gameover::create() {
    Scene_Base::create();
}

void Scene_Gameover::start() {
    Scene_Base::start();
    playGameoverMusic();
}

void Scene_Gameover::update() {
    Scene_Base::update();
    if (_waitCount > 0) {
        _waitCount--;
    }
}

void Scene_Gameover::stop() {
    Scene_Base::stop();
}

void Scene_Gameover::terminate() {
    Scene_Base::terminate();
}

void Scene_Gameover::playGameoverMusic() {
}

void Scene_Gameover::waitCount() const {
}

void Scene_Gameover::setWaitCount(int count) {
    _waitCount = count;
}

void Scene_Gameover::gotoTitle() {
}

void Scene_Gameover::gotoMenu() {
}
