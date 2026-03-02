#ifndef WINDOW_HELP_H
#define WINDOW_HELP_H

#include "Window_Base.h"

class Window_Help : public Window_Base {
public:
    Window_Help(int height = 108);
    ~Window_Help();

    void setText(const QString &text);
    void clear();
    void setItem(void *item);
    
private:
    QString _text;
};

#endif // WINDOW_HELP_H
