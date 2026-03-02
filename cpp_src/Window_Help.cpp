#include "Window_Help.h"

Window_Help::Window_Help(int height) : Window_Base(0, 0, 816, height) {
}

Window_Help::~Window_Help() {
}

void Window_Help::setText(const QString &text) {
    if (_text != text) {
        _text = text;
    }
}

void Window_Help::clear() {
    _text = "";
}

void Window_Help::setItem(void *item) {
}
