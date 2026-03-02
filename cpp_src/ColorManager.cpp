#include "ColorManager.h"

ColorManager& ColorManager::instance() {
    static ColorManager instance;
    return instance;
}

ColorManager::ColorManager() {
}

ColorManager::~ColorManager() {
}

void ColorManager::initialize() {
}

QColor ColorManager::textColor(int id) const {
    return QColor(255, 255, 255);
}

QColor ColorManager::normalColor() const {
    return QColor(255, 255, 255);
}

QColor ColorManager::systemColor() const {
    return QColor(192, 224, 255);
}

QColor ColorManager::crisisColor() const {
    return QColor(255, 0, 0);
}

QColor ColorManager::deathColor() const {
    return QColor(128, 128, 128);
}

QColor ColorManager::gaugeBackColor() const {
    return QColor(64, 64, 64);
}

QColor ColorManager::hpGaugeColor1() const {
    return QColor(224, 100, 100);
}

QColor ColorManager::hpGaugeColor2() const {
    return QColor(240, 60, 60);
}

QColor ColorManager::mpGaugeColor1() const {
    return QColor(100, 100, 224);
}

QColor ColorManager::mpGaugeColor2() const {
    return QColor(60, 60, 240);
}
