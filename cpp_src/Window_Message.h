#ifndef WINDOW_MESSAGEPOPPUP_H
#define WINDOW_MESSAGEPOPPUP_H

#include "Window_Base.h"

class Window_Message : public Window_Base {
public:
    Window_Message();
    ~Window_Message();

    void initialize();
    void startMessage();
    void updatePlacement();
    void updateBackground();
    void terminateMessage();
    
    bool isOpen() const;
    bool isClosing() const;
    bool isWaiting() const;
    
    void setBackground(int background);
    void setPositionType(int positionType);
    void setDimensions(int width, int height);

private:
    int _background;
    int _positionType;
};

#endif // WINDOW_MESSAGEPOPPUP_H
