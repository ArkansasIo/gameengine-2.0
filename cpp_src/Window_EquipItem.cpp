#include "Window_EquipItem.h"

Window_EquipItem::Window_EquipItem(int x, int y, int width, int height) 
    : Window_ItemList(x, y, width, height), _slotId(0), _actorId(0) {
}

Window_EquipItem::~Window_EquipItem() {
}

void Window_EquipItem::setSlotId(int slotId) {
    if (_slotId != slotId) {
        _slotId = slotId;
        refresh();
    }
}

void Window_EquipItem::setActor(int actorId) {
    if (_actorId != actorId) {
        _actorId = actorId;
        refresh();
    }
}
