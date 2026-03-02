#include "../../include/scenes/SceneTitle.h"
#include "../../include/managers/GameManager.h"

namespace LunaLite {
namespace Scenes {

SceneTitle::SceneTitle()
    : SceneBase("Title"), _commandWindow(nullptr) {
}

SceneTitle::~SceneTitle() {
    if (_commandWindow) {
        delete _commandWindow;
    }
}

void SceneTitle::start() {
    SceneBase::start();
    
    _commandWindow = new UI::WindowCommand(0, 300, 400);
    _commandWindow->addCommand("New Game");
    _commandWindow->addCommand("Continue");
    _commandWindow->addCommand("Settings");
    _commandWindow->addCommand("Exit");
}

void SceneTitle::update() {
    SceneBase::update();
    
    if (_commandWindow) {
        _commandWindow->update();
    }
}

void SceneTitle::render() {
    if (_commandWindow) {
        _commandWindow->setVisible(true);
    }
}

void SceneTitle::stop() {
    SceneBase::stop();
    if (_commandWindow) {
        delete _commandWindow;
        _commandWindow = nullptr;
    }
}

} // namespace Scenes
} // namespace LunaLite
