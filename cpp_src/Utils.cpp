#include "Utils.h"
#include <sstream>
#include <iomanip>

const std::string Utils::RPGMAKER_NAME = "LunaLite";
const std::string Utils::RPGMAKER_VERSION = "1.0.0";

bool Utils::isOptionValid(const std::string& name) {
    return false;
}

bool Utils::isNwjs() {
    return false;
}

bool Utils::isMobileDevice() {
    return false;
}

bool Utils::isMobileSafari() {
    return false;
}

bool Utils::isAndroidChrome() {
    return false;
}

bool Utils::canReadGameFiles() {
    return true;
}

std::string Utils::rgbToCssColor(int r, int g, int b) {
    std::stringstream ss;
    ss << "rgb(" << r << "," << g << "," << b << ")";
    return ss.str();
}

bool Utils::isSupportPassiveEvent() {
    return false;
}
