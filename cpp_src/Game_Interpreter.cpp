#include "Game_Interpreter.h"

Game_Interpreter::Game_Interpreter(int depth)
    : _depth(depth), _eventId(0), _index(0), _indent(0),
      _running(false), _waiting(false), _paused(false) {
}

Game_Interpreter::~Game_Interpreter() {
}

void Game_Interpreter::initialize() {
    _index = 0;
    _indent = 0;
    _running = false;
    _waiting = false;
}

void Game_Interpreter::setup(const QList<QString> &list, int eventId) {
    _list = list;
    _eventId = eventId;
    initialize();
    _running = true;
}

bool Game_Interpreter::isRunning() const {
    return _running;
}

bool Game_Interpreter::isWaiting() const {
    return _waiting;
}

bool Game_Interpreter::isPaused() const {
    return _paused;
}

void Game_Interpreter::update() {
    if (_running) {
        executeCommand();
    }
}

void Game_Interpreter::executeCommand() {
}

int Game_Interpreter::itemExists(int paramIndex) const {
    return 0;
}

QString Game_Interpreter::currentCommand() const {
    return _index < _list.size() ? _list[_index] : QString();
}

int Game_Interpreter::currentIndent() const {
    return _indent;
}

bool Game_Interpreter::isEventRunning() const {
    return _running;
}

void Game_Interpreter::waitCount() const {
}

void Game_Interpreter::command111ShowConditions() {}
void Game_Interpreter::command112ShowLoopCount() {}
void Game_Interpreter::command113Comment() {}
void Game_Interpreter::command114PluginCommand() {}
void Game_Interpreter::command200ControlVariables() {}
void Game_Interpreter::command204ControlCharacterMovement() {}
void Game_Interpreter::command205TransferPlayer() {}
void Game_Interpreter::command206SetEventLocation() {}
void Game_Interpreter::command207Scroll() {}
void Game_Interpreter::command208SetMovementRoute() {}
void Game_Interpreter::command209Wait() {}
void Game_Interpreter::command210ShowPicture() {}
void Game_Interpreter::command211MovePicture() {}
void Game_Interpreter::command212RotatePicture() {}
void Game_Interpreter::command213TintPicture() {}
void Game_Interpreter::command214ErasePicture() {}
void Game_Interpreter::command215ShowWeather() {}
void Game_Interpreter::command216PlayBGM() {}
void Game_Interpreter::command217PlayBGS() {}
void Game_Interpreter::command218PlayME() {}
void Game_Interpreter::command219PlaySE() {}
void Game_Interpreter::command220StopBGM() {}
void Game_Interpreter::command221StopBGS() {}
void Game_Interpreter::command222StopME() {}
void Game_Interpreter::command223StopSE() {}
void Game_Interpreter::command230ShowText() {}
void Game_Interpreter::command231ShowChoices() {}
void Game_Interpreter::command232InputNumber() {}
void Game_Interpreter::command233SelectItem() {}
void Game_Interpreter::command250ShowScrollingText() {}
void Game_Interpreter::command301Battle() {}
void Game_Interpreter::command302Shop() {}
void Game_Interpreter::command303Name() {}
void Game_Interpreter::command304HideName() {}
void Game_Interpreter::command305ChangeWindowskin() {}
void Game_Interpreter::command306ChangeActorImages() {}
void Game_Interpreter::command307ChangeVehicleImage() {}
void Game_Interpreter::command308ChangeSystemSettings() {}
void Game_Interpreter::command309DisableFormationCommand() {}
void Game_Interpreter::command310PartyWindowDisable() {}
void Game_Interpreter::command311Show() {}
void Game_Interpreter::command312Erase() {}
void Game_Interpreter::command313SetEventPriority() {}
void Game_Interpreter::command314SetEventTrigger() {}
void Game_Interpreter::command315SetEventImage() {}
void Game_Interpreter::command316ChangeTransparency() {}
