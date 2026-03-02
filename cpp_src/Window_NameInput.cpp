#include "Window_NameInput.h"

Window_NameInput::Window_NameInput() : Window_Selectable(0, 108, 600, 516) {
    initialize();
}

Window_NameInput::~Window_NameInput() {
}

void Window_NameInput::initialize() {
}

QString Window_NameInput::name() const {
    return "";
}

void Window_NameInput::setEditWindow(void *editWindow) {
}

void Window_NameInput::onNameOk() {
}

void Window_NameInput::onNameCancel() {
}
