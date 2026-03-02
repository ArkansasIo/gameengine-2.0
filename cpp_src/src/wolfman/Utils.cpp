#include "../../include/wolfman/Utils.h"
#include <random>

namespace WolfManAlpha {
namespace Utils {

const float Math::PI = 3.14159265359f;
const float Math::TAU = 6.28318530718f;
const float Math::DEG_TO_RAD = 0.01745329251f;
const float Math::RAD_TO_DEG = 57.29577951308f;

QVector<QString> String::split(const QString &str, const QString &delimiter) {
    return str.split(delimiter).toVector();
}

QString String::join(const QVector<QString> &parts, const QString &delimiter) {
    return parts.join(delimiter);
}

QString String::toLower(const QString &str) {
    return str.toLower();
}

QString String::toUpper(const QString &str) {
    return str.toUpper();
}

bool String::startsWith(const QString &str, const QString &prefix) {
    return str.startsWith(prefix);
}

bool String::endsWith(const QString &str, const QString &suffix) {
    return str.endsWith(suffix);
}

QString String::trim(const QString &str) {
    return str.trimmed();
}

QString String::replace(const QString &str, const QString &from, const QString &to) {
    return str.replace(from, to);
}

float Random::randomFloat(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

int Random::randomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

bool Random::randomBool() {
    return randomInt(0, 1) == 1;
}

float Random::randomAngle() {
    return randomFloat(0, Math::TAU);
}

QString Convert::toString(int value) {
    return QString::number(value);
}

QString Convert::toString(float value) {
    return QString::number(value);
}

QString Convert::toString(bool value) {
    return value ? "true" : "false";
}

int Convert::toInt(const QString &str) {
    return str.toInt();
}

float Convert::toFloat(const QString &str) {
    return str.toFloat();
}

bool Convert::toBool(const QString &str) {
    return str.toLower() == "true";
}

int Color::rgba(int r, int g, int b, int a) {
    return (r << 24) | (g << 16) | (b << 8) | a;
}

int Color::rgb(int r, int g, int b) {
    return rgba(r, g, b, 255);
}

void Color::getRgba(int color, int& r, int& g, int& b, int& a) {
    r = (color >> 24) & 0xFF;
    g = (color >> 16) & 0xFF;
    b = (color >> 8) & 0xFF;
    a = color & 0xFF;
}

} // namespace Utils
} // namespace WolfManAlpha
