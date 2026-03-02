#include "Window_Message.h"

Window_Message::Window_Message() : Window_Base(0, 0, 816, 108), _background(0), _positionType(2) {
}

Window_Message::~Window_Message() {
}

void Window_Message::initialize() {
}

void Window_Message::startMessage() {
    open();
}

void Window_Message::updatePlacement() {
}

void Window_Message::updateBackground() {
}

void Window_Message::terminateMessage() {
    close();
}

bool Window_Message::isOpen() const {
    return Window_Base::isOpen();
}

bool Window_Message::isClosing() const {
    return false;
}

bool Window_Message::isWaiting() const {
    return false;
}

void Window_Message::setBackground(int background) {
    _background = background;
}

void Window_Message::setPositionType(int positionType) {
    _positionType = positionType;
}

void Window_Message::setDimensions(int width, int height) {
    setSize(width, height);
}
