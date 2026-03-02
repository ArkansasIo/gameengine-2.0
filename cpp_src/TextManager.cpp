#include "TextManager.h"

TextManager& TextManager::instance() {
    static TextManager instance;
    return instance;
}

TextManager::TextManager() {
}

TextManager::~TextManager() {
}

void TextManager::initialize() {
    _basic.clear();
    _params.clear();
}

QString TextManager::basic(int id) const {
    return _basic.value(id, "");
}

QString TextManager::params(int id) const {
    return _params.value(id, "");
}

QString TextManager::states(int id) const {
    return "";
}

QString TextManager::skill(int id) const {
    return "";
}

QString TextManager::item(int id) const {
    return "";
}

QString TextManager::weapon(int id) const {
    return "";
}

QString TextManager::armor(int id) const {
    return "";
}

QString TextManager::enemy(int id) const {
    return "";
}

QString TextManager::actor(int id) const {
    return "";
}

void TextManager::setBasic(int id, const QString &text) {
    _basic[id] = text;
}

void TextManager::setParams(int id, const QString &text) {
    _params[id] = text;
}
