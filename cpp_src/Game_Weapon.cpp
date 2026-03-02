#include "Game_Weapon.h"

Game_Weapon::Game_Weapon(int weaponId) : _weaponId(weaponId) {
}

Game_Weapon::~Game_Weapon() {
}

int Game_Weapon::weaponId() const {
    return _weaponId;
}

int Game_Weapon::weaponType() const {
    return 0;
}

int Game_Weapon::price() const {
    return 0;
}

bool Game_Weapon::canEquip() const {
    return true;
}

QString Game_Weapon::name() const {
    return "";
}

QString Game_Weapon::description() const {
    return "";
}

QString Game_Weapon::iconIndex() const {
    return "";
}
