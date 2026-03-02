#ifndef SCENE_STATUS_H
#define SCENE_STATUS_H

#include "Scene_Base.h"

class Window_Status;
class Window_StatusBase;

class Scene_Status : public Scene_Base {
public:
    Scene_Status();
    ~Scene_Status();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void nextActor();
    void previousActor();
    void onActorOk();
    void onActorCancel();
    
private:
    int _actorId;
    Window_Status *_statusWindow;
};

#endif // SCENE_STATUS_H
