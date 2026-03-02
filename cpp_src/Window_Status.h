#ifndef WINDOW_STATUS_H
#define WINDOW_STATUS_H

#include "Window_Base.h"

class Window_Status : public Window_Base {
public:
    Window_Status();
    ~Window_Status();

    void refresh();
    void setActor(int actorId);
    
private:
    int _actorId;
};

#endif // WINDOW_STATUS_H
