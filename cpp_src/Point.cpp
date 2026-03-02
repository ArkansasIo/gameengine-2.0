#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {
}

Point* Point::copyFrom(const Point& p) {
    x = p.x;
    y = p.y;
    return this;
}

Point* Point::copyTo(Point& p) const {
    p.x = x;
    p.y = y;
    return &p;
}

bool Point::equals(const Point& p) const {
    return x == p.x && y == p.y;
}

void Point::set(double newX, double newY) {
    x = newX;
    y = newY;
}
