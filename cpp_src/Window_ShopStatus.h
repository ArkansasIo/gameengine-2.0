#ifndef WINDOW_SHOPSTATUS_H
#define WINDOW_SHOPSTATUS_H

#include "Window_Base.h"

class Window_ShopStatus : public Window_Base {
public:
    Window_ShopStatus(int x, int y, int width, int height);
    ~Window_ShopStatus();

    void refresh();
    void setItem(void *item, int actor);

private:
    void *_item;
    int _actorId;
};

#endif // WINDOW_SHOPSTATUS_H
