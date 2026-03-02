#include "Window_SkillList.h"

Window_SkillList::Window_SkillList(int x, int y, int width, int height) 
    : Window_Selectable(x, y, width, height), _actorId(0), _skillType(0) {
    refresh();
}

Window_SkillList::~Window_SkillList() {
}

void Window_SkillList::setActor(int actorId) {
    if (_actorId != actorId) {
        _actorId = actorId;
        refresh();
    }
}

void Window_SkillList::setSkillType(int skillType) {
    if (_skillType != skillType) {
        _skillType = skillType;
        refresh();
    }
}

void Window_SkillList::refresh() {
}

void *Window_SkillList::skill() const {
    return nullptr;
}

bool Window_SkillList::includes(void *skill) const {
    return false;
}

bool Window_SkillList::isEnabled(void *skill) const {
    return true;
}
