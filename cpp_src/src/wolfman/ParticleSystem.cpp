#include "../../include/wolfman/ParticleSystem.h"

namespace WolfManAlpha {

ParticleEmitter::ParticleEmitter()
    : _emissionRate(10), _minLifetime(0.5f), _maxLifetime(2.0f),
      _playing(false), _emissionCounter(0), _shape(0) {
}

ParticleEmitter::~ParticleEmitter() {
    _particles.clear();
}

void ParticleEmitter::setPosition(float x, float y) {
    _position = Vector2D(x, y);
}

void ParticleEmitter::setEmissionRate(int particlesPerSecond) {
    _emissionRate = particlesPerSecond;
}

void ParticleEmitter::setParticleLifetime(float minTime, float maxTime) {
    _minLifetime = minTime;
    _maxLifetime = maxTime;
}

void ParticleEmitter::setInitialVelocity(float minX, float maxX, float minY, float maxY) {
    // Store velocity ranges
}

void ParticleEmitter::setInitialScale(float min, float max) {
    // Store scale ranges
}

void ParticleEmitter::setInitialColor(int startColor, int endColor) {
    // Store color ranges
}

void ParticleEmitter::play() {
    _playing = true;
}

void ParticleEmitter::pause() {
    _playing = false;
}

void ParticleEmitter::stop() {
    _playing = false;
    _particles.clear();
}

bool ParticleEmitter::isPlaying() const {
    return _playing;
}

void ParticleEmitter::update(float deltaTime) {
    if (!_playing) return;
    
    // Emit new particles
    _emissionCounter += _emissionRate * deltaTime;
    while (_emissionCounter >= 1.0f) {
        Particle p;
        p.position = _position;
        _particles.append(p);
        _emissionCounter -= 1.0f;
    }
    
    // Update existing particles
    for (int i = _particles.size() - 1; i >= 0; --i) {
        _particles[i].lifetime -= deltaTime;
        if (_particles[i].lifetime <= 0) {
            _particles.remove(i);
        } else {
            _particles[i].position = _particles[i].position + _particles[i].velocity * deltaTime;
            _particles[i].velocity = _particles[i].velocity + _particles[i].acceleration * deltaTime;
        }
    }
}

const QVector<Particle>& ParticleEmitter::getParticles() const {
    return _particles;
}

void ParticleEmitter::setShape(int shape) {
    _shape = shape;
}

void ParticleEmitter::setSpread(float angle, float spread) {
    // Set emission spread parameters
}

ParticleSystem& ParticleSystem::instance() {
    static ParticleSystem system;
    return system;
}

ParticleSystem::ParticleSystem() {
}

ParticleSystem::~ParticleSystem() {
    for (auto emitter : _emitters) {
        delete emitter;
    }
    _emitters.clear();
}

ParticleEmitter* ParticleSystem::createEmitter(const QString &name) {
    auto emitter = new ParticleEmitter();
    _emitters[name] = emitter;
    return emitter;
}

ParticleEmitter* ParticleSystem::getEmitter(const QString &name) {
    return _emitters.value(name, nullptr);
}

void ParticleSystem::destroyEmitter(const QString &name) {
    if (_emitters.contains(name)) {
        delete _emitters[name];
        _emitters.remove(name);
    }
}

void ParticleSystem::update(float deltaTime) {
    for (auto emitter : _emitters) {
        if (emitter) {
            emitter->update(deltaTime);
        }
    }
}

void ParticleSystem::render() {
    // Render all particles
}

void ParticleSystem::createExplosionEffect(float x, float y, int particleCount) {
    auto emitter = createEmitter("explosion");
    emitter->setPosition(x, y);
    emitter->play();
}

void ParticleSystem::createSmokEffect(float x, float y) {
    auto emitter = createEmitter("smoke");
    emitter->setPosition(x, y);
}

void ParticleSystem::createSparkEffect(float x, float y, float angle) {
    auto emitter = createEmitter("spark");
    emitter->setPosition(x, y);
}

void ParticleSystem::createRainEffect(int width, int height, int particleCount) {
    auto emitter = createEmitter("rain");
}

} // namespace WolfManAlpha
