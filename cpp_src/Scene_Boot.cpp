#include "Scene_Boot.h"

Scene_Boot::Scene_Boot() : _databaseLoaded(false) {
}

Scene_Boot::~Scene_Boot() {
}

void Scene_Boot::initialize() {
    Scene_Base::initialize();
}

void Scene_Boot::create() {
    Scene_Base::create();
    loadDatabase();
}

void Scene_Boot::start() {
    Scene_Base::start();
    loadImages();
}

void Scene_Boot::update() {
    Scene_Base::update();
}

void Scene_Boot::stop() {
    Scene_Base::stop();
}

void Scene_Boot::terminate() {
    Scene_Base::terminate();
}

void Scene_Boot::checkPlayerLocation() {
}

void Scene_Boot::updateDocumentTitle() {
}

void Scene_Boot::loadDatabase() {
    _databaseLoaded = true;
}

void Scene_Boot::loadImages() {
}

void Scene_Boot::startNewGame() {
}
