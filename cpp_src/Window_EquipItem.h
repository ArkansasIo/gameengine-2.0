#ifndef WINDOW_EQUIPITEM_H
#define WINDOW_EQUIPITEM_H

#include "Window_ItemList.h"

class Window_EquipItem : public Window_ItemList {
public:
    Window_EquipItem(int x, int y, int width, int height);
    ~Window_EquipItem();

    void setSlotId(int slotId);
    void setActor(int actorId);

private:
    int _slotId;
    int _actorId;
};

#endif // WINDOW_EQUIPITEM_H
