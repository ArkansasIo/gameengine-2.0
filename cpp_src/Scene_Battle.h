#ifndef SCENE_BATTLE_H
#define SCENE_BATTLE_H

#include "Scene_Base.h"

class Window_BattleLog;
class Window_Message;

class Scene_Battle : public Scene_Base {
public:
    Scene_Battle();
    ~Scene_Battle();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void updateBattleProcess();
    void changeInputWindow();
    void startPartyCommandSelection();
    void startActorCommandSelection();
    void selectNextCommand();
    void selectPreviousCommand();
    void startActorSelection();
    void startEnemySelection();
    void onActorOk();
    void onActorCancel();
    void onEnemyOk();
    void onEnemyCancel();
    
private:
    Window_BattleLog *_logWindow;
    int _battlePhase;
};

#endif // SCENE_BATTLE_H
