#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include "Scene_Base.h"

class Window_Command;
class Window_Gold;
class Window_Status;

class Scene_Menu : public Scene_Base {
public:
    Scene_Menu();
    ~Scene_Menu();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void commandItem();
    void commandSkill();
    void commandEquip();
    void commandStatus();
    void commandArrange();
    void commandFormation();
    void commandOptions();
    void commandSave();
    void commandLoad();
    void commandGameEnd();
    
private:
    Window_Command *_commandWindow;
    Window_Gold *_goldWindow;
    Window_Status *_statusWindow;
};

#endif // SCENE_MENU_H
