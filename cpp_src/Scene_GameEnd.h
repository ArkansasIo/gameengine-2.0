#ifndef SCENE_GAMEEND_H
#define SCENE_GAMEEND_H

#include "Scene_Base.h"

class Window_GameEndCommand;

class Scene_GameEnd : public Scene_Base {
public:
    Scene_GameEnd();
    ~Scene_GameEnd();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void commandToTitle();
    void commandCancel();
    
private:
    Window_GameEndCommand *_commandWindow;
};

#endif // SCENE_GAMEEND_H
