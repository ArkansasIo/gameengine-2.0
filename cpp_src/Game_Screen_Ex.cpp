#include "Game_Screen_Ex.h"

Game_Screen::Game_Screen() : _brightness(255), _weatherPower(0) {
}

Game_Screen::~Game_Screen() {
}

void Game_Screen::initialize() {
    _brightness = 255;
    _weatherPower = 0;
    _weatherType = "none";
}

void Game_Screen::update() {
}

void Game_Screen::brightness() const {
}

void Game_Screen::setBrightness(int brightness) {
    _brightness = qBound(0, brightness, 255);
}

void Game_Screen::tone() const {
}

void Game_Screen::setTone(int r, int g, int b, int gray, int duration) {
}

void Game_Screen::startTint(int r, int g, int b, int gray, int duration) {
}

void Game_Screen::flash(int red, int green, int blue, int duration) {
}

void Game_Screen::shake(int power, int speed, int duration) {
}

void Game_Screen::startShake(int power, int speed, int duration) {
}

void Game_Screen::showPicture(int pictureId, const QString &name, int origin, int x, int y, 
                              int scaleX, int scaleY, int opacity, int blendMode) {
}

void Game_Screen::movePicture(int pictureId, int origin, int x, int y, 
                              int scaleX, int scaleY, int opacity, int duration) {
}

void Game_Screen::rotatePicture(int pictureId, int speed) {
}

void Game_Screen::tintPicture(int pictureId, int r, int g, int b, int gray, int duration) {
}

void Game_Screen::erasePicture(int pictureId) {
}

void Game_Screen::weatherPower() const {
}

void Game_Screen::setWeatherPower(int power) {
    _weatherPower = qBound(0, power, 9);
}

void Game_Screen::weather() const {
}

void Game_Screen::changeWeather(const QString &type, int power, int duration) {
    _weatherType = type;
    _weatherPower = power;
}
