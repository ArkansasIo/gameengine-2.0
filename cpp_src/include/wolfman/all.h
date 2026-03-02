/// Master WolfMan Alpha Engine Header
/// Include this file to get access to all WolfMan Alpha systems

#ifndef WOLFMAN_ALL_H
#define WOLFMAN_ALL_H

// ============================================================================
// WolfMan Alpha - Complete Game Engine Library
// ============================================================================
// Version: 1.0.0
// Purpose: Comprehensive 2D game engine with advanced features
// Framework: Qt 5.12+ / Qt 6.0+
// Standard: C++17
// ============================================================================

// Core Engine
#include "wolfman/Core.h"

// Entity-Component System
#include "wolfman/EntityComponentSystem.h"

// Physics Simulation
#include "wolfman/Physics.h"

// Graphics & Rendering
#include "wolfman/Renderer.h"

// Input Management
#include "wolfman/InputManager.h"

// Audio System
#include "wolfman/AudioManager.h"

// Particle Effects
#include "wolfman/ParticleSystem.h"

// AI & Decision Making
#include "wolfman/AI.h"

// Scripting System
#include "wolfman/Scripting.h"

// Network Communication
#include "wolfman/Network.h"

// Debug & Development Tools
#include "wolfman/Debug.h"

// Utilities (Math, String, Random, Colors)
#include "wolfman/Utils.h"

// Master Integration Class
#include "wolfman/WolfManAlpha.h"

// ============================================================================
// Quick Start Usage Example
// ============================================================================
/*

#include "wolfman/all.h"

int main() {
    // Initialize engine
    WolfManAlpha::WolfMan& engine = WolfManAlpha::WolfMan::instance();
    if (!engine.initialize(1280, 720, "My Game")) {
        return 1;
    }
    
    // Get subsystems
    auto& renderer = engine.getRenderer();
    auto& input = engine.getInput();
    auto& audio = engine.getAudio();
    auto& physics = engine.getPhysics();
    auto& entities = engine.getEntities();
    
    // Main game loop
    while (engine.isRunning()) {
        engine.update(16.67f / 1000.0f); // Assuming 60 FPS
        engine.render();
    }
    
    engine.shutdown();
    return 0;
}

*/

// ============================================================================
// Features Summary
// ============================================================================
/*

### Graphics & Rendering (Renderer)
- Sprite rendering with full transforms
- Text rendering with custom fonts
- Primitive shapes (rectangles, circles, lines, polygons)
- Camera system with zoom and rotation
- Layer-based rendering
- Blend modes (Normal, Add, Multiply, Screen)

### Physics & Collision (Physics)
- 2D rigid body dynamics
- Multiple collider types (Circle, AABB, Polygon)
- Collision detection and response
- Force and impulse simulation
- Gravity and constraints
- Raycasting and overlap queries

### Input Handling (InputManager)
- Keyboard input (26+ keys)
- Mouse input with deltas and wheel
- Gamepad/controller support
- Touch input with multi-touch
- Key repeat and state tracking
- Event callbacks

### Audio System (AudioManager)
- Multiple audio source types (Music, SFX, Voice, etc.)
- Volume and pitch control
- Fade effects (in, out, to)
- 3D positional audio
- Audio effects and EQ
- Per-type volume management

### Particles & Effects (ParticleSystem)
- Flexible particle emitters
- Pre-built effects (explosions, smoke, sparks, rain)
- Custom particle physics
- Emission shapes (point, circle, box, line)
- Spread and angle control

### AI & Pathfinding (AI)
- A* pathfinding algorithm
- Navigation mesh support
- 8 steering behaviors (seek, flee, wander, etc.)
- Flocking algorithms (separation, alignment, cohesion)
- Finite state machines
- Behavior and decision trees

### Scripting System (Scripting)
- Script context management
- Variable storage and retrieval
- Function registration and calling
- Event-triggered scripts
- Debug mode support

### Networking (Network)
- Server hosting (up to N clients)
- Client connection
- Message and packet transmission
- Connection callbacks
- Network statistics (ping, packet loss)
- P2P communication support

### Entity System (EntityComponentSystem)
- Hierarchical entity management
- Template-based component system
- Scene graph with parent-child relationships
- Layer system for depth ordering
- Entity lifecycle management

### Debugging Tools (Debug)
- Multi-level logging system (Debug, Info, Warning, Error, Critical)
- Real-time debug overlay
- Performance profiler
- Memory usage tracking
- FPS and entity count display

### Utilities (Utils)
- Math helper functions (clamp, lerp, easing, trig)
- String manipulation (split, join, trim, replace)
- Random number generation
- Type conversions
- Color utilities

*/

// ============================================================================
// Namespace Organization
// ============================================================================
/*

All WolfMan Alpha classes are organized in the WolfManAlpha namespace:

WolfManAlpha::
├── Core (Engine lifecycle)
├── Entity (Hierarchical entity)
├── Component (Base component class)
├── EntityManager (Entity management singleton)
├── Physics (Physics engine singleton)
├── Vector2D (2D vector math)
├── RigidBody (Physics object)
├── Collider (Collision shape)
├── Renderer (Graphics rendering singleton)
├── InputManager (Input handling singleton)
├── AudioManager (Audio system singleton)
├── AudioSource (Audio playback)
├── ParticleSystem (Particle system singleton)
├── ParticleEmitter (Particle generator)
├── AI (AI systems collection)
├── PathFinder (Pathfinding singleton)
├── AIAgent (AI-controlled entity)
├── Scripting (Scripting system singleton)
├── ScriptContext (Script execution context)
├── Network (Networking singleton)
├── Debug (Debug tools singleton)
├── Logger (Logging system)
├── DebugOverlay (Debug visualization)
├── Profiler (Performance profiler)
├── Utils:: (Utilities sub-namespace)
│   ├── Math (Math utilities)
│   ├── String (String manipulation)
│   ├── Random (Random generation)
│   ├── Convert (Type conversion)
│   └── Color (Color utilities)
└── WolfMan (Master integration class)

*/

#endif // WOLFMAN_ALL_H
