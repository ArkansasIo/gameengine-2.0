#ifndef SCENE_TITLE_H
#define SCENE_TITLE_H

#include "Scene_Base.h"

class Scene_Title : public Scene_Base {
public:
    Scene_Title();
    ~Scene_Title();

    virtual void initialize();
    virtual void create();
    virtual void start();
    virtual void update();
    virtual void stop();
    virtual void terminate();
    
private:
    void createBackground();
    void createForeground();
    void createWindowLayer();
    void drawGameTitle();
    void centerSprite();
    void playTitleMusic();
    void commandNewGame();
    void commandContinue();
    void commandOptions();
};

#endif // SCENE_TITLE_H
