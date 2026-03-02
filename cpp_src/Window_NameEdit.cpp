#include "Window_NameEdit.h"

Window_NameEdit::Window_NameEdit() : Window_Base(0, 0, 600, 108), _actorId(0), _maxLength(20) {
    refresh();
}

Window_NameEdit::~Window_NameEdit() {
}

void Window_NameEdit::setActor(int actorId) {
    if (_actorId != actorId) {
        _actorId = actorId;
        refresh();
    }
}

void Window_NameEdit::setMaxLength(int maxLength) {
    _maxLength = maxLength;
}

void Window_NameEdit::refresh() {
}
