#include "Window_EquipStatus.h"

Window_EquipStatus::Window_EquipStatus(int x, int y) 
    : Window_Base(x, y, 312, 416), _actorId(0) {
    refresh();
}

Window_EquipStatus::~Window_EquipStatus() {
}

void Window_EquipStatus::refresh() {
}

void Window_EquipStatus::setActor(int actorId) {
    if (_actorId != actorId) {
        _actorId = actorId;
        refresh();
    }
}
