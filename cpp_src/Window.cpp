#include "Window.h"

Window::Window(int x, int y, int width, int height)
    : Sprite(nullptr), windowWidth(width), windowHeight(height),
      padding(18), margin(4), active(true), openness(255),
      _opening(false), _closing(false) {
    this->x = x;
    this->y = y;
    _tone[0] = 0;
    _tone[1] = 0;
    _tone[2] = 0;
}

Window::~Window() {
}

void Window::update() {
    Sprite::update();
    updateTone();
    updateInnerChildren();
}

void Window::move(int newX, int newY, int newWidth, int newHeight) {
    x = newX;
    y = newY;
    windowWidth = newWidth;
    windowHeight = newHeight;
}

bool Window::isOpen() const {
    return openness >= 255;
}

bool Window::isClosed() const {
    return openness <= 0;
}

void Window::open() {
    _opening = true;
    _closing = false;
}

void Window::close() {
    _closing = true;
    _opening = false;
}

void Window::activate() {
    active = true;
}

void Window::deactivate() {
    active = false;
}

void Window::updateTransform() {
    Sprite::updateTransform();
}

void Window::updateTone() {
}

void Window::addChildToBack(Sprite* child) {
}

void Window::updatePadding() {
}

void Window::updateBackOpacity() {
}

void Window::setTone(int r, int g, int b) {
    _tone[0] = r;
    _tone[1] = g;
    _tone[2] = b;
}

void Window::addInnerChild(Sprite* child) {
}

void Window::updateInnerChildren() {
}
