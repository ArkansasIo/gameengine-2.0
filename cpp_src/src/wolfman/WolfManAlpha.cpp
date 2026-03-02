#include "../../include/wolfman/WolfManAlpha.h"

namespace WolfManAlpha {

WolfMan& WolfMan::instance() {
    static WolfMan wolfman;
    return wolfman;
}

WolfMan::WolfMan()
    : _engine(Engine::instance()),
      _renderer(Renderer::instance()),
      _input(InputManager::instance()),
      _audio(AudioManager::instance()),
      _physics(Physics::instance()),
      _entities(EntityManager::instance()),
      _particles(ParticleSystem::instance()),
      _pathFinder(PathFinder::instance()),
      _scripting(ScriptingSystem::instance()),
      _network(NetworkManager::instance()),
      _logger(Logger::instance()),
      _debug(DebugOverlay::instance()),
      _profiler(Profiler::instance()) {
}

WolfMan::~WolfMan() {
    shutdown();
}

bool WolfMan::initialize(int width, int height, const QString &title) {
    _logger.info("Initializing WolfMan Alpha Engine...");
    
    if (!_engine.initialize(width, height, title)) {
        _logger.error("Failed to initialize engine");
        return false;
    }
    
    if (!_renderer.initialize(width, height)) {
        _logger.error("Failed to initialize renderer");
        return false;
    }
    
    _logger.info("WolfMan Alpha " + QString(VERSION_STRING) + " initialized successfully");
    return true;
}

Engine& WolfMan::getEngine() {
    return _engine;
}

Renderer& WolfMan::getRenderer() {
    return _renderer;
}

InputManager& WolfMan::getInput() {
    return _input;
}

AudioManager& WolfMan::getAudio() {
    return _audio;
}

Physics& WolfMan::getPhysics() {
    return _physics;
}

EntityManager& WolfMan::getEntities() {
    return _entities;
}

ParticleSystem& WolfMan::getParticles() {
    return _particles;
}

PathFinder& WolfMan::getPathFinder() {
    return _pathFinder;
}

ScriptingSystem& WolfMan::getScripting() {
    return _scripting;
}

NetworkManager& WolfMan::getNetwork() {
    return _network;
}

Logger& WolfMan::getLogger() {
    return _logger;
}

DebugOverlay& WolfMan::getDebug() {
    return _debug;
}

Profiler& WolfMan::getProfiler() {
    return _profiler;
}

void WolfMan::update(float deltaTime) {
    _profiler.beginProfile("engine_update");
    
    if (!_engine.isRunning()) return;
    
    _engine.update(deltaTime);
    _input.update();
    _physics.simulate(deltaTime);
    _entities.updateAll(deltaTime);
    _particles.update(deltaTime);
    _scripting.update(deltaTime);
    _network.update();
    _audio.update(deltaTime);
    _debug.update();
    
    _profiler.endProfile("engine_update");
}

void WolfMan::render() {
    _profiler.beginProfile("engine_render");
    
    _renderer.beginFrame();
    _entities.renderAll();
    _particles.render();
    _debug.render();
    _renderer.endFrame();
    _renderer.present();
    
    _profiler.endProfile("engine_render");
}

bool WolfMan::isRunning() const {
    return _engine.isRunning();
}

void WolfMan::shutdown() {
    _logger.info("Shutting down WolfMan Alpha Engine...");
    _network.disconnectFromServer();
    _network.stopServer();
    _audio.stopAll();
    _entities.destroyAllEntities();
    _particles.ParticleSystem::~ParticleSystem();
    _engine.shutdown();
    _logger.info("WolfMan Alpha Engine shut down");
}

} // namespace WolfManAlpha
