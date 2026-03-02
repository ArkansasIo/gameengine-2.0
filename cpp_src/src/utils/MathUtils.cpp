#include "../../include/utils/MathUtils.h"
#include <ctime>

namespace LunaLite {
namespace Math {

std::mt19937 Utils::_generator(static_cast<unsigned>(std::time(nullptr)));

int Utils::randomInt(int min, int max) {
    if (min > max) std::swap(min, max);
    std::uniform_int_distribution<> dist(min, max);
    return dist(_generator);
}

float Utils::randomFloat(float min, float max) {
    if (min > max) std::swap(min, max);
    std::uniform_real_distribution<> dist(min, max);
    return static_cast<float>(dist(_generator));
}

bool Utils::randomChance(float probability) {
    return randomFloat(0.0f, 1.0f) < probability;
}

float Utils::lerp(float a, float b, float t) {
    return a + (b - a) * std::clamp(t, 0.0f, 1.0f);
}

int Utils::lerpInt(int a, int b, float t) {
    return static_cast<int>(lerp(static_cast<float>(a), static_cast<float>(b), t));
}

float Utils::easeInQuad(float t) {
    return t * t;
}

float Utils::easeOutQuad(float t) {
    return t * (2.0f - t);
}

float Utils::easeInOutQuad(float t) {
    return t < 0.5f ? 2.0f * t * t : -1.0f + (4.0f - 2.0f * t) * t;
}

float Utils::distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

int Utils::manhattanDistance(int x1, int y1, int x2, int y2) {
    return std::abs(x2 - x1) + std::abs(y2 - y1);
}

float Utils::getAngle(float x1, float y1, float x2, float y2) {
    return std::atan2(y2 - y1, x2 - x1) * 180.0f / 3.14159265359f;
}

float Utils::normalizeAngle(float angle) {
    while (angle < 0) angle += 360.0f;
    while (angle >= 360.0f) angle -= 360.0f;
    return angle;
}

QString Utils::formatNumber(int value) {
    return QString::number(value);
}

QString Utils::formatCurrency(int value) {
    QString str = QString::number(value);
    int insertPosition = str.length() - 3;
    while (insertPosition > 0) {
        str.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    return str;
}

} // namespace Math
} // namespace LunaLite
