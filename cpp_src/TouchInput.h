#ifndef TOUCH_INPUT_H
#define TOUCH_INPUT_H

class TouchInput {
public:
    static bool _mousePressed;
    static int _screenPressed;
    static int _pressedTime;
    static int _x;
    static int _y;
    static int _date;
    
    static void initialize();
    static void clear();
    static void update();
    static bool isPressed();
    static bool isTriggered();
    static bool isRepeated();
    static bool isLongPressed();
    static bool isCancelled();
    static bool isMoved();
    static int wheelX();
    static int wheelY();
    static int x();
    static int y();
    
private:
    TouchInput() = delete;
};

#endif // TOUCH_INPUT_H
