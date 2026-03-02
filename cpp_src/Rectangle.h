#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
    Rectangle(double x = 0.0, double y = 0.0, double width = 0.0, double height = 0.0);
    
    double x;
    double y;
    double width;
    double height;
    
    double left() const;
    double right() const;
    double top() const;
    double bottom() const;
    
    Rectangle* clone() const;
    Rectangle* copy(const Rectangle& rectangle);
    bool contains(double x, double y) const;
    void pad(double padX, double padY);
    void fit(const Rectangle& rectangle);
    void enlarge(const Rectangle& rectangle);
    
    static Rectangle emptyRectangle;
};

#endif // RECTANGLE_H
