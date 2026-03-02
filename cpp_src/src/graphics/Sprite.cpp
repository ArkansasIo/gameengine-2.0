#include "../../include/graphics/Sprite.h"
#include "../../include/utils/MathUtils.h"

namespace LunaLite {
namespace Graphics {

Sprite::Sprite(int id)
    : Core::GameObject(id), _x(0), _y(0),
      _scaleX(1.0f), _scaleY(1.0f), _rotation(0),
      _opacity(255), _visible(true), _frameIndex(0), _clickable(false) {
}

Sprite::~Sprite() {
}

float Sprite::getX() const {
    return _x;
}

float Sprite::getY() const {
    return _y;
}

void Sprite::setX(float x) {
    _x = x;
}

void Sprite::setY(float y) {
    _y = y;
}

void Sprite::setPosition(float x, float y) {
    _x = x;
    _y = y;
}

float Sprite::getScaleX() const {
    return _scaleX;
}

float Sprite::getScaleY() const {
    return _scaleY;
}

void Sprite::setScaleX(float scale) {
    _scaleX = Math::Utils::clamp(scale, 0.0f, 10.0f);
}

void Sprite::setScaleY(float scale) {
    _scaleY = Math::Utils::clamp(scale, 0.0f, 10.0f);
}

void Sprite::setScale(float x, float y) {
    setScaleX(x);
    setScaleY(y);
}

float Sprite::getRotation() const {
    return _rotation;
}

void Sprite::setRotation(float rotation) {
    _rotation = Math::Utils::normalizeAngle(rotation);
}

int Sprite::getOpacity() const {
    return _opacity;
}

void Sprite::setOpacity(int opacity) {
    _opacity = Math::Utils::clamp(opacity, 0, 255);
}

bool Sprite::isVisible() const {
    return _visible;
}

void Sprite::setVisible(bool visible) {
    _visible = visible;
}

int Sprite::getFrameIndex() const {
    return _frameIndex;
}

void Sprite::setFrameIndex(int index) {
    _frameIndex = Math::Utils::clamp(index, 0, 100);
}

QString Sprite::getBitmapName() const {
    return _bitmapName;
}

void Sprite::setBitmapName(const QString &name) {
    _bitmapName = name;
}

bool Sprite::isClickable() const {
    return _clickable;
}

void Sprite::setClickable(bool clickable) {
    _clickable = clickable;
}

void Sprite::initialize() {
    _x = 0;
    _y = 0;
    _scaleX = 1.0f;
    _scaleY = 1.0f;
    _rotation = 0;
    _opacity = 255;
    _visible = true;
    _frameIndex = 0;
}

void Sprite::update() {
}

} // namespace Graphics
} // namespace LunaLite
