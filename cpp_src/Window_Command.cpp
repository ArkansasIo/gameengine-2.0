#include "Window_Command.h"

Window_Command::Window_Command(const QRect &rect)
    : Window_Selectable(rect) {
}

Window_Command::~Window_Command() {
}

void Window_Command::initialize() {
    Window_Selectable::initialize();
}

void Window_Command::setBackgroundType(int type) {
    Window_Base::setBackgroundType(type);
}

int Window_Command::windowHeight() const {
    return fittingHeight(_list.size());
}

int Window_Command::itemHeight() const {
    return lineHeight();
}

int Window_Command::maxItems() const {
    return _list.size();
}

void Window_Command::addCommand(const QString &name, const QString &symbol, bool enabled) {
    int index = _list.size();
    _list.append(name);
    _symbols[index] = symbol;
    _enabled[index] = enabled;
}

void Window_Command::addItem(const QString &name, const QString &symbol) {
    addCommand(name, symbol, true);
}

void Window_Command::addOriginalCommand(const QString &name, const QString &symbol) {
    addCommand(name, symbol, true);
}

bool Window_Command::isCommandEnabled(int index) const {
    return _enabled.value(index, true);
}

QString Window_Command::commandName(int index) const {
    return index < _list.size() ? _list[index] : QString();
}

QString Window_Command::commandSymbol(int index) const {
    return _symbols.value(index, QString());
}

void Window_Command::drawItem(int index) {
}

void Window_Command::refresh() {
}

void Window_Command::updatePlacement() {
}

void Window_Command::deactivate() {
    Window_Selectable::deactivate();
}
