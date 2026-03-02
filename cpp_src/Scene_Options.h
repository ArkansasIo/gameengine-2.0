#ifndef SCENE_OPTIONS_H
#define SCENE_OPTIONS_H

#include "Scene_Base.h"

class Window_Options;

class Scene_Options : public Scene_Base {
public:
    Scene_Options();
    ~Scene_Options();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void onOptionsOk();
    void onOptionsCancel();

private:
    Window_Options *_optionsWindow;
};

#endif // SCENE_OPTIONS_H
