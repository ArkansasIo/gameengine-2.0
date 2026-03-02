#include "Scene_Skill.h"

Scene_Skill::Scene_Skill() : _skillTypeWindow(nullptr), _skillListWindow(nullptr), _statusWindow(nullptr) {
}

Scene_Skill::~Scene_Skill() {
}

void Scene_Skill::initialize() {
    Scene_Base::initialize();
}

void Scene_Skill::create() {
    Scene_Base::create();
}

void Scene_Skill::start() {
    Scene_Base::start();
}

void Scene_Skill::update() {
    Scene_Base::update();
}

void Scene_Skill::stop() {
    Scene_Base::stop();
}

void Scene_Skill::terminate() {
    Scene_Base::terminate();
}

void Scene_Skill::onPersonalOk() {
}

void Scene_Skill::onPersonalCancel() {
}

void Scene_Skill::onSkillOk() {
}

void Scene_Skill::onSkillCancel() {
}
