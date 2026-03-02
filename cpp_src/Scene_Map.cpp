#include "Scene_Map.h"

Scene_Map::Scene_Map() {
}

Scene_Map::~Scene_Map() {
}

void Scene_Map::initialize() {
    Scene_Base::initialize();
}

void Scene_Map::create() {
    Scene_Base::create();
    createDisplayObjects();
    loadMapData();
}

void Scene_Map::start() {
    Scene_Base::start();
}

void Scene_Map::update() {
    Scene_Base::update();
    updateTransferPlayer();
    updateEncounter();
    updateCallMenu();
    updateCallSave();
    updateCallDebug();
}

void Scene_Map::stop() {
    Scene_Base::stop();
}

void Scene_Map::terminate() {
    Scene_Base::terminate();
}

bool Scene_Map::shouldAutosave() const {
    return true;
}

void Scene_Map::updateTransferPlayer() {
}

void Scene_Map::updateEncounter() {
}

void Scene_Map::updateCallMenu() {
}

void Scene_Map::updateCallSave() {
}

void Scene_Map::updateCallDebug() {
}

void Scene_Map::updateShowDebugCommands() {
}

void Scene_Map::updateShowHideDebugMenu() {
}

void Scene_Map::launchBattle() {
}

void Scene_Map::createDisplayObjects() {
}

void Scene_Map::loadMapData() {
}

void Scene_Map::onMapLoaded() {
}

void Scene_Map::fadeInForTransfer() {
}

void Scene_Map::fadeOutForTransfer() {
}
