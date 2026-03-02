#ifndef TONESPRITE_H
#define TONESPRITE_H

class ToneSprite {
public:
    ToneSprite();
    ~ToneSprite();

    void initialize();
    void update();
    
    void setTone(int r, int g, int b, int gray);

private:
    int _red, _green, _blue, _gray;
};

#endif // TONESPRITE_H
