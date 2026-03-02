#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

#include <string>
#include "CacheMap.h"
#include "Bitmap.h"

class ImageManager {
public:
    static CacheMap* cache;
    
    static Bitmap* loadAnimation(const std::string& filename, int hue = 0);
    static Bitmap* loadBattleback1(const std::string& filename, int hue = 0);
    static Bitmap* loadBattleback2(const std::string& filename, int hue = 0);
    static Bitmap* loadEnemy(const std::string& filename, int hue = 0);
    static Bitmap* loadCharacter(const std::string& filename, int hue = 0);
    static Bitmap* loadFace(const std::string& filename, int hue = 0);
    static Bitmap* loadParallax(const std::string& filename, int hue = 0);
    static Bitmap* loadPicture(const std::string& filename, int hue = 0);
    static Bitmap* loadSvActor(const std::string& filename, int hue = 0);
    static Bitmap* loadSvEnemy(const std::string& filename, int hue = 0);
    static Bitmap* loadSystem(const std::string& filename, int hue = 0);
    static Bitmap* loadTileset(const std::string& filename, int hue = 0);
    static Bitmap* loadTitle1(const std::string& filename, int hue = 0);
    static Bitmap* loadTitle2(const std::string& filename, int hue = 0);
    static Bitmap* loadBitmap(const std::string& folder, const std::string& filename, int hue = 0, bool smooth = false);
    static Bitmap* loadEmptyBitmap();
    static Bitmap* loadNormalBitmap(const std::string& path, int hue = 0);
    
    static void clear();
    static bool isReady();
    static bool isObjectCharacter(const std::string& filename);
    static bool isBigCharacter(const std::string& filename);
    static bool isZeroParallax(const std::string& filename);
    
private:
    ImageManager() = delete;
};

#endif // IMAGE_MANAGER_H
