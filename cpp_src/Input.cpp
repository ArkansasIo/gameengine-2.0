#include "Input.h"
#include <chrono>

int Input::keyRepeatWait = 24;
int Input::keyRepeatInterval = 6;
std::map<int, std::string> Input::keyMapper;
std::map<int, std::string> Input::gamepadMapper;
int Input::dir4 = 0;
int Input::dir8 = 0;
long long Input::date = 0;

void Input::initialize() {
    keyMapper.clear();
    gamepadMapper.clear();
    dir4 = 0;
    dir8 = 0;
    date = 0;
}

void Input::clear() {
    dir4 = 0;
    dir8 = 0;
}

void Input::update() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    date = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

bool Input::isPressed(const std::string& keyName) {
    return false;
}

bool Input::isTriggered(const std::string& keyName) {
    return false;
}

bool Input::isRepeated(const std::string& keyName) {
    return false;
}

bool Input::isLongPressed(const std::string& keyName) {
    return false;
}
