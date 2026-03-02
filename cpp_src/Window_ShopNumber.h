#ifndef WINDOW_SHOPNUMBER_H
#define WINDOW_SHOPNUMBER_H

#include "Window_Selectable.h"

class Window_ShopNumber : public Window_Selectable {
public:
    Window_ShopNumber(int x, int y, int height);
    ~Window_ShopNumber();

    void setup(void *item, int max, int price);
    void placeButtons();

private:
    void *_item;
    int _max;
    int _price;
    int _number;
};

#endif // WINDOW_SHOPNUMBER_H
