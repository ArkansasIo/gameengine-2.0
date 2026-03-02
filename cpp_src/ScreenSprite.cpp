#include "ScreenSprite.h"

ScreenSprite::ScreenSprite() : _red(0), _green(0), _blue(0), _alpha(0) {
}

ScreenSprite::~ScreenSprite() {
}

void ScreenSprite::initialize() {
}

void ScreenSprite::setBlendColor(int r, int g, int b, int a) {
    _red = r;
    _green = g;
    _blue = b;
    _alpha = a;
}

void ScreenSprite::setTone(int r, int g, int b, int gray) {
}

void ScreenSprite::update() {
}
