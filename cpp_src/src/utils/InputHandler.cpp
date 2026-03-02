#include "../../include/utils/InputHandler.h"
#include <QApplication>
#include <QKeyEvent>

InputHandler& InputHandler::instance() {
    static InputHandler handler;
    return handler;
}

InputHandler::InputHandler() 
    : QObject(), _textInputActive(false), _touchX(0), _touchY(0), _touchActive(false) {
}

InputHandler::~InputHandler() {
}

void InputHandler::initialize() {
    _pressedKeys.clear();
    _triggeredKeys.clear();
    _repeatCounters.clear();
    _inputText = "";
    _textInputActive = false;
}

void InputHandler::update() {
    _triggeredKeys.clear();
    
    for (auto it = _repeatCounters.begin(); it != _repeatCounters.end(); ++it) {
        (*it)++;
        if ((*it) > 6) {
            _triggeredKeys.insert(it.key());
            (*it) = 4;
        }
    }
}

bool InputHandler::isPressed(Key key) const {
    return _pressedKeys.contains(key);
}

bool InputHandler::isTriggered(Key key) const {
    return _triggeredKeys.contains(key);
}

bool InputHandler::isRepeated(Key key) const {
    return _pressedKeys.contains(key) && (_repeatCounters.value(key, 0) == 0 || _repeatCounters.value(key, 0) > 4);
}

int InputHandler::getDirectionInput() const {
    if (isPressed(KEY_UP)) {
        if (isDiagonalEnabled()) {
            if (isPressed(KEY_LEFT)) return 7;
            if (isPressed(KEY_RIGHT)) return 9;
        }
        return 8;
    }
    if (isPressed(KEY_DOWN)) {
        if (isDiagonalEnabled()) {
            if (isPressed(KEY_LEFT)) return 1;
            if (isPressed(KEY_RIGHT)) return 3;
        }
        return 2;
    }
    if (isPressed(KEY_LEFT)) return 4;
    if (isPressed(KEY_RIGHT)) return 6;
    return 0;
}

bool InputHandler::isDiagonalEnabled() const {
    return true;
}

void InputHandler::startTextInput(int maxLength) {
    _textInputActive = true;
    _inputText = "";
}

void InputHandler::endTextInput() {
    _textInputActive = false;
}

QString InputHandler::getInputText() const {
    return _inputText;
}

bool InputHandler::isTouchActive() const {
    return _touchActive;
}

int InputHandler::getTouchX() const {
    return _touchX;
}

int InputHandler::getTouchY() const {
    return _touchY;
}
