
#include "Game_Screen.h"

Game_Screen::Game_Screen() 
    : _brightness(255), _fadeOutDuration(0), _fadeInDuration(0),
      _toneDuration(0), _flashDuration(0), _shakePower(0),
      _shakeSpeed(0), _shakeDuration(0), _shakeDirection(1),
      _shake(0), _zoomX(0), _zoomY(0), _zoomScale(1),
      _zoomScaleTarget(1), _zoomDuration(0), _weatherType(0),
      _weatherPower(0), _weatherPowerTarget(0), _weatherDuration(0) {
    _tone[0] = 0;
    _tone[1] = 0;
    _tone[2] = 0;
    _toneTarget[0] = 0;
    _toneTarget[1] = 0;
    _toneTarget[2] = 0;
    _flashColor[0] = 0;
    _flashColor[1] = 0;
    _flashColor[2] = 0;
    _flashColor[3] = 0;
}

Game_Screen::~Game_Screen() {
}

void Game_Screen::initialize() {
    clear();
}

void Game_Screen::clear() {
    clearFade();
    clearTone();
    clearFlash();
    clearShake();
    clearZoom();
    clearWeather();
    clearPictures();
}

void Game_Screen::onBattleStart() {
    clearFade();
    clearFlash();
    clearShake();
    clearZoom();
}

int Game_Screen::brightness() const {
    return _brightness;
}

int Game_Screen::tone() const {
    return 0;
}

int Game_Screen::flashColor() const {
    return 0;
}

int Game_Screen::shake() const {
    return _shake;
}

int Game_Screen::zoomX() const {
    return _zoomX;
}

int Game_Screen::zoomY() const {
    return _zoomY;
}

int Game_Screen::zoomScale() const {
    return _zoomScale;
}

int Game_Screen::weatherType() const {
    return _weatherType;
}

int Game_Screen::weatherPower() const {
    return _weatherPower;
}

void Game_Screen::clearFade() {
    _brightness = 255;
    _fadeOutDuration = 0;
    _fadeInDuration = 0;
}

void Game_Screen::clearTone() {
    _tone[0] = 0;
    _tone[1] = 0;
    _tone[2] = 0;
    _toneDuration = 0;
}

void Game_Screen::clearFlash() {
    _flashColor[0] = 0;
    _flashColor[1] = 0;
    _flashColor[2] = 0;
    _flashColor[3] = 0;
    _flashDuration = 0;
}

void Game_Screen::clearShake() {
    _shakePower = 0;
    _shakeSpeed = 0;
    _shakeDuration = 0;
    _shake = 0;
}

void Game_Screen::clearZoom() {
    _zoomX = 0;
    _zoomY = 0;
    _zoomScale = 1;
    _zoomScaleTarget = 1;
    _zoomDuration = 0;
}

void Game_Screen::clearWeather() {
    _weatherType = 0;
    _weatherPower = 0;
    _weatherPowerTarget = 0;
    _weatherDuration = 0;
}

void Game_Screen::clearPictures() {
}

void Game_Screen::erasePicture(int pictureId) {
}

void Game_Screen::showPicture(int pictureId, const std::string& name, int origin, int x, int y, int scaleX, int scaleY, int opacity, int blendMode) {
}

void Game_Screen::movePicture(int pictureId, int origin, int x, int y, int scaleX, int scaleY, int opacity, int blendMode, int duration) {
}

void Game_Screen::rotatePicture(int pictureId, int speed) {
}

void Game_Screen::tintPicture(int pictureId, int tone, int duration) {
}

void Game_Screen::startFadeOut(int duration) {
    _fadeOutDuration = duration;
    _brightness = 255;
}

void Game_Screen::startFadeIn(int duration) {
    _fadeInDuration = duration;
    _brightness = 0;
}

void Game_Screen::startTint(int tone, int duration) {
    _toneDuration = duration;
}

void Game_Screen::startFlash(int color, int duration) {
    _flashDuration = duration;
}

void Game_Screen::startShake(int power, int speed, int duration) {
    _shakePower = power;
    _shakeSpeed = speed;
    _shakeDuration = duration;
}

void Game_Screen::startZoom(int x, int y, int scale, int duration) {
    _zoomX = x;
    _zoomY = y;
    _zoomScaleTarget = scale;
    _zoomDuration = duration;
}

void Game_Screen::setZoom(int x, int y, int scale) {
    _zoomX = x;
    _zoomY = y;
    _zoomScale = scale;
}

void Game_Screen::changeWeather(int type, int power, int duration) {
    _weatherType = type;
    _weatherPowerTarget = power;
    _weatherDuration = duration;
}

void Game_Screen::update() {
    updateFadeOut();
    updateFadeIn();
    updateTone();
    updateFlash();
    updateShake();
    updateZoom();
    updateWeather();
    updatePictures();
}

void Game_Screen::updateFadeOut() {
    if (_fadeOutDuration > 0) {
        _brightness -= 255 / _fadeOutDuration;
        _fadeOutDuration--;
    }
}

void Game_Screen::updateFadeIn() {
    if (_fadeInDuration > 0) {
        _brightness += 255 / _fadeInDuration;
        _fadeInDuration--;
    }
}

void Game_Screen::updateTone() {
    if (_toneDuration > 0) {
        _toneDuration--;
    }
}

void Game_Screen::updateFlash() {
    if (_flashDuration > 0) {
        _flashDuration--;
    }
}

void Game_Screen::updateShake() {
    if (_shakeDuration > 0) {
        _shake = _shakePower * _shakeSpeed * _shakeDirection;
        _shakeDirection = -_shakeDirection;
        _shakeDuration--;
    } else {
        _shake = 0;
    }
}

void Game_Screen::updateZoom() {
    if (_zoomDuration > 0) {
        _zoomScale += (_zoomScaleTarget - _zoomScale) / _zoomDuration;
        _zoomDuration--;
    }
}

void Game_Screen::updateWeather() {
    if (_weatherDuration > 0) {
        int d = _weatherDuration;
        _weatherPower = (_weatherPower * (d - 1) + _weatherPowerTarget) / d;
        _weatherDuration--;
    }
}

void Game_Screen::updatePictures() {
}

void Game_Screen::startFlashForDamage() {
    startFlash(255, 8);
}
