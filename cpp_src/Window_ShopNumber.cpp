#include "Window_ShopNumber.h"

Window_ShopNumber::Window_ShopNumber(int x, int y, int height) 
    : Window_Selectable(x, y, 304, height), _item(nullptr), _max(0), _price(0), _number(1) {
    placeButtons();
}

Window_ShopNumber::~Window_ShopNumber() {
}

void Window_ShopNumber::setup(void *item, int max, int price) {
    _item = item;
    _max = max;
    _price = price;
    _number = 1;
}

void Window_ShopNumber::placeButtons() {
}
