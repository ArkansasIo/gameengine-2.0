#include "Rectangle.h"
#include <algorithm>

Rectangle Rectangle::emptyRectangle(0, 0, 0, 0);

Rectangle::Rectangle(double x, double y, double width, double height) 
    : x(x), y(y), width(width), height(height) {
}

double Rectangle::left() const {
    return x;
}

double Rectangle::right() const {
    return x + width;
}

double Rectangle::top() const {
    return y;
}

double Rectangle::bottom() const {
    return y + height;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(x, y, width, height);
}

Rectangle* Rectangle::copy(const Rectangle& rectangle) {
    x = rectangle.x;
    y = rectangle.y;
    width = rectangle.width;
    height = rectangle.height;
    return this;
}

bool Rectangle::contains(double px, double py) const {
    return px >= x && px <= x + width && py >= y && py <= y + height;
}

void Rectangle::pad(double padX, double padY) {
    x -= padX;
    y -= padY;
    width += padX * 2;
    height += padY * 2;
}

void Rectangle::fit(const Rectangle& rectangle) {
    double x1 = std::max(x, rectangle.x);
    double y1 = std::max(y, rectangle.y);
    double x2 = std::min(x + width, rectangle.x + rectangle.width);
    double y2 = std::min(y + height, rectangle.y + rectangle.height);
    
    x = x1;
    y = y1;
    width = x2 - x1;
    height = y2 - y1;
}

void Rectangle::enlarge(const Rectangle& rectangle) {
    double x1 = std::min(x, rectangle.x);
    double y1 = std::min(y, rectangle.y);
    double x2 = std::max(x + width, rectangle.x + rectangle.width);
    double y2 = std::max(y + height, rectangle.y + rectangle.height);
    
    x = x1;
    y = y1;
    width = x2 - x1;
    height = y2 - y1;
}
