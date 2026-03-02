#include "Sprite.h"

Sprite::Sprite(Bitmap* bmp) 
    : bitmap(bmp), width(0), height(0), opacity(255), 
      rotation(0.0), visible(true), x(0.0), y(0.0) {
    anchor = new Point(0.0, 0.0);
    scale = new Point(1.0, 1.0);
    position = new Point(0.0, 0.0);
    _frame = new Rectangle(0, 0, 0, 0);
    
    if (bitmap) {
        width = bitmap->width;
        height = bitmap->height;
    }
}

Sprite::~Sprite() {
    delete anchor;
    delete scale;
    delete position;
    delete _frame;
}

void Sprite::update() {
}

void Sprite::move(double newX, double newY) {
    x = newX;
    y = newY;
    position->x = newX;
    position->y = newY;
}

void Sprite::setFrame(int fx, int fy, int fw, int fh) {
    _frame->x = fx;
    _frame->y = fy;
    _frame->width = fw;
    _frame->height = fh;
}

Rectangle* Sprite::getFrame() const {
    return _frame;
}

void Sprite::updateTransform() {
}
