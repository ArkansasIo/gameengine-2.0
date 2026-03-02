#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0);
    
    double x;
    double y;
    
    Point* copyFrom(const Point& p);
    Point* copyTo(Point& p) const;
    bool equals(const Point& p) const;
    void set(double x = 0.0, double y = 0.0);
};

#endif // POINT_H
