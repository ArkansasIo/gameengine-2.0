#include "../../include/managers/ConfigurationManager.h"

namespace LunaLite {
namespace Managers {

ConfigurationManager& ConfigurationManager::instance() {
    static ConfigurationManager manager;
    return manager;
}

ConfigurationManager::ConfigurationManager() {
    initializeDefaults();
}

ConfigurationManager::~ConfigurationManager() {
}

void ConfigurationManager::initializeDefaults() {
    _config["gameTitle"] = "LunaLite";
    _config["screenWidth"] = 816;
    _config["screenHeight"] = 624;
    _config["fullscreen"] = false;
    _config["masterVolume"] = 100;
    _config["bgmVolume"] = 100;
    _config["bgsVolume"] = 100;
    _config["seVolume"] = 100;
    _config["difficulty"] = Normal;
    _config["debugEnabled"] = false;
    _config["allowSaveAnywhere"] = false;
    _config["allowLoadAnywhere"] = false;
}

bool ConfigurationManager::loadConfig(const QString &filePath) {
    // TODO: Load from JSON file
    return true;
}

bool ConfigurationManager::saveConfig(const QString &filePath) {
    // TODO: Save to JSON file
    return true;
}

QString ConfigurationManager::getGameTitle() const {
    return _config.value("gameTitle", "LunaLite").toString();
}

void ConfigurationManager::setGameTitle(const QString &title) {
    _config["gameTitle"] = title;
}

int ConfigurationManager::getScreenWidth() const {
    return _config.value("screenWidth", 816).toInt();
}

int ConfigurationManager::getScreenHeight() const {
    return _config.value("screenHeight", 624).toInt();
}

void ConfigurationManager::setScreenSize(int width, int height) {
    _config["screenWidth"] = width;
    _config["screenHeight"] = height;
}

bool ConfigurationManager::isFullscreen() const {
    return _config.value("fullscreen", false).toBool();
}

void ConfigurationManager::setFullscreen(bool fullscreen) {
    _config["fullscreen"] = fullscreen;
}

int ConfigurationManager::getMasterVolume() const {
    return _config.value("masterVolume", 100).toInt();
}

void ConfigurationManager::setMasterVolume(int volume) {
    int v = (volume < 0) ? 0 : (volume > 100) ? 100 : volume;
    _config["masterVolume"] = v;
}

ConfigurationManager::GameDifficulty ConfigurationManager::getDifficulty() const {
    return static_cast<GameDifficulty>(_config.value("difficulty", Normal).toInt());
}

void ConfigurationManager::setDifficulty(GameDifficulty difficulty) {
    _config["difficulty"] = static_cast<int>(difficulty);
}

bool ConfigurationManager::isDebugEnabled() const {
    return _config.value("debugEnabled", false).toBool();
}

void ConfigurationManager::setDebugEnabled(bool enabled) {
    _config["debugEnabled"] = enabled;
}

bool ConfigurationManager::getAllowSaveAnywhereOption() const {
    return _config.value("allowSaveAnywhere", false).toBool();
}

bool ConfigurationManager::getAllowLoadAnywhereOption() const {
    return _config.value("allowLoadAnywhere", false).toBool();
}

QVariant ConfigurationManager::getValue(const QString &key, const QVariant &defaultValue) const {
    return _config.value(key, defaultValue);
}

void ConfigurationManager::setValue(const QString &key, const QVariant &value) {
    _config[key] = value;
}

void ConfigurationManager::resetToDefaults() {
    _config.clear();
    initializeDefaults();
}

} // namespace Managers
} // namespace LunaLite
