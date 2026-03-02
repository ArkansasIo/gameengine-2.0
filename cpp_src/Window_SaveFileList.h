#ifndef WINDOW_SAVEFILELIST_H
#define WINDOW_SAVEFILELIST_H

#include "Window_Selectable.h"

class Window_SaveFileList : public Window_Selectable {
public:
    Window_SaveFileList(int x, int y, int width, int height);
    ~Window_SaveFileList();

    void setMode(int mode);  // 0: load, 1: save
    void refresh();
    void drawFileData(int index);

private:
    int _mode;
};

#endif // WINDOW_SAVEFILELIST_H
