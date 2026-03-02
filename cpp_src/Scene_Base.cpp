#include "Scene_Base.h"

Scene_Base::Scene_Base()
    : _ready(false), _active(false), _transitioning(false), 
      _transitionCount(0), _transitionSpeed(1) {
}

Scene_Base::~Scene_Base() {
}

void Scene_Base::initialize() {
    _ready = true;
    _active = true;
}

void Scene_Base::create() {
}

void Scene_Base::start() {
}

void Scene_Base::update() {
}

void Scene_Base::stop() {
    _active = false;
}

void Scene_Base::terminate() {
}

bool Scene_Base::isReady() const {
    return _ready;
}

bool Scene_Base::isActive() const {
    return _active;
}

bool Scene_Base::isTransitioning() const {
    return _transitioning;
}

bool Scene_Base::isRequested() const {
    return false;
}

void Scene_Base::setTransitionColor(int r, int g, int b) {
}

void Scene_Base::setTransitionSpeed(int speed) {
    _transitionSpeed = speed;
}
