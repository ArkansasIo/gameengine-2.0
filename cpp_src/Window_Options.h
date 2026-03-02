#ifndef WINDOW_OPTIONS_H
#define WINDOW_OPTIONS_H

#include "Window_Selectable.h"

class Window_Options : public Window_Selectable {
public:
    Window_Options();
    ~Window_Options();

    void initialize();
    void refresh();
    void statusText(int index) const;
    void processOk();

private:
};

#endif // WINDOW_OPTIONS_H
