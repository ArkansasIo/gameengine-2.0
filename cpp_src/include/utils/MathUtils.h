#ifndef LUNALITE_MATH_UTILS_H
#define LUNALITE_MATH_UTILS_H

#include <cmath>
#include <algorithm>
#include <random>
#include "qstring.h"

namespace LunaLite {
namespace Math {

class Utils {
public:
    // Random number generation
    static int randomInt(int min, int max);
    static float randomFloat(float min, float max);
    static bool randomChance(float probability);
    
    // Clamping
    template<typename T>
    static T clamp(T value, T min, T max) {
        return std::max(min, std::min(value, max));
    }
    
    // Interpolation
    static float lerp(float a, float b, float t);
    static int lerpInt(int a, int b, float t);
    
    // Easing functions
    static float easeInQuad(float t);
    static float easeOutQuad(float t);
    static float easeInOutQuad(float t);
    
    // Distance calculation
    static float distance(float x1, float y1, float x2, float y2);
    static int manhattanDistance(int x1, int y1, int x2, int y2);
    
    // Angle calculations
    static float getAngle(float x1, float y1, float x2, float y2);
    static float normalizeAngle(float angle);
    
    // Number formatting
    static QString formatNumber(int value);
    static QString formatCurrency(int value);

private:
    static std::mt19937 _generator;
};

} // namespace Math
} // namespace LunaLite

#endif // LUNALITE_MATH_UTILS_H
