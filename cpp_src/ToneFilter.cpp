#include "ToneFilter.h"

ToneFilter::ToneFilter() : _red(0), _green(0), _blue(0), _gray(0), _duration(0) {
}

ToneFilter::~ToneFilter() {
}

void ToneFilter::initialize() {
}

void ToneFilter::update() {
    if (_duration > 0) {
        _duration--;
    }
}

void ToneFilter::setTone(int r, int g, int b, int gray) {
    _red = r;
    _green = g;
    _blue = b;
    _gray = gray;
}

void ToneFilter::setToneDuration(int duration) {
    _duration = duration;
}
