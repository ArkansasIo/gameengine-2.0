#include "../../include/graphics/GameScreen.h"

namespace LunaLite {
namespace Graphics {

Picture::Picture() : id(0), x(0), y(0), scaleX(100), scaleY(100),
                     opacity(255), rotation(0), visible(false) {
}

GameScreen& GameScreen::instance() {
    static GameScreen screen;
    return screen;
}

GameScreen::GameScreen()
    : _brightness(255), _weatherType(0), _weatherIntensity(0) {
}

GameScreen::~GameScreen() {
}

void GameScreen::showPicture(int id, const QString &name, int origin, float x, float y,
                             int scaleX, int scaleY, int opacity, int blendMode) {
    Picture pic;
    pic.id = id;
    pic.name = name;
    pic.x = x;
    pic.y = y;
    pic.scaleX = scaleX / 100.0f;
    pic.scaleY = scaleY / 100.0f;
    pic.opacity = opacity;
    pic.visible = true;
    _pictures.append(pic);
}

void GameScreen::movePicture(int id, int duration, int origin, float x, float y,
                             int scaleX, int scaleY, int opacity, int blendMode) {
    for (auto &pic : _pictures) {
        if (pic.id == id) {
            pic.x = x;
            pic.y = y;
            pic.scaleX = scaleX / 100.0f;
            pic.scaleY = scaleY / 100.0f;
            pic.opacity = opacity;
            break;
        }
    }
}

void GameScreen::rotatePicture(int id, double speed) {
    for (auto &pic : _pictures) {
        if (pic.id == id) {
            pic.rotation += static_cast<float>(speed);
            break;
        }
    }
}

void GameScreen::tintPicture(int id, int r, int g, int b, int intensity, int duration) {
    // Would apply tint effect
}

void GameScreen::erasePicture(int id) {
    for (int i = 0; i < _pictures.size(); ++i) {
        if (_pictures[i].id == id) {
            _pictures.remove(i);
            break;
        }
    }
}

bool GameScreen::isPictureVisible(int id) const {
    for (const auto &pic : _pictures) {
        if (pic.id == id) {
            return pic.visible;
        }
    }
    return false;
}

void GameScreen::flashScreen(int r, int g, int b, int intensity, int duration) {
    // Would create flash effect
}

void GameScreen::shakeScreen(int power, int speed, int duration) {
    // Would create shake effect
}

void GameScreen::tintScreen(int r, int g, int b, int intensity, int duration) {
    // Would create tint effect
}

void GameScreen::showWeather(int weatherType, int intensity, int duration) {
    _weatherType = weatherType;
    _weatherIntensity = intensity;
}

void GameScreen::setScreenBrightness(int brightness, int duration) {
    _brightness = (brightness < 0) ? 0 : (brightness > 255) ? 255 : brightness;
}

int GameScreen::getScreenBrightness() const {
    return _brightness;
}

void GameScreen::update() {
    // Update screen effects like flashes and shakes
}

void GameScreen::render() {
    // Render pictures and effects
}

void GameScreen::clear() {
    _pictures.clear();
    _brightness = 255;
    _weatherType = 0;
    _weatherIntensity = 0;
}

} // namespace Graphics
} // namespace LunaLite
