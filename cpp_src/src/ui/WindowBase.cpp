#include "../../include/ui/WindowBase.h"
#include "../../include/utils/MathUtils.h"

namespace LunaLite {
namespace UI {

WindowBase::WindowBase(int x, int y, int width, int height)
    : Graphics::Sprite(0), _width(width), _height(height),
      _padding(12), _backColor(0), _cursorIndex(0),
      _active(true), _enabled(true), _open(true) {
    setPosition(static_cast<float>(x), static_cast<float>(y));
}

WindowBase::~WindowBase() {
}

int WindowBase::getWidth() const {
    return _width;
}

int WindowBase::getHeight() const {
    return _height;
}

void WindowBase::setWidth(int width) {
    _width = Math::Utils::clamp(width, 0, 1920);
}

void WindowBase::setHeight(int height) {
    _height = Math::Utils::clamp(height, 0, 1440);
}

void WindowBase::setDimensions(int width, int height) {
    setWidth(width);
    setHeight(height);
}

int WindowBase::getPadding() const {
    return _padding;
}

void WindowBase::setPadding(int padding) {
    _padding = Math::Utils::clamp(padding, 0, 32);
}

int WindowBase::getBackColor() const {
    return _backColor;
}

void WindowBase::setBackColor(int color) {
    _backColor = color;
}

void WindowBase::clearContents() {
    // Would clear any drawn content
}

int WindowBase::getCursorIndex() const {
    return _cursorIndex;
}

void WindowBase::setCursorIndex(int index) {
    _cursorIndex = index;
}

void WindowBase::moveCursor(int offset) {
    _cursorIndex += offset;
}

bool WindowBase::isActive() const {
    return _active;
}

void WindowBase::setActive(bool active) {
    _active = active;
}

bool WindowBase::isEnabled() const {
    return _enabled;
}

void WindowBase::setEnabled(bool enabled) {
    _enabled = enabled;
}

bool WindowBase::isOpen() const {
    return _open;
}

void WindowBase::open() {
    _open = true;
}

void WindowBase::close() {
    _open = false;
}

void WindowBase::update() {
    Graphics::Sprite::update();
}

} // namespace UI
} // namespace LunaLite
