#ifndef WINDOW_BATTLEACTOR_H
#define WINDOW_BATTLEACTOR_H

#include "Window_Selectable.h"

class Window_BattleActor : public Window_Selectable {
public:
    Window_BattleActor();
    ~Window_BattleActor();

    void setup(int statusType);
    void show();
    void hide();

private:
};

#endif // WINDOW_BATTLEACTOR_H
