#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include "SceneBase.h"
#include "../ui/WindowCommand.h"
#include "../ui/WindowBase.h"

namespace LunaLite {
namespace Scenes {

class SceneMenu : public SceneBase {
public:
    SceneMenu();
    virtual ~SceneMenu();
    
    void start() override;
    void update() override;
    void render() override;
    void stop() override;
    
private:
    UI::WindowCommand* _mainMenuWindow;
    UI::WindowBase* _statusWindow;
    UI::WindowBase* _goldWindow;
};

} // namespace Scenes
} // namespace LunaLite

#endif // SCENE_MENU_H
