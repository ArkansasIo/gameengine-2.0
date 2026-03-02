#ifndef WINDOW_EQUIPSTATUS_H
#define WINDOW_EQUIPSTATUS_H

#include "Window_Base.h"

class Window_EquipStatus : public Window_Base {
public:
    Window_EquipStatus(int x, int y);
    ~Window_EquipStatus();

    void refresh();
    void setActor(int actorId);

private:
    int _actorId;
};

#endif // WINDOW_EQUIPSTATUS_H
