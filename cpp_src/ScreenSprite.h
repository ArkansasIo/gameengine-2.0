#ifndef SCREENSPRITE_H
#define SCREENSPRITE_H

class ScreenSprite {
public:
    ScreenSprite();
    ~ScreenSprite();

    void initialize();
    void setBlendColor(int r, int g, int b, int a);
    void setTone(int r, int g, int b, int gray);
    void update();

private:
    int _red, _green, _blue, _alpha;
};

#endif // SCREENSPRITE_H
