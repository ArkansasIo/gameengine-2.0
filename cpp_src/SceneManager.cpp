#include "SceneManager.h"
#include "Graphics.h"
#include "Input.h"
#include "TouchInput.h"

Scene* SceneManager::_scene = nullptr;
Scene* SceneManager::_nextScene = nullptr;
bool SceneManager::_sceneStarted = false;
bool SceneManager::_exiting = false;
bool SceneManager::_previousClass = false;
bool SceneManager::_backgroundBitmap = false;
int SceneManager::_screenWidth = 816;
int SceneManager::_screenHeight = 624;
int SceneManager::_boxWidth = 816;
int SceneManager::_boxHeight = 624;
int SceneManager::_deltaTime = 1000 / 60;
long long SceneManager::_currentTime = 0;
long long SceneManager::_accumulator = 0;

void SceneManager::run() {
    initialize();
    while (!_exiting) {
        update();
    }
    terminate();
}

void SceneManager::initialize() {
    initGraphics();
    initAudio();
    initInput();
}

void SceneManager::initGraphics() {
    Graphics::initialize(_screenWidth, _screenHeight);
}

void SceneManager::initAudio() {
}

void SceneManager::initInput() {
    Input::initialize();
    TouchInput::initialize();
}

void SceneManager::initNwjs() {
}

void SceneManager::checkBrowser() {
}

void SceneManager::checkPluginErrors() {
}

void SceneManager::setupErrorHandlers() {
}

void SceneManager::requestUpdate() {
    update();
}

void SceneManager::update() {
    updateInputData();
    changeScene();
    updateScene();
    renderScene();
    updateMain();
}

void SceneManager::terminate() {
}

void SceneManager::onError(const char* error) {
}

void SceneManager::onKeyDown(int event) {
}

void SceneManager::catchException(const char* error) {
}

void SceneManager::updateInputData() {
    Input::update();
    TouchInput::update();
}

void SceneManager::updateMain() {
    Graphics::tickEnd();
}

void SceneManager::changeScene() {
    if (_nextScene && _scene != _nextScene) {
        if (_scene) {
            _scene->stop();
            _scene->terminate();
            delete _scene;
        }
        _scene = _nextScene;
        _nextScene = nullptr;
        if (_scene) {
            _scene->create();
            _sceneStarted = false;
        }
    }
}

void SceneManager::updateScene() {
    if (_scene) {
        if (!_sceneStarted && _scene->isReady()) {
            _scene->start();
            _sceneStarted = true;
            onSceneStart();
        }
        if (_sceneStarted) {
            _scene->update();
        }
    }
}

void SceneManager::renderScene() {
    Graphics::render();
}

void SceneManager::onSceneCreate() {
}

void SceneManager::onSceneStart() {
}

void SceneManager::onSceneLoading() {
}

bool SceneManager::isSceneChanging() {
    return _nextScene != nullptr;
}

bool SceneManager::isCurrentSceneBusy() {
    return _scene && _scene->isBusy();
}

bool SceneManager::isCurrentSceneStarted() {
    return _sceneStarted;
}

bool SceneManager::isNextScene(Scene* sceneClass) {
    return _nextScene == sceneClass;
}

void SceneManager::goto_(Scene* sceneClass) {
    _nextScene = sceneClass;
}

void SceneManager::push(Scene* sceneClass) {
    _nextScene = sceneClass;
}

void SceneManager::pop() {
}

void SceneManager::exit() {
    _exiting = true;
}

void SceneManager::clearStack() {
}

void SceneManager::stop() {
}

void SceneManager::prepareNextScene() {
}

void SceneManager::snap() {
}

void SceneManager::snapForBackground() {
}

void SceneManager::backgroundBitmap() {
}
