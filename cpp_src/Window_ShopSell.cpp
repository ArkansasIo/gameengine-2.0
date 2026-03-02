#include "Window_ShopSell.h"

Window_ShopSell::Window_ShopSell(int x, int y, int width, int height) 
    : Window_ItemList(x, y, width, height) {
    refresh();
}

Window_ShopSell::~Window_ShopSell() {
}

void Window_ShopSell::refresh() {
}

bool Window_ShopSell::isEnabled(void *item) const {
    return true;
}
