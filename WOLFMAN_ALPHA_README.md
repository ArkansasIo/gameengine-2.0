# WolfMan Alpha Game Engine Library

## Version: 1.0.0

Professional game engine framework for C++ game development with complete feature set for 2D/3D games.

---

## Core Systems

### 1. Engine Core (`Core.h`)
- Main engine initialization and lifecycle management
- Frame timing and FPS counting
- Engine state management
- Memory usage tracking
- Debug mode support

**Key Classes:**
- `Engine` - Main engine singleton

---

### 2. Entity Component System (`EntityComponentSystem.h`)
- Hierarchical entity/actor system with parent-child relationships
- Component-based architecture for flexible entity structure
- Dynamic component management and queries
- Scene graph with layer management
- Entity lifecycle (initialize, update, destroy)

**Key Classes:**
- `Entity` - Game object with component support
- `Component` - Base class for all entity components
- `EntityManager` - Global entity/scene management

---

### 3. Physics Engine (`Physics.h`)
- 2D/3D physics simulation
- Rigid body dynamics with mass, velocity, acceleration
- Collision detection (circle, box, polygon)
- Force and impulse application
- Gravity and environmental forces
- Physics constraints (distance, hinge)
- Raycasting and overlap queries
- Sleep/wake system for optimization

**Key Classes:**
- `Physics` - Physics simulation singleton
- `RigidBody` - Physics body data
- `Collider` - Collision shape definition
- `Vector2D` - 2D math vector

---

### 4. Renderer (`Renderer.h`)
- 2D sprite rendering system
- Text rendering with font support
- Primitive shapes (rectangles, circles, lines, polygons)
- Layered rendering with depth control
- Camera system with position, zoom, rotation
- Blend modes (Normal, Add, Multiply, Screen)
- Scissor/clipping regions
- Rendering statistics and optimization

**Key Classes:**
- `Renderer` - Main rendering system singleton
- `DrawCommand` - Rendering command buffer entry

---

## Manager Systems

### 5. Input Manager (`InputManager.h`)
- Keyboard input handling
- Mouse input with position tracking
- Gamepad/controller support
- Touch input for mobile devices
- Input event callbacks
- Key repeat logic
- Device capability queries

**Key Classes:**
- `InputManager` - Input handling singleton
- `KeyCode` - Enumeration of all input keys

---

### 6. Audio Manager (`AudioManager.h`)
- Audio playback (sound effects, music, voice)
- Volume control per audio type
- Volume and pitch adjustment
- Fade in/out effects
- 3D positional audio support
- Reverb and EQ effects
- Audio loading and unloading

**Key Classes:**
- `AudioManager` - Audio system singleton
- `AudioSource` - Individual audio track
- `AudioSourceType` - Audio classification

---

### 7. Particle System (`ParticleSystem.h`)
- Particle emission and simulation
- Customizable emitter properties
- Particle lifetime, velocity, scale, color
- Built-in effects (explosion, smoke, sparks, rain)
- Emission shapes (point, circle, box, line)
- Particle physics integration

**Key Classes:**
- `ParticleSystem` - Global particle manager
- `ParticleEmitter` - Individual particle emitter
- `Particle` - Individual particle data

---

## Advanced Systems

### 8. AI System (`AI.h`)
- Pathfinding with A* algorithm
- Navigation mesh support
- Steering behaviors:
  - Seek, Flee, Arrive
  - Wander, Pursue, Evade
  - Flocking (separation, alignment, cohesion)
- Path smoothing
- Finite State Machines for AI agents
- Behavior trees (extensible)
- Decision trees for decision making

**Key Classes:**
- `PathFinder` - Global pathfinding system
- `AIAgent` - Individual AI agent
- `AIState` - FSM state base class
- `BehaviorNode` - Behavior tree node
- `Decision` - Decision tree node

---

### 9. Scripting System (`Scripting.h`)
- Script context management
- Variable storage and retrieval
- Function registration and calling
- Event scripting support
- Script execution engine
- Callback system
- Debug output for scripting

**Key Classes:**
- `ScriptingSystem` - Global scripting manager
- `ScriptContext` - Individual script context
- `EventScript` - Event-triggered script

---

### 10. Network System (`Network.h`)
- TCP/UDP networking
- Client-server architecture
- Peer-to-peer communication
- Message and packet sending
- Network callbacks and events
- Connection management
- Network statistics (ping, packet loss, speeds)

**Key Classes:**
- `NetworkManager` - Global network manager
- `NetworkServer` - Server for hosting games
- `NetworkPeer` - Individual network connection

---

## Development Tools

### 11. Debug System (`Debug.h`)
- Logging system with multiple log levels
- Debug overlay for real-time information
- FPS, memory, and entity count display
- Debug drawing (lines, circles, text)
- Performance profiling
- Log history management

**Key Classes:**
- `Logger` - Logging system singleton
- `DebugOverlay` - Visual debug information
- `Profiler` - Performance measurement

---

## Master Integration Class

### WolfMan Class (`WolfManAlpha.h`)
Quick access to all engine systems through single interface:

```cpp
WolfMan& engine = WolfMan::instance();
engine.initialize(1280, 720, "My Game");

// Access any system
engine.getRenderer().drawSprite("hero", 100, 100);
engine.getInput().isKeyDown(KeyCode::Up);
engine.getAudio().playAudio("bgm");

while (engine.isRunning()) {
    engine.update(deltaTime);
    engine.render();
}
```

---

## Usage Example

```cpp
#include "wolfman/WolfManAlpha.h"

int main() {
    using namespace WolfManAlpha;
    
    WolfMan& engine = WolfMan::instance();
    
    // Initialize
    if (!engine.initialize(1280, 720, "WolfMan Game")) {
        return 1;
    }
    
    // Create entity with components
    auto player = engine.getEntities().createEntity("player");
    
    // Main loop
    while (engine.isRunning()) {
        float deltaTime = 0.016f;  // 60 FPS
        
        engine.update(deltaTime);
        engine.render();
    }
    
    engine.shutdown();
    return 0;
}
```

---

## Features Overview

✅ **Core Engine**: Initialization, main loop, memory management  
✅ **Graphics**: Sprite rendering, text, shapes, camera system  
✅ **Physics**: 2D simulation, collision, forces, constraints  
✅ **Input**: Keyboard, mouse, gamepad, touch  
✅ **Audio**: Music, SFX, voice, 3D audio, effects  
✅ **Particles**: Emission, effects, physics integration  
✅ **AI**: Pathfinding, steering, FSM, behavior trees  
✅ **Scripting**: Script execution, events, callbacks  
✅ **Networking**: Multiplayer, server, P2P  
✅ **Tools**: Profiling, logging, debug overlay  

---

## Performance Characteristics

- **Memory**: Efficient pooling and singleton pattern
- **Rendering**: Batch rendering with layer culling
- **Physics**: Broad-phase collision with AABB
- **AI**: A* pathfinding with caching
- **Scripting**: Context-based execution

---

## Compatibility

- **Language**: C++17+
- **Frameworks**: Qt 5.12+, Qt 6.0+
- **Platforms**: Windows, Linux, macOS
- **Graphics**: OpenGL-based rendering

---

## License

WolfMan Alpha Engine - Open Source Game Development Framework
