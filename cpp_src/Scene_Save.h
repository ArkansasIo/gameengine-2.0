#ifndef SCENE_SAVE_H
#define SCENE_SAVE_H

#include "Scene_Base.h"

class Window_SaveFileList;

class Scene_Save : public Scene_Base {
public:
    Scene_Save();
    ~Scene_Save();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void onSavefileOk();
    void onSavefileCancel();
    void executeSave(int saveIndex);
    
private:
    Window_SaveFileList *_listWindow;
};

#endif // SCENE_SAVE_H
