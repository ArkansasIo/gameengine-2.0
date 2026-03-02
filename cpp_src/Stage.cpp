#include "Stage.h"
#include "Sprite.h"

Stage::Stage() {
}

Stage::~Stage() {
    for (auto child : children) {
        delete child;
    }
    children.clear();
}

void Stage::addChild(Sprite* child) {
    if (child) {
        children.push_back(child);
    }
}

void Stage::removeChild(Sprite* child) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == child) {
            children.erase(it);
            break;
        }
    }
}

void Stage::update() {
    updateChildren();
}

void Stage::updateChildren() {
    for (auto child : children) {
        if (child) {
            child->update();
        }
    }
}

void Stage::render() {
}
