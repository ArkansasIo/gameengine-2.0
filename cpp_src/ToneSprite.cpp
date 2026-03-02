#include "ToneSprite.h"

ToneSprite::ToneSprite() : _red(0), _green(0), _blue(0), _gray(0) {
}

ToneSprite::~ToneSprite() {
}

void ToneSprite::initialize() {
}

void ToneSprite::update() {
}

void ToneSprite::setTone(int r, int g, int b, int gray) {
    _red = r;
    _green = g;
    _blue = b;
    _gray = gray;
}
