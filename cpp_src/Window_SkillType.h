#ifndef WINDOW_SKILLTYPE_H
#define WINDOW_SKILLTYPE_H

#include "Window_Command.h"

class Window_SkillType : public Window_Command {
public:
    Window_SkillType(int x, int y);
    ~Window_SkillType();

    void initialize();
    void refresh();
    void setActor(int actorId);
    
private:
    int _actorId;
};

#endif // WINDOW_SKILLTYPE_H
