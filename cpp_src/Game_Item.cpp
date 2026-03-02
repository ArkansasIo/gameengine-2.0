#include "Game_Item.h"

Game_Item::Game_Item(int itemId)
    : _itemId(itemId) {
}

Game_Item::~Game_Item() {
}

void Game_Item::initialize(int itemId) {
    _itemId = itemId;
}

bool Game_Item::isNull() const {
    return _itemId == 0;
}

int Game_Item::itemId() const {
    return _itemId;
}

QString Game_Item::name() const {
    return "Item";
}

QString Game_Item::description() const {
    return QString();
}

int Game_Item::price() const {
    return 0;
}

int Game_Item::consumable() const {
    return 1;
}

int Game_Item::occasion() const {
    return 0;
}

int Game_Item::scope() const {
    return 0;
}

int Game_Item::speed() const {
    return 0;
}

int Game_Item::successRate() const {
    return 100;
}

int Game_Item::repeatCount() const {
    return 1;
}

int Game_Item::animationId() const {
    return 0;
}

QString Game_Item::damage() const {
    return QString();
}

QString Game_Item::effects() const {
    return QString();
}

bool Game_Item::isSkill() const {
    return false;
}

bool Game_Item::isItem() const {
    return true;
}

bool Game_Item::isUsableItem() const {
    return !isNull();
}

bool Game_Item::isWeapon() const {
    return false;
}

bool Game_Item::isArmor() const {
    return false;
}
