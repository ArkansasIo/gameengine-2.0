#ifndef WINDOW_GOLD_H
#define WINDOW_GOLD_H

#include "Window_Base.h"

class Window_Gold : public Window_Base {
public:
    Window_Gold(int x = 0, int y = 0);
    ~Window_Gold();

    void refresh();
    void open();
    void close();
    
private:
    int _goldValue;
};

#endif // WINDOW_GOLD_H
