#ifndef SCENE_SHOP_H
#define SCENE_SHOP_H

#include "Scene_Base.h"

class Window_ShopCommand;
class Window_ShopBuy;
class Window_ShopSell;
class Window_ShopNumber;
class Window_ShopStatus;

class Scene_Shop : public Scene_Base {
public:
    Scene_Shop();
    ~Scene_Shop();

    void initialize() override;
    void create() override;
    void start() override;
    void update() override;
    void stop() override;
    void terminate() override;
    
    void commandBuy();
    void commandSell();
    void onBuyOk();
    void onBuyCancel();
    void onSellOk();
    void onSellCancel();
    void onNumberOk();
    void onNumberCancel();
    
private:
    Window_ShopCommand *_commandWindow;
    Window_ShopBuy *_buyWindow;
    Window_ShopSell *_sellWindow;
    Window_ShopNumber *_numberWindow;
    Window_ShopStatus *_statusWindow;
};

#endif // SCENE_SHOP_H
