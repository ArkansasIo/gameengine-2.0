#ifndef WINDOW_ACTORCOMMAND_H
#define WINDOW_ACTORCOMMAND_H

#include "Window_Command.h"

class Window_ActorCommand : public Window_Command {
public:
    Window_ActorCommand();
    ~Window_ActorCommand();

    void setup(int actorId);

private:
    int _actorId;
};

#endif // WINDOW_ACTORCOMMAND_H
