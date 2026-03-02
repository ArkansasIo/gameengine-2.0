#ifndef WINDOW_EQUIPCOMMAND_H
#define WINDOW_EQUIPCOMMAND_H

#include "Window_Command.h"

class Window_EquipCommand : public Window_Command {
public:
    Window_EquipCommand(int x, int y, int width);
    ~Window_EquipCommand();

    void initialize();

private:
};

#endif // WINDOW_EQUIPCOMMAND_H
