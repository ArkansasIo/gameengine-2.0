#ifndef SPRITE_H
#define SPRITE_H

#include "Point.h"
#include "Rectangle.h"
#include "Bitmap.h"
#include <vector>

class Sprite {
public:
    Sprite(Bitmap* bitmap = nullptr);
    virtual ~Sprite();
    
    // Properties
    Bitmap* bitmap;
    int width;
    int height;
    int opacity;
    Point* anchor;
    Point* scale;
    Point* position;
    double rotation;
    bool visible;
    double x;
    double y;
    
    // Methods
    virtual void update();
    void move(double x, double y);
    void setFrame(int x, int y, int width, int height);
    Rectangle* getFrame() const;
    void updateTransform();
    
protected:
    Rectangle* _frame;
};

#endif // SPRITE_H
