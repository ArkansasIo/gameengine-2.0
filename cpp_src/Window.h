#ifndef WINDOW_H
#define WINDOW_H

#include "Sprite.h"
#include <string>

class Window : public Sprite {
public:
    Window(int x, int y, int width, int height);
    virtual ~Window();
    
    // Properties
    int windowWidth;
    int windowHeight;
    int padding;
    int margin;
    bool active;
    bool openness;
    
    // Methods
    virtual void update() override;
    void move(int x, int y, int width, int height);
    bool isOpen() const;
    bool isClosed() const;
    void open();
    void close();
    void activate();
    void deactivate();
    void updateTransform();
    void updateTone();
    void addChildToBack(Sprite* child);
    void updatePadding();
    void updateBackOpacity();
    void setTone(int r, int g, int b);
    void addInnerChild(Sprite* child);
    void updateInnerChildren();
    
protected:
    int _tone[3];
    bool _opening;
    bool _closing;
};

#endif // WINDOW_H
