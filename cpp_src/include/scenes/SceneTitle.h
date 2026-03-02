#ifndef SCENE_TITLE_H
#define SCENE_TITLE_H

#include "SceneBase.h"
#include "../ui/WindowCommand.h"

namespace LunaLite {
namespace Scenes {

class SceneTitle : public SceneBase {
public:
    SceneTitle();
    virtual ~SceneTitle();
    
    void start() override;
    void update() override;
    void render() override;
    void stop() override;
    
private:
    UI::WindowCommand* _commandWindow;
};

} // namespace Scenes
} // namespace LunaLite

#endif // SCENE_TITLE_H
