#include "Scene_Load.h"

Scene_Load::Scene_Load() : _listWindow(nullptr) {
}

Scene_Load::~Scene_Load() {
}

void Scene_Load::initialize() {
    Scene_Base::initialize();
}

void Scene_Load::create() {
    Scene_Base::create();
}

void Scene_Load::start() {
    Scene_Base::start();
}

void Scene_Load::update() {
    Scene_Base::update();
}

void Scene_Load::stop() {
    Scene_Base::stop();
}

void Scene_Load::terminate() {
    Scene_Base::terminate();
}

void Scene_Load::onSavefileOk() {
}

void Scene_Load::onSavefileCancel() {
}

void Scene_Load::executeLoad(int saveIndex) {
}

bool Scene_Load::isValidSavefileIndex(int index) const {
    return true;
}
