#ifndef SCENE_BOOT_H
#define SCENE_BOOT_H

#include "Scene_Base.h"

class Scene_Boot : public Scene_Base {
public:
    Scene_Boot();
    ~Scene_Boot();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void checkPlayerLocation();
    void updateDocumentTitle();
    void loadDatabase();
    void loadImages();
    void startNewGame();
    
private:
    bool _databaseLoaded;
};

#endif // SCENE_BOOT_H
