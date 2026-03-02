#ifndef WINDOW_SHOPSELL_H
#define WINDOW_SHOPSELL_H

#include "Window_ItemList.h"

class Window_ShopSell : public Window_ItemList {
public:
    Window_ShopSell(int x, int y, int width, int height);
    ~Window_ShopSell();

    void refresh();
    bool isEnabled(void *item) const;

private:
};

#endif // WINDOW_SHOPSELL_H
