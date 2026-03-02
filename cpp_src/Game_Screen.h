#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <string>
#include <vector>

class Game_Screen {
public:
    Game_Screen();
    ~Game_Screen();
    
    void initialize();
    void clear();
    void onBattleStart();
    int brightness() const;
    int tone() const;
    int flashColor() const;
    int shake() const;
    int zoomX() const;
    int zoomY() const;
    int zoomScale() const;
    int weatherType() const;
    int weatherPower() const;
    void clearFade();
    void clearTone();
    void clearFlash();
    void clearShake();
    void clearZoom();
    void clearWeather();
    void clearPictures();
    void erasePicture(int pictureId);
    void showPicture(int pictureId, const std::string& name, int origin, int x, int y, int scaleX, int scaleY, int opacity, int blendMode);
    void movePicture(int pictureId, int origin, int x, int y, int scaleX, int scaleY, int opacity, int blendMode, int duration);
    void rotatePicture(int pictureId, int speed);
    void tintPicture(int pictureId, int tone, int duration);
    void startFadeOut(int duration);
    void startFadeIn(int duration);
    void startTint(int tone, int duration);
    void startFlash(int color, int duration);
    void startShake(int power, int speed, int duration);
    void startZoom(int x, int y, int scale, int duration);
    void setZoom(int x, int y, int scale);
    void changeWeather(int type, int power, int duration);
    void update();
    void updateFadeOut();
    void updateFadeIn();
    void updateTone();
    void updateFlash();
    void updateShake();
    void updateZoom();
    void updateWeather();
    void updatePictures();
    void startFlashForDamage();
    
private:
    int _brightness;
    int _fadeOutDuration;
    int _fadeInDuration;
    int _tone[3];
    int _toneTarget[3];
    int _toneDuration;
    int _flashColor[4];
    int _flashDuration;
    int _shakePower;
    int _shakeSpeed;
    int _shakeDuration;
    int _shakeDirection;
    int _shake;
    int _zoomX;
    int _zoomY;
    int _zoomScale;
    int _zoomScaleTarget;
    int _zoomDuration;
    int _weatherType;
    int _weatherPower;
    int _weatherPowerTarget;
    int _weatherDuration;
};

#endif // GAME_SCREEN_H
