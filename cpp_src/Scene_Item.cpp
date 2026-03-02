#include "Scene_Item.h"

Scene_Item::Scene_Item() : _helpWindow(nullptr), _categoryWindow(nullptr), _itemWindow(nullptr) {
}

Scene_Item::~Scene_Item() {
}

void Scene_Item::initialize() {
    Scene_Base::initialize();
}

void Scene_Item::create() {
    Scene_Base::create();
}

void Scene_Item::start() {
    Scene_Base::start();
}

void Scene_Item::update() {
    Scene_Base::update();
}

void Scene_Item::stop() {
    Scene_Base::stop();
}

void Scene_Item::terminate() {
    Scene_Base::terminate();
}

void Scene_Item::onItemOk() {
}

void Scene_Item::onItemCancel() {
}

void Scene_Item::onCategoryOk() {
}

void Scene_Item::onCategoryCancel() {
}
