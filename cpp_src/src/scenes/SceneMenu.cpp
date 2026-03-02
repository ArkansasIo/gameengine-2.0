#include "../../include/scenes/SceneMenu.h"

namespace LunaLite {
namespace Scenes {

SceneMenu::SceneMenu()
    : SceneBase("Menu"), _mainMenuWindow(nullptr),
      _statusWindow(nullptr), _goldWindow(nullptr) {
}

SceneMenu::~SceneMenu() {
    if (_mainMenuWindow) delete _mainMenuWindow;
    if (_statusWindow) delete _statusWindow;
    if (_goldWindow) delete _goldWindow;
}

void SceneMenu::start() {
    SceneBase::start();
    
    _mainMenuWindow = new UI::WindowCommand(0, 0, 300);
    _mainMenuWindow->addCommand("Items");
    _mainMenuWindow->addCommand("Skills");
    _mainMenuWindow->addCommand("Equipment");
    _mainMenuWindow->addCommand("Status");
    _mainMenuWindow->addCommand("Save");
    _mainMenuWindow->addCommand("Load");
    _mainMenuWindow->addCommand("Exit Game");
    
    _statusWindow = new UI::WindowBase(300, 0, 500, 400);
    _goldWindow = new UI::WindowBase(300, 400, 500, 200);
}

void SceneMenu::update() {
    SceneBase::update();
    
    if (_mainMenuWindow) {
        _mainMenuWindow->update();
    }
    if (_statusWindow) {
        _statusWindow->update();
    }
    if (_goldWindow) {
        _goldWindow->update();
    }
}

void SceneMenu::render() {
    // Render all windows
}

void SceneMenu::stop() {
    SceneBase::stop();
    if (_mainMenuWindow) {
        delete _mainMenuWindow;
        _mainMenuWindow = nullptr;
    }
    if (_statusWindow) {
        delete _statusWindow;
        _statusWindow = nullptr;
    }
    if (_goldWindow) {
        delete _goldWindow;
        _goldWindow = nullptr;
    }
}

} // namespace Scenes
} // namespace LunaLite
