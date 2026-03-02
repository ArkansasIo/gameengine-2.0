#include "ImageManager_Ex.h"

ImageManager& ImageManager::instance() {
    static ImageManager instance;
    return instance;
}

ImageManager::ImageManager() {
}

ImageManager::~ImageManager() {
}

void ImageManager::initialize() {
}

void *ImageManager::loadBitmap(const QString &url, int hue) {
    return nullptr;
}

void *ImageManager::loadBitmapFromUrl(const QString &url) {
    return nullptr;
}

void ImageManager::releaseImage(const QString &name) {
}
