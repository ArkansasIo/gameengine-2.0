#include "ImageManager_Base.h"

ImageManager_Base& ImageManager_Base::instance() {
    static ImageManager_Base instance;
    return instance;
}

ImageManager_Base::ImageManager_Base() {
}

ImageManager_Base::~ImageManager_Base() {
}

Bitmap *ImageManager_Base::loadSystem(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadBattle1(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadBattle2(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadBattleback1(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadBattleback2(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadCharacter(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadFace(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadParallax(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadPicture(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadTileset(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadTitle1(const QString &filename) {
    return nullptr;
}

Bitmap *ImageManager_Base::loadTitle2(const QString &filename) {
    return nullptr;
}

void ImageManager_Base::releaseReservation(const QString &key) {
}

void ImageManager_Base::releaseReservations() {
}
