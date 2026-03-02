#ifndef SCENE_GAMEOVER_H
#define SCENE_GAMEOVER_H

#include "Scene_Base.h"

class Scene_Gameover : public Scene_Base {
public:
    Scene_Gameover();
    ~Scene_Gameover();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void playGameoverMusic();
    void waitCount() const;
    void setWaitCount(int count);
    void gotoTitle();
    void gotoMenu();
    
private:
    int _waitCount;
};

#endif // SCENE_GAMEOVER_H
