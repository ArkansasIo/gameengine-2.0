#include "Window_BattleLog.h"

Window_BattleLog::Window_BattleLog() : Window_Selectable(0, 408, 816, 216) {
    clear();
}

Window_BattleLog::~Window_BattleLog() {
}

void Window_BattleLog::clear() {
}

void Window_BattleLog::addText(const QString &text) {
}

void Window_BattleLog::displayAction(void *subject, void *item) {
}

void Window_BattleLog::displayCounter(void *target) {
}

void Window_BattleLog::displayReflection(void *target) {
}

void Window_BattleLog::displayHeal(void *target, int value) {
}

void Window_BattleLog::displayDamage(void *target, int value) {
}

void Window_BattleLog::displayCritical(void *target) {
}

void Window_BattleLog::displayMiss(void *target) {
}

void Window_BattleLog::displayEvasion(void *target) {
}

void Window_BattleLog::displayFailure(void *target) {
}
