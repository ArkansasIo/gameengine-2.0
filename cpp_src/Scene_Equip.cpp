#include "Scene_Equip.h"

Scene_Equip::Scene_Equip() : _actorId(0), _statusWindow(nullptr), _commandWindow(nullptr), 
                              _slotWindow(nullptr), _itemWindow(nullptr) {
}

Scene_Equip::~Scene_Equip() {
}

void Scene_Equip::initialize() {
    Scene_Base::initialize();
}

void Scene_Equip::create() {
    Scene_Base::create();
}

void Scene_Equip::start() {
    Scene_Base::start();
}

void Scene_Equip::update() {
    Scene_Base::update();
}

void Scene_Equip::stop() {
    Scene_Base::stop();
}

void Scene_Equip::terminate() {
    Scene_Base::terminate();
}

void Scene_Equip::onSlotOk() {
}

void Scene_Equip::onSlotCancel() {
}

void Scene_Equip::onItemOk() {
}

void Scene_Equip::onItemCancel() {
}

void Scene_Equip::onActorChange() {
}
