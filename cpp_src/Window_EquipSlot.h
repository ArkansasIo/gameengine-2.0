#ifndef WINDOW_EQUIPSLOT_H
#define WINDOW_EQUIPSLOT_H

#include "Window_Selectable.h"

class Window_EquipSlot : public Window_Selectable {
public:
    Window_EquipSlot(int x, int y, int width, int height);
    ~Window_EquipSlot();

    void setActor(int actorId);
    void refresh();
    
    int slotId() const;
    void *item() const;
    bool isEnabled(int index) const;

private:
    int _actorId;
};

#endif // WINDOW_EQUIPSLOT_H
