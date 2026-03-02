#include "Scene_Title.h"

Scene_Title::Scene_Title() {
}

Scene_Title::~Scene_Title() {
}

void Scene_Title::initialize() {
    Scene_Base::initialize();
}

void Scene_Title::create() {
    Scene_Base::create();
    createBackground();
    createForeground();
    createWindowLayer();
}

void Scene_Title::start() {
    Scene_Base::start();
    playTitleMusic();
}

void Scene_Title::update() {
    Scene_Base::update();
}

void Scene_Title::stop() {
    Scene_Base::stop();
}

void Scene_Title::terminate() {
    Scene_Base::terminate();
}

void Scene_Title::createBackground() {
}

void Scene_Title::createForeground() {
}

void Scene_Title::createWindowLayer() {
}

void Scene_Title::drawGameTitle() {
}

void Scene_Title::centerSprite() {
}

void Scene_Title::playTitleMusic() {
}

void Scene_Title::commandNewGame() {
}

void Scene_Title::commandContinue() {
}

void Scene_Title::commandOptions() {
}
