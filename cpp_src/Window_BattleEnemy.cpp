#include "Window_BattleEnemy.h"

Window_BattleEnemy::Window_BattleEnemy(int x, int y, int width, int height)
    : Window_Selectable(x, y, width, height) {
}

Window_BattleEnemy::~Window_BattleEnemy() {
}

void Window_BattleEnemy::refreshCursor() {
}

void Window_BattleEnemy::show() {
    Window_Selectable::show();
}

void Window_BattleEnemy::hide() {
    Window_Selectable::hide();
}
