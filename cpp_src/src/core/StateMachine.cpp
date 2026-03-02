#include "../../include/core/StateMachine.h"

namespace LunaLite {
namespace Core {

StateMachine::StateMachine()
    : _currentState(GameState::BOOT), _previousState(GameState::BOOT),
      _nextState(GameState::BOOT), _transitioning(false), _transitionTimer(0) {
}

StateMachine::~StateMachine() {
}

void StateMachine::setState(GameState newState) {
    if (newState != _currentState) {
        _previousState = _currentState;
        _nextState = newState;
        _transitioning = true;
        _transitionTimer = 30; // 30 frames for transition
    }
}

GameState StateMachine::getState() const {
    return _currentState;
}

GameState StateMachine::getPreviousState() const {
    return _previousState;
}

bool StateMachine::isTransitioning() const {
    return _transitioning;
}

void StateMachine::updateTransition() {
    if (_transitioning) {
        _transitionTimer--;
        if (_transitionTimer <= 0) {
            _currentState = _nextState;
            _transitioning = false;
        }
    }
}

QString StateMachine::getStateName() const {
    switch (_currentState) {
        case GameState::BOOT: return "Boot";
        case GameState::TITLE: return "Title";
        case GameState::MENU: return "Menu";
        case GameState::MAP: return "Map";
        case GameState::BATTLE: return "Battle";
        case GameState::PAUSE: return "Pause";
        case GameState::SHUTDOWN: return "Shutdown";
    }
    return "Unknown";
}

} // namespace Core
} // namespace LunaLite
