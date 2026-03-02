#include "../../include/wolfman/Core.h"

namespace WolfManAlpha {

Engine& Engine::instance() {
    static Engine engine;
    return engine;
}

Engine::Engine()
    : _initialized(false), _running(false), _debugMode(false),
      _width(816), _height(624), _title("WolfMan Alpha Engine"),
      _fps(0), _deltaTime(0), _frameCount(0) {
}

Engine::~Engine() {
    shutdown();
}

bool Engine::initialize(int width, int height, const QString &title) {
    if (_initialized) return false;
    
    _width = width;
    _height = height;
    _title = title;
    _initialized = true;
    _running = true;
    
    return true;
}

void Engine::shutdown() {
    _running = false;
    _initialized = false;
}

bool Engine::isInitialized() const {
    return _initialized;
}

void Engine::update(float deltaTime) {
    if (!_running) return;
    _deltaTime = deltaTime;
    _frameCount++;
    _fps = (1.0f / deltaTime);
}

void Engine::render() {
}

bool Engine::isRunning() const {
    return _running;
}

void Engine::requestShutdown() {
    _running = false;
}

QString Engine::getEngineVersion() const {
    return VERSION_STRING;
}

int Engine::getWidth() const {
    return _width;
}

int Engine::getHeight() const {
    return _height;
}

QString Engine::getTitle() const {
    return _title;
}

float Engine::getFps() const {
    return _fps;
}

float Engine::getDeltaTime() const {
    return _deltaTime;
}

int Engine::getFrameCount() const {
    return _frameCount;
}

bool Engine::isDebugMode() const {
    return _debugMode;
}

void Engine::setDebugMode(bool enabled) {
    _debugMode = enabled;
}

long long Engine::getTotalMemoryUsage() const {
    // Would calculate total memory usage
    return 0;
}

void Engine::reportMemoryUsage() const {
    // Would report memory usage to console/logger
}

} // namespace WolfManAlpha
