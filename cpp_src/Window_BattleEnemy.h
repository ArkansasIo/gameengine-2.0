#ifndef WINDOW_BATTLEENEMY_H
#define WINDOW_BATTLEENEMY_H

#include "Window_Selectable.h"

class Window_BattleEnemy : public Window_Selectable {
public:
    Window_BattleEnemy(int x, int y, int width, int height);
    ~Window_BattleEnemy();

    void refreshCursor();
    void show();
    void hide();

private:
};

#endif // WINDOW_BATTLEENEMY_H
