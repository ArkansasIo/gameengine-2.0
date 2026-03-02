#include "Window_Gold.h"

Window_Gold::Window_Gold(int x, int y) : Window_Base(x, y, 240, 108), _goldValue(0) {
    refresh();
}

Window_Gold::~Window_Gold() {
}

void Window_Gold::refresh() {
}

void Window_Gold::open() {
    Window_Base::open();
}

void Window_Gold::close() {
    Window_Base::close();
}
