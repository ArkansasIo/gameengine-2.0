#include "ImageManager.h"

CacheMap* ImageManager::cache = new CacheMap();

Bitmap* ImageManager::loadAnimation(const std::string& filename, int hue) {
    return loadBitmap("img/animations/", filename, hue, true);
}

Bitmap* ImageManager::loadBattleback1(const std::string& filename, int hue) {
    return loadBitmap("img/battlebacks1/", filename, hue, true);
}

Bitmap* ImageManager::loadBattleback2(const std::string& filename, int hue) {
    return loadBitmap("img/battlebacks2/", filename, hue, true);
}

Bitmap* ImageManager::loadEnemy(const std::string& filename, int hue) {
    return loadBitmap("img/enemies/", filename, hue, true);
}

Bitmap* ImageManager::loadCharacter(const std::string& filename, int hue) {
    return loadBitmap("img/characters/", filename, hue, false);
}

Bitmap* ImageManager::loadFace(const std::string& filename, int hue) {
    return loadBitmap("img/faces/", filename, hue, true);
}

Bitmap* ImageManager::loadParallax(const std::string& filename, int hue) {
    return loadBitmap("img/parallaxes/", filename, hue, true);
}

Bitmap* ImageManager::loadPicture(const std::string& filename, int hue) {
    return loadBitmap("img/pictures/", filename, hue, true);
}

Bitmap* ImageManager::loadSvActor(const std::string& filename, int hue) {
    return loadBitmap("img/sv_actors/", filename, hue, true);
}

Bitmap* ImageManager::loadSvEnemy(const std::string& filename, int hue) {
    return loadBitmap("img/sv_enemies/", filename, hue, true);
}

Bitmap* ImageManager::loadSystem(const std::string& filename, int hue) {
    return loadBitmap("img/system/", filename, hue, false);
}

Bitmap* ImageManager::loadTileset(const std::string& filename, int hue) {
    return loadBitmap("img/tilesets/", filename, hue, false);
}

Bitmap* ImageManager::loadTitle1(const std::string& filename, int hue) {
    return loadBitmap("img/titles1/", filename, hue, true);
}

Bitmap* ImageManager::loadTitle2(const std::string& filename, int hue) {
    return loadBitmap("img/titles2/", filename, hue, true);
}

Bitmap* ImageManager::loadBitmap(const std::string& folder, const std::string& filename, int hue, bool smooth) {
    if (filename.empty()) {
        return loadEmptyBitmap();
    }
    
    std::string path = folder + filename + ".png";
    return loadNormalBitmap(path, hue);
}

Bitmap* ImageManager::loadEmptyBitmap() {
    return new Bitmap(0, 0);
}

Bitmap* ImageManager::loadNormalBitmap(const std::string& path, int hue) {
    Bitmap* bitmap = Bitmap::load(path);
    if (hue != 0) {
        bitmap->rotateHue(hue);
    }
    return bitmap;
}

void ImageManager::clear() {
    cache->clear();
}

bool ImageManager::isReady() {
    return true;
}

bool ImageManager::isObjectCharacter(const std::string& filename) {
    return filename.find("!") == 0;
}

bool ImageManager::isBigCharacter(const std::string& filename) {
    return filename.find("$") == 0;
}

bool ImageManager::isZeroParallax(const std::string& filename) {
    return filename.find("!") == 0;
}
