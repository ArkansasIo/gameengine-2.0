#include "Scene_Status.h"

Scene_Status::Scene_Status() : _actorId(0), _statusWindow(nullptr) {
}

Scene_Status::~Scene_Status() {
}

void Scene_Status::initialize() {
    Scene_Base::initialize();
}

void Scene_Status::create() {
    Scene_Base::create();
}

void Scene_Status::start() {
    Scene_Base::start();
}

void Scene_Status::update() {
    Scene_Base::update();
}

void Scene_Status::stop() {
    Scene_Base::stop();
}

void Scene_Status::terminate() {
    Scene_Base::terminate();
}

void Scene_Status::nextActor() {
}

void Scene_Status::previousActor() {
}

void Scene_Status::onActorOk() {
}

void Scene_Status::onActorCancel() {
}
