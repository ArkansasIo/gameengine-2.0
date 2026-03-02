#include "Window_Status.h"

Window_Status::Window_Status() : Window_Base(0, 0, 816, 624), _actorId(0) {
    refresh();
}

Window_Status::~Window_Status() {
}

void Window_Status::refresh() {
}

void Window_Status::setActor(int actorId) {
    if (_actorId != actorId) {
        _actorId = actorId;
        refresh();
    }
}
