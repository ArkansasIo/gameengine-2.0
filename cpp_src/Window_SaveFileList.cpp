#include "Window_SaveFileList.h"

Window_SaveFileList::Window_SaveFileList(int x, int y, int width, int height) 
    : Window_Selectable(x, y, width, height), _mode(0) {
    refresh();
}

Window_SaveFileList::~Window_SaveFileList() {
}

void Window_SaveFileList::setMode(int mode) {
    _mode = mode;
    refresh();
}

void Window_SaveFileList::refresh() {
}

void Window_SaveFileList::drawFileData(int index) {
}
