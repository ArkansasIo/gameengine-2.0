#ifndef SCENE_SKILL_H
#define SCENE_SKILL_H

#include "Scene_Base.h"

class Window_SkillType;
class Window_SkillList;
class Window_SkillStatus;

class Scene_Skill : public Scene_Base {
public:
    Scene_Skill();
    ~Scene_Skill();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void onPersonalOk();
    void onPersonalCancel();
    void onSkillOk();
    void onSkillCancel();
    
private:
    Window_SkillType *_skillTypeWindow;
    Window_SkillList *_skillListWindow;
    Window_SkillStatus *_statusWindow;
};

#endif // SCENE_SKILL_H
