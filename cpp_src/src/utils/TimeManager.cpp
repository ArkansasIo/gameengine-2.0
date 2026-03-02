#include "../../include/utils/TimeManager.h"

TimeManager& TimeManager::instance() {
    static TimeManager manager;
    return manager;
}

TimeManager::TimeManager()
    : QObject(), _deltaTime(0.0), _frameCount(0), _fps(0), _frameTime(0.0f),
      _paused(false), _timeScale(1.0f), _targetFps(60) {
}

TimeManager::~TimeManager() {
}

void TimeManager::initialize(int targetFps) {
    _targetFps = targetFps;
    _lastFrameTime = std::chrono::high_resolution_clock::now();
    _frameCount = 0;
    _fps = 0;
}

void TimeManager::update() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - _lastFrameTime;
    
    if (!_paused) {
        _deltaTime = elapsed.count() * _timeScale;
    } else {
        _deltaTime = 0.0;
    }
    
    _frameTime = static_cast<float>(_deltaTime);
    _lastFrameTime = currentTime;
    
    _frameCount++;
    if (_frameCount % _targetFps == 0) {
        _fps = static_cast<int>(1.0 / std::max(_deltaTime, 0.0001));
    }
}

double TimeManager::getDeltaTime() const {
    return _deltaTime;
}

float TimeManager::getDeltaTimeFloat() const {
    return _frameTime;
}

int TimeManager::getFrameCount() const {
    return _frameCount;
}

int TimeManager::getFps() const {
    return _fps;
}

float TimeManager::getFrameTime() const {
    return _frameTime;
}

void TimeManager::pause() {
    _paused = true;
}

void TimeManager::resume() {
    _paused = false;
}

bool TimeManager::isPaused() const {
    return _paused;
}

void TimeManager::setTimeScale(float scale) {
    _timeScale = scale;
}

float TimeManager::getTimeScale() const {
    return _timeScale;
}
