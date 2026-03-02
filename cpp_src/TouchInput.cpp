#include "TouchInput.h"

bool TouchInput::_mousePressed = false;
int TouchInput::_screenPressed = 0;
int TouchInput::_pressedTime = 0;
int TouchInput::_x = 0;
int TouchInput::_y = 0;
int TouchInput::_date = 0;

void TouchInput::initialize() {
    clear();
}

void TouchInput::clear() {
    _mousePressed = false;
    _screenPressed = 0;
    _pressedTime = 0;
    _x = 0;
    _y = 0;
}

void TouchInput::update() {
}

bool TouchInput::isPressed() {
    return _mousePressed;
}

bool TouchInput::isTriggered() {
    return _screenPressed && _pressedTime == 0;
}

bool TouchInput::isRepeated() {
    return false;
}

bool TouchInput::isLongPressed() {
    return _pressedTime >= 60;
}

bool TouchInput::isCancelled() {
    return false;
}

bool TouchInput::isMoved() {
    return false;
}

int TouchInput::wheelX() {
    return 0;
}

int TouchInput::wheelY() {
    return 0;
}

int TouchInput::x() {
    return _x;
}

int TouchInput::y() {
    return _y;
}
