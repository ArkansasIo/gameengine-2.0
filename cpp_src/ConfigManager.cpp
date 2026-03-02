#include "ConfigManager.h"

ConfigManager& ConfigManager::instance() {
    static ConfigManager instance;
    return instance;
}

ConfigManager::ConfigManager() {
    initialize();
}

ConfigManager::~ConfigManager() {
}

void ConfigManager::initialize() {
    _boolValues["alwaysDash"] = false;
    _boolValues["commandRemember"] = false;
    _boolValues["touchUI"] = true;
    _boolValues["vibration"] = true;
    _boolValues["debugMode"] = false;
    
    _intValues["bgmVolume"] = 100;
    _intValues["bgsVolume"] = 100;
    _intValues["meVolume"] = 100;
    _intValues["seVolume"] = 100;
}

void ConfigManager::load() {
}

void ConfigManager::save() {
}

bool ConfigManager::alwaysDash() const {
    return _boolValues.value("alwaysDash", false);
}

void ConfigManager::setAlwaysDash(bool value) {
    _boolValues["alwaysDash"] = value;
}

bool ConfigManager::commandRemember() const {
    return _boolValues.value("commandRemember", false);
}

void ConfigManager::setCommandRemember(bool value) {
    _boolValues["commandRemember"] = value;
}

int ConfigManager::bgmVolume() const {
    return _intValues.value("bgmVolume", 100);
}

void ConfigManager::setBgmVolume(int value) {
    _intValues["bgmVolume"] = qBound(0, value, 100);
}

int ConfigManager::bgsVolume() const {
    return _intValues.value("bgsVolume", 100);
}

void ConfigManager::setBgsVolume(int value) {
    _intValues["bgsVolume"] = qBound(0, value, 100);
}

int ConfigManager::meVolume() const {
    return _intValues.value("meVolume", 100);
}

void ConfigManager::setMeVolume(int value) {
    _intValues["meVolume"] = qBound(0, value, 100);
}

int ConfigManager::seVolume() const {
    return _intValues.value("seVolume", 100);
}

void ConfigManager::setSeVolume(int value) {
    _intValues["seVolume"] = qBound(0, value, 100);
}

bool ConfigManager::touchUI() const {
    return _boolValues.value("touchUI", true);
}

void ConfigManager::setTouchUI(bool value) {
    _boolValues["touchUI"] = value;
}

bool ConfigManager::vibration() const {
    return _boolValues.value("vibration", true);
}

void ConfigManager::setVibration(bool value) {
    _boolValues["vibration"] = value;
}

bool ConfigManager::debugMode() const {
    return _boolValues.value("debugMode", false);
}

void ConfigManager::setDebugMode(bool value) {
    _boolValues["debugMode"] = value;
}
