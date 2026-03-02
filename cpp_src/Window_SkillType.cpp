#include "Window_SkillType.h"

Window_SkillType::Window_SkillType(int x, int y) : Window_Command(x, y, 240, 0), _actorId(0) {
    initialize();
}

Window_SkillType::~Window_SkillType() {
}

void Window_SkillType::initialize() {
    refresh();
}

void Window_SkillType::refresh() {
}

void Window_SkillType::setActor(int actorId) {
    if (_actorId != actorId) {
        _actorId = actorId;
        refresh();
    }
}
