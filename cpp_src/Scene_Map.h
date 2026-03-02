#ifndef SCENE_MAP_H
#define SCENE_MAP_H

#include "Scene_Base.h"

class Scene_Map : public Scene_Base {
public:
    Scene_Map();
    ~Scene_Map();

    virtual void initialize();
    virtual void create();
    virtual void start();
    virtual void update();
    virtual void stop();
    virtual void terminate();
    
    bool shouldAutosave() const;
    void updateTransferPlayer();
    void updateEncounter();
    void updateCallMenu();
    void updateCallSave();
    void updateCallDebug();
    void updateShowDebugCommands();
    void updateShowHideDebugMenu();
    void launchBattle();
    
private:
    void createDisplayObjects();
    void loadMapData();
    void onMapLoaded();
    void fadeInForTransfer();
    void fadeOutForTransfer();
};

#endif // SCENE_MAP_H
