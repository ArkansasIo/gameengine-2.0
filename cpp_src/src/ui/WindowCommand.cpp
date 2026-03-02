#include "../../include/ui/WindowCommand.h"

namespace LunaLite {
namespace UI {

WindowCommand::WindowCommand(int x, int y, int width)
    : WindowBase(x, y, width, 0) {
}

WindowCommand::~WindowCommand() {
}

void WindowCommand::addCommand(const QString &name) {
    _commands.append(name);
    _enabled.append(true);
    _height += 36;  // Typical line height
}

void WindowCommand::removeCommand(int index) {
    if (index >= 0 && index < _commands.size()) {
        _commands.remove(index);
        _enabled.remove(index);
        _height -= 36;
    }
}

void WindowCommand::clearCommands() {
    _commands.clear();
    _enabled.clear();
    _height = 0;
}

int WindowCommand::getCommandCount() const {
    return _commands.size();
}

QString WindowCommand::getCommand(int index) const {
    if (index >= 0 && index < _commands.size()) {
        return _commands[index];
    }
    return "";
}

int WindowCommand::getSelectedIndex() const {
    return _cursorIndex;
}

void WindowCommand::selectItem(int index) {
    if (index >= 0 && index < _commands.size()) {
        _cursorIndex = index;
    }
}

void WindowCommand::selectNext() {
    if (_cursorIndex < _commands.size() - 1) {
        _cursorIndex++;
    }
}

void WindowCommand::selectPrev() {
    if (_cursorIndex > 0) {
        _cursorIndex--;
    }
}

void WindowCommand::selectOk() {
    if (_okCallback && _cursorIndex < _commands.size()) {
        _okCallback(_cursorIndex);
    }
}

void WindowCommand::enableCommand(int index) {
    if (index >= 0 && index < _enabled.size()) {
        _enabled[index] = true;
    }
}

void WindowCommand::disableCommand(int index) {
    if (index >= 0 && index < _enabled.size()) {
        _enabled[index] = false;
    }
}

bool WindowCommand::isCommandEnabled(int index) const {
    if (index >= 0 && index < _enabled.size()) {
        return _enabled[index];
    }
    return false;
}

void WindowCommand::setOkCallback(CommandCallback callback) {
    _okCallback = callback;
}

void WindowCommand::setCancelCallback(CommandCallback callback) {
    _cancelCallback = callback;
}

void WindowCommand::update() {
    WindowBase::update();
}

} // namespace UI
} // namespace LunaLite
