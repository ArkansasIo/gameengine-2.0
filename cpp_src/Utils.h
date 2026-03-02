#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
public:
    static const std::string RPGMAKER_NAME;
    static const std::string RPGMAKER_VERSION;
    
    static bool isOptionValid(const std::string& name);
    static bool isNwjs();
    static bool isMobileDevice();
    static bool isMobileSafari();
    static bool isAndroidChrome();
    static bool canReadGameFiles();
    static std::string rgbToCssColor(int r, int g, int b);
    static bool isSupportPassiveEvent();
    
private:
    Utils() = delete;
};

#endif // UTILS_H
