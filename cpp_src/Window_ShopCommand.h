#ifndef WINDOW_SHOPCOMMAND_H
#define WINDOW_SHOPCOMMAND_H

#include "Window_Command.h"

class Window_ShopCommand : public Window_Command {
public:
    Window_ShopCommand(int width);
    ~Window_ShopCommand();

    void initialize();

private:
};

#endif // WINDOW_SHOPCOMMAND_H
