#ifndef WINDOW_CATEGORYITEM_H
#define WINDOW_CATEGORYITEM_H

#include "Window_Command.h"

class Window_ItemCategory : public Window_Command {
public:
    Window_ItemCategory();
    ~Window_ItemCategory();

    void initialize();
    void refresh();

private:
};

#endif // WINDOW_CATEGORYITEM_H
