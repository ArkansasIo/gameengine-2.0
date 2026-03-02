#ifndef SCENE_EQUIP_H
#define SCENE_EQUIP_H

#include "Scene_Base.h"

class Window_EquipStatus;
class Window_EquipCommand;
class Window_EquipSlot;
class Window_EquipItem;

class Scene_Equip : public Scene_Base {
public:
    Scene_Equip();
    ~Scene_Equip();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void onSlotOk();
    void onSlotCancel();
    void onItemOk();
    void onItemCancel();
    void onActorChange();
    
private:
    int _actorId;
    Window_EquipStatus *_statusWindow;
    Window_EquipCommand *_commandWindow;
    Window_EquipSlot *_slotWindow;
    Window_EquipItem *_itemWindow;
};

#endif // SCENE_EQUIP_H
