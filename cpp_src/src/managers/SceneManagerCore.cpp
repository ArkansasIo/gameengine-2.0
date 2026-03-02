#include "../../include/managers/SceneManagerCore.h"

namespace LunaLite {
namespace Managers {

SceneManager& SceneManager::instance() {
    static SceneManager manager;
    return manager;
}

SceneManager::SceneManager() : _currentScene(nullptr) {
}

SceneManager::~SceneManager() {
    popAll();
}

void SceneManager::changeScene(Scenes::SceneBase* scene) {
    if (_currentScene) {
        _currentScene->stop();
        delete _currentScene;
    }
    _currentScene = scene;
    if (_currentScene) {
        _currentScene->start();
    }
}

void SceneManager::pushScene(Scenes::SceneBase* scene) {
    if (_currentScene) {
        _sceneStack.push(_currentScene);
    }
    _currentScene = scene;
    if (_currentScene) {
        _currentScene->start();
    }
}

void SceneManager::popScene() {
    if (_currentScene) {
        _currentScene->stop();
        delete _currentScene;
    }
    
    if (!_sceneStack.isEmpty()) {
        _currentScene = _sceneStack.pop();
        if (_currentScene) {
            _currentScene->start();
        }
    } else {
        _currentScene = nullptr;
    }
}

void SceneManager::popAll() {
    while (!_sceneStack.isEmpty()) {
        auto scene = _sceneStack.pop();
        if (scene) {
            scene->stop();
            delete scene;
        }
    }
    
    if (_currentScene) {
        _currentScene->stop();
        delete _currentScene;
        _currentScene = nullptr;
    }
}

Scenes::SceneBase* SceneManager::getCurrentScene() const {
    return _currentScene;
}

Scenes::SceneBase* SceneManager::getPreviousScene() const {
    if (!_sceneStack.isEmpty()) {
        return _sceneStack.top();
    }
    return nullptr;
}

int SceneManager::getSceneCount() const {
    return _sceneStack.size() + (_currentScene ? 1 : 0);
}

bool SceneManager::isSceneActive() const {
    return _currentScene && _currentScene->isActive();
}

bool SceneManager::isSceneReady() const {
    return _currentScene && _currentScene->isReady();
}

void SceneManager::update() {
    if (_currentScene) {
        _currentScene->update();
    }
}

void SceneManager::render() {
    if (_currentScene) {
        _currentScene->render();
    }
}

QString SceneManager::getCurrentSceneName() const {
    if (_currentScene) {
        return _currentScene->getSceneName();
    }
    return "No Scene";
}

} // namespace Managers
} // namespace LunaLite
