#include "../../include/wolfman/InputManager.h"

namespace WolfManAlpha {

InputManager& InputManager::instance() {
    static InputManager manager;
    return manager;
}

InputManager::InputManager()
    : _mouseX(0), _mouseY(0), _mouseDeltaX(0), _mouseDeltaY(0), _mouseWheelDelta(0) {
}

InputManager::~InputManager() {
}

bool InputManager::isKeyDown(KeyCode key) {
    return _keyDown.value(key, false);
}

bool InputManager::isKeyPressed(KeyCode key) {
    return _keyPressed.value(key, false);
}

bool InputManager::isKeyReleased(KeyCode key) {
    return _keyReleased.value(key, false);
}

int InputManager::getMouseX() const {
    return _mouseX;
}

int InputManager::getMouseY() const {
    return _mouseY;
}

float InputManager::getMouseDeltaX() const {
    return _mouseDeltaX;
}

float InputManager::getMouseDeltaY() const {
    return _mouseDeltaY;
}

int InputManager::getMouseWheelDelta() const {
    return _mouseWheelDelta;
}

bool InputManager::isMouseButtonDown(KeyCode button) {
    return _keyDown.value(button, false);
}

float InputManager::getGamepadAxisX(int gamepadIndex) const {
    return 0.0f;  // Would query gamepad
}

float InputManager::getGamepadAxisY(int gamepadIndex) const {
    return 0.0f;
}

float InputManager::getGamepadTriggerLeft(int gamepadIndex) const {
    return 0.0f;
}

float InputManager::getGamepadTriggerRight(int gamepadIndex) const {
    return 0.0f;
}

bool InputManager::isGamepadConnected(int gamepadIndex) const {
    return false;
}

int InputManager::getGamepadCount() const {
    return 0;
}

int InputManager::getTouchCount() const {
    return 0;
}

float InputManager::getTouchX(int index) const {
    return 0.0f;
}

float InputManager::getTouchY(int index) const {
    return 0.0f;
}

bool InputManager::isTouchActive(int index) const {
    return false;
}

void InputManager::onKeyDown(InputCallback callback) {
    // Register callback
}

void InputManager::onKeyUp(InputCallback callback) {
    // Register callback
}

void InputManager::onMouseMove(std::function<void(int, int)> callback) {
    // Register callback
}

bool InputManager::hasKeyboard() const {
    return true;
}

bool InputManager::hasMouse() const {
    return true;
}

bool InputManager::hasGamepad() const {
    return false;
}

bool InputManager::hasTouchScreen() const {
    return false;
}

void InputManager::update() {
    _keyPressed.clear();
    _keyReleased.clear();
    _mouseDeltaX = 0;
    _mouseDeltaY = 0;
    _mouseWheelDelta = 0;
}

void InputManager::reset() {
    _keyDown.clear();
    _keyPressed.clear();
    _keyReleased.clear();
}

} // namespace WolfManAlpha
