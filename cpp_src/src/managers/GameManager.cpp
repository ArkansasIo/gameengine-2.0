#include "../../include/managers/GameManager.h"
#include "../../include/utils/TimeManager.h"
#include "SceneManagerCore.h"

namespace LunaLite {
namespace Managers {

GameManager& GameManager::instance() {
    static GameManager manager;
    return manager;
}

GameManager::GameManager()
    : _initialized(false), _running(false), _paused(false), _debugMode(false),
      _gameName("LunaLite"), _width(816), _height(624), _frameCount(0) {
}

GameManager::~GameManager() {
    shutdown();
}

bool GameManager::initialize(int width, int height, const QString &gameName) {
    if (_initialized) return false;
    
    _width = width;
    _height = height;
    _gameName = gameName;
    
    _running = true;
    _initialized = true;
    
    return true;
}

void GameManager::update() {
    if (!_running || _paused) return;
    
    _frameCount++;
    
    // Update scene manager
    SceneManager::instance().update();
    
    // Update time manager
    Utilities::TimeManager::instance().getDeltaTime();
}

void GameManager::render() {
    if (!_running) return;
    
    // Render scene manager
    SceneManager::instance().render();
}

void GameManager::shutdown() {
    _running = false;
    _initialized = false;
    SceneManager::instance().popAll();
}

Core::StateMachine::GameState GameManager::getGameState() const {
    // Would query StateMachine
    return Core::StateMachine::BOOT;
}

void GameManager::setGameState(Core::StateMachine::GameState state) {
    // Would set StateMachine state
}

QString GameManager::getGameName() const {
    return _gameName;
}

int GameManager::getGameWidth() const {
    return _width;
}

int GameManager::getGameHeight() const {
    return _height;
}

bool GameManager::isRunning() const {
    return _running;
}

bool GameManager::isPaused() const {
    return _paused;
}

void GameManager::pause() {
    _paused = true;
}

void GameManager::resume() {
    _paused = false;
}

double GameManager::getDeltaTime() const {
    return Utilities::TimeManager::instance().getDeltaTimeFloat();
}

int GameManager::getFps() const {
    return Utilities::TimeManager::instance().getFps();
}

int GameManager::getFrameCount() const {
    return _frameCount;
}

bool GameManager::isDebugMode() const {
    return _debugMode;
}

void GameManager::setDebugMode(bool enabled) {
    _debugMode = enabled;
}

} // namespace Managers
} // namespace LunaLite
