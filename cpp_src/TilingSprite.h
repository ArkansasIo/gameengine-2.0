#ifndef TILINGSPRITE_H
#define TILINGSPRITE_H

class TilingSprite {
public:
    TilingSprite();
    ~TilingSprite();

    void initialize();
    void update();
    
    void setPosition(double x, double y);
    void setScale(double scaleX, double scaleY);
    void setOpacity(int opacity);
    
    double x() const;
    double y() const;

private:
    double _x, _y;
    double _scaleX, _scaleY;
    int _opacity;
};

#endif // TILINGSPRITE_H
