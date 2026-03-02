#include "../../include/managers/ResourceManager.h"

namespace LunaLite {
namespace Managers {

ResourceManager& ResourceManager::instance() {
    static ResourceManager manager;
    return manager;
}

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
    clearAllResources();
}

bool ResourceManager::loadImage(const QString &name, const QString &filePath) {
    QPixmap* pixmap = new QPixmap(filePath);
    if (pixmap->isNull()) {
        delete pixmap;
        return false;
    }
    _images[name] = pixmap;
    return true;
}

void ResourceManager::unloadImage(const QString &name) {
    if (_images.contains(name)) {
        delete _images[name];
        _images.remove(name);
    }
}

QPixmap* ResourceManager::getImage(const QString &name) {
    return _images.value(name, nullptr);
}

bool ResourceManager::hasImage(const QString &name) const {
    return _images.contains(name);
}

void ResourceManager::clearImages() {
    for (auto pixmap : _images) {
        delete pixmap;
    }
    _images.clear();
}

bool ResourceManager::loadAudio(const QString &name, const QString &filePath) {
    // Would load audio file
    _audioFiles[name] = filePath;
    return true;
}

void ResourceManager::unloadAudio(const QString &name) {
    _audioFiles.remove(name);
}

bool ResourceManager::hasAudio(const QString &name) const {
    return _audioFiles.contains(name);
}

void ResourceManager::clearAudio() {
    _audioFiles.clear();
}

bool ResourceManager::loadDataFile(const QString &name, const QString &filePath) {
    // Would load data file
    _dataFiles[name] = filePath;
    return true;
}

QString ResourceManager::getDataFile(const QString &name) const {
    return _dataFiles.value(name, "");
}

bool ResourceManager::hasDataFile(const QString &name) const {
    return _dataFiles.contains(name);
}

void ResourceManager::clearDataFiles() {
    _dataFiles.clear();
}

int ResourceManager::getMemoryUsage() const {
    int total = 0;
    for (auto pixmap : _images) {
        // Approximate memory: width * height * 4 bytes per pixel / 1024 KB
        total += (pixmap->width() * pixmap->height() * 4) / 1024;
    }
    return total;
}

void ResourceManager::clearAllResources() {
    clearImages();
    clearAudio();
    clearDataFiles();
}

void ResourceManager::preloadResourcesForMap(int mapId) {
    // Would preload graphics, sounds, and data for a specific map
}

} // namespace Managers
} // namespace LunaLite
