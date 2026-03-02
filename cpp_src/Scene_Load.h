#ifndef SCENE_LOAD_H
#define SCENE_LOAD_H

#include "Scene_Base.h"

class Window_SaveFileList;

class Scene_Load : public Scene_Base {
public:
    Scene_Load();
    ~Scene_Load();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void onSavefileOk();
    void onSavefileCancel();
    void executeLoad(int saveIndex);
    bool isValidSavefileIndex(int index) const;
    
private:
    Window_SaveFileList *_listWindow;
};

#endif // SCENE_LOAD_H
