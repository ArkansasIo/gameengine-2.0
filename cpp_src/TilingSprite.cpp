#include "TilingSprite.h"

TilingSprite::TilingSprite() : _x(0), _y(0), _scaleX(1.0), _scaleY(1.0), _opacity(255) {
}

TilingSprite::~TilingSprite() {
}

void TilingSprite::initialize() {
}

void TilingSprite::update() {
}

void TilingSprite::setPosition(double x, double y) {
    _x = x;
    _y = y;
}

void TilingSprite::setScale(double scaleX, double scaleY) {
    _scaleX = scaleX;
    _scaleY = scaleY;
}

void TilingSprite::setOpacity(int opacity) {
    _opacity = qBound(0, opacity, 255);
}

double TilingSprite::x() const {
    return _x;
}

double TilingSprite::y() const {
    return _y;
}
