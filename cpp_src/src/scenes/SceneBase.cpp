#include "../../include/scenes/SceneBase.h"

namespace LunaLite {
namespace Scenes {

SceneBase::SceneBase(const QString &name)
    : GameObject(0), _sceneName(name), _active(false), _ready(false), _updateCount(0) {
}

SceneBase::~SceneBase() {
}

QString SceneBase::getSceneName() const {
    return _sceneName;
}

void SceneBase::start() {
    _active = true;
    _ready = true;
}

void SceneBase::update() {
    if (_active) {
        _updateCount++;
    }
}

void SceneBase::render() {
}

void SceneBase::stop() {
    _active = false;
}

bool SceneBase::isActive() const {
    return _active;
}

bool SceneBase::isReady() const {
    return _ready;
}

int SceneBase::getUpdateCount() const {
    return _updateCount;
}

void SceneBase::initialize() {
    _updateCount = 0;
}

} // namespace Scenes
} // namespace LunaLite
