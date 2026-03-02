#ifndef SCENE_ITEM_H
#define SCENE_ITEM_H

#include "Scene_Base.h"

class Window_Help;
class Window_ItemList;
class Window_ItemCategory;

class Scene_Item : public Scene_Base {
public:
    Scene_Item();
    ~Scene_Item();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void onItemOk();
    void onItemCancel();
    void onCategoryOk();
    void onCategoryCancel();
    
private:
    Window_Help *_helpWindow;
    Window_ItemCategory *_categoryWindow;
    Window_ItemList *_itemWindow;
};

#endif // SCENE_ITEM_H
