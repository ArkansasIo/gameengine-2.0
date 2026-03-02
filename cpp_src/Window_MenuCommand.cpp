#include "Window_MenuCommand.h"

Window_MenuCommand::Window_MenuCommand(int x, int y) : Window_Command(x, y, 240, 0) {
    initialize();
}

Window_MenuCommand::~Window_MenuCommand() {
}

void Window_MenuCommand::initialize() {
    refresh();
}

void Window_MenuCommand::refresh() {
}

bool Window_MenuCommand::isFormationEnabled() const {
    return true;
}

void Window_MenuCommand::setFormationEnabled(bool enabled) {
}
