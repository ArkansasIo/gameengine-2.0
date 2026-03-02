#include "Window_ItemList.h"

Window_ItemList::Window_ItemList(int x, int y, int width, int height) 
    : Window_Selectable(x, y, width, height) {
    refresh();
}

Window_ItemList::~Window_ItemList() {
}

void Window_ItemList::setCategory(const QString &category) {
    if (_category != category) {
        _category = category;
        refresh();
    }
}

void Window_ItemList::refresh() {
}

void *Window_ItemList::item() const {
    return nullptr;
}

bool Window_ItemList::includes(void *item) const {
    return false;
}

bool Window_ItemList::isEnabled(void *item) const {
    return true;
}
