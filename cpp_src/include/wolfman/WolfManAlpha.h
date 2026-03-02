#ifndef WOLFMAN_ALPHA_H
#define WOLFMAN_ALPHA_H

// WolfMan Alpha - Professional Game Engine Library
// Version: 1.0.0
// Complete game development framework with all core systems

// Core systems
#include "Core.h"
#include "EntityComponentSystem.h"
#include "Physics.h"
#include "Renderer.h"

// Managers
#include "InputManager.h"
#include "AudioManager.h"
#include "ParticleSystem.h"

// Advanced systems
#include "AI.h"
#include "Scripting.h"
#include "Network.h"

// Development tools
#include "Debug.h"

namespace WolfManAlpha {

// Quick access helper
class WolfMan {
public:
    static WolfMan& instance();
    
    // Initialize all systems
    bool initialize(int width, int height, const QString &title);
    
    // Access systems
    Engine& getEngine();
    Renderer& getRenderer();
    InputManager& getInput();
    AudioManager& getAudio();
    Physics& getPhysics();
    EntityManager& getEntities();
    ParticleSystem& getParticles();
    PathFinder& getPathFinder();
    ScriptingSystem& getScripting();
    NetworkManager& getNetwork();
    Logger& getLogger();
    DebugOverlay& getDebug();
    Profiler& getProfiler();
    
    // Main loop
    void update(float deltaTime);
    void render();
    bool isRunning() const;
    void shutdown();
    
    // Helper functions
    static QString getVersion() { return VERSION_STRING; }
    static void logInfo(const QString &msg) { Logger::instance().info(msg); }
    static void logError(const QString &msg) { Logger::instance().error(msg); }
    static void logWarning(const QString &msg) { Logger::instance().warning(msg); }
    
private:
    WolfMan();
    ~WolfMan();
    
    Engine& _engine;
    Renderer& _renderer;
    InputManager& _input;
    AudioManager& _audio;
    Physics& _physics;
    EntityManager& _entities;
    ParticleSystem& _particles;
    PathFinder& _pathFinder;
    ScriptingSystem& _scripting;
    NetworkManager& _network;
    Logger& _logger;
    DebugOverlay& _debug;
    Profiler& _profiler;
};

} // namespace WolfManAlpha

#endif // WOLFMAN_ALPHA_H
