#ifndef SCENE_NAME_H
#define SCENE_NAME_H

#include "Scene_Base.h"

class Window_NameEdit;
class Window_NameInput;

class Scene_Name : public Scene_Base {
public:
    Scene_Name();
    ~Scene_Name();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void onInputOk();
    void onInputCancel();
    
private:
    int _actorId;
    Window_NameEdit *_editWindow;
    Window_NameInput *_inputWindow;
};

#endif // SCENE_NAME_H
