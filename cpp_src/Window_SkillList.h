#ifndef WINDOW_SKILLLIST_H
#define WINDOW_SKILLLIST_H

#include "Window_Selectable.h"

class Window_SkillList : public Window_Selectable {
public:
    Window_SkillList(int x, int y, int width, int height);
    ~Window_SkillList();

    void setActor(int actorId);
    void setSkillType(int skillType);
    void refresh();
    
    void *skill() const;
    bool includes(void *skill) const;
    bool isEnabled(void *skill) const;
    
private:
    int _actorId;
    int _skillType;
};

#endif // WINDOW_SKILLLIST_H
