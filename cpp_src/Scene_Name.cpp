#include "Scene_Name.h"

Scene_Name::Scene_Name() : _actorId(0), _editWindow(nullptr), _inputWindow(nullptr) {
}

Scene_Name::~Scene_Name() {
}

void Scene_Name::initialize() {
    Scene_Base::initialize();
}

void Scene_Name::create() {
    Scene_Base::create();
}

void Scene_Name::start() {
    Scene_Base::start();
}

void Scene_Name::update() {
    Scene_Base::update();
}

void Scene_Name::stop() {
    Scene_Base::stop();
}

void Scene_Name::terminate() {
    Scene_Base::terminate();
}

void Scene_Name::onInputOk() {
}

void Scene_Name::onInputCancel() {
}
