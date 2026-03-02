#ifndef WINDOW_BATTLESTATUS_H
#define WINDOW_BATTLESTATUS_H

#include "Window_Selectable.h"

class Window_BattleStatus : public Window_Selectable {
public:
    Window_BattleStatus();
    ~Window_BattleStatus();

    void initialize();
    void refresh();

private:
};

#endif // WINDOW_BATTLESTATUS_H
