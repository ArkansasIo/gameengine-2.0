#ifndef WINDOW_MENUCOMMAND_H
#define WINDOW_MENUCOMMAND_H

#include "Window_Command.h"

class Window_MenuCommand : public Window_Command {
public:
    Window_MenuCommand(int x, int y);
    ~Window_MenuCommand();

    void initialize();
    void refresh();
    
    bool isFormationEnabled() const;
    void setFormationEnabled(bool enabled);

private:
};

#endif // WINDOW_MENUCOMMAND_H
