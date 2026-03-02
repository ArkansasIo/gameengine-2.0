#include "Weather.h"

Weather::Weather() : _power(0), _duration(0) {
}

Weather::~Weather() {
}

void Weather::initialize() {
    _type = "none";
    _power = 0;
    _duration = 0;
}

void Weather::update() {
    if (_duration > 0) {
        _duration--;
    }
}

void Weather::setType(const QString &type) {
    _type = type;
}

void Weather::setPower(int power) {
    _power = qBound(0, power, 9);
}

void Weather::setDuration(int duration) {
    _duration = duration;
}

QString Weather::type() const {
    return _type;
}

int Weather::power() const {
    return _power;
}

int Weather::duration() const {
    return _duration;
}

void Weather::refresh() {
}
