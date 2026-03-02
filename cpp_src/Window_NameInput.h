#ifndef WINDOW_NAMEINPUT_H
#define WINDOW_NAMEINPUT_H

#include "Window_Selectable.h"

class Window_NameInput : public Window_Selectable {
public:
    Window_NameInput();
    ~Window_NameInput();

    void initialize();
    QString name() const;
    void setEditWindow(void *editWindow);
    void onNameOk();
    void onNameCancel();

private:
};

#endif // WINDOW_NAMEINPUT_H
