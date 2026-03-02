#include "Window_ShopStatus.h"

Window_ShopStatus::Window_ShopStatus(int x, int y, int width, int height) 
    : Window_Base(x, y, width, height), _item(nullptr), _actorId(0) {
    refresh();
}

Window_ShopStatus::~Window_ShopStatus() {
}

void Window_ShopStatus::refresh() {
}

void Window_ShopStatus::setItem(void *item, int actor) {
    _item = item;
    _actorId = actor;
}
