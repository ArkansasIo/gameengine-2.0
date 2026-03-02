#ifndef WINDOW_NAMEEDIT_H
#define WINDOW_NAMEEDIT_H

#include "Window_Base.h"

class Window_NameEdit : public Window_Base {
public:
    Window_NameEdit();
    ~Window_NameEdit();

    void setActor(int actorId);
    void setMaxLength(int maxLength);
    void refresh();

private:
    int _actorId;
    int _maxLength;
};

#endif // WINDOW_NAMEEDIT_H
