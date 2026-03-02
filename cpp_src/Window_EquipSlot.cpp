#include "Window_EquipSlot.h"

Window_EquipSlot::Window_EquipSlot(int x, int y, int width, int height) 
    : Window_Selectable(x, y, width, height), _actorId(0) {
    refresh();
}

Window_EquipSlot::~Window_EquipSlot() {
}

void Window_EquipSlot::setActor(int actorId) {
    if (_actorId != actorId) {
        _actorId = actorId;
        refresh();
    }
}

void Window_EquipSlot::refresh() {
}

int Window_EquipSlot::slotId() const {
    return 0;
}

void *Window_EquipSlot::item() const {
    return nullptr;
}

bool Window_EquipSlot::isEnabled(int index) const {
    return true;
}
