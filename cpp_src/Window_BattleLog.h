#ifndef WINDOW_BATTLELOG_H
#define WINDOW_BATTLELOG_H

#include "Window_Selectable.h"

class Window_BattleLog : public Window_Selectable {
public:
    Window_BattleLog();
    ~Window_BattleLog();

    void clear();
    void addText(const QString &text);
    void displayAction(void *subject, void *item);
    void displayCounter(void *target);
    void displayReflection(void *target);
    void displayHeal(void *target, int value);
    void displayDamage(void *target, int value);
    void displayCritical(void *target);
    void displayMiss(void *target);
    void displayEvasion(void *target);
    void displayFailure(void *target);

private:
};

#endif // WINDOW_BATTLELOG_H
