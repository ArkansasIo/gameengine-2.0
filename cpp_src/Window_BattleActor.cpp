#include "Window_BattleActor.h"

Window_BattleActor::Window_BattleActor() : Window_Selectable(0, 408, 816, 216) {
}

Window_BattleActor::~Window_BattleActor() {
}

void Window_BattleActor::setup(int statusType) {
}

void Window_BattleActor::show() {
    Window_Selectable::show();
}

void Window_BattleActor::hide() {
    Window_Selectable::hide();
}
