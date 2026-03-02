#include "Game_Armor.h"

Game_Armor::Game_Armor(int armorId) : _armorId(armorId) {
}

Game_Armor::~Game_Armor() {
}

int Game_Armor::armorId() const {
    return _armorId;
}

int Game_Armor::armorType() const {
    return 0;
}

int Game_Armor::price() const {
    return 0;
}

bool Game_Armor::canEquip() const {
    return true;
}

QString Game_Armor::name() const {
    return "";
}

QString Game_Armor::description() const {
    return "";
}

QString Game_Armor::iconIndex() const {
    return "";
}
