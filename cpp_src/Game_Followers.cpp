#include "Game_Followers.h"

Game_Followers::Game_Followers() {
}

Game_Followers::~Game_Followers() {
    for (Game_Character *follower : _followers) {
        delete follower;
    }
}

void Game_Followers::initialize() {
    _followers.clear();
}

void Game_Followers::refresh() {
}

void Game_Followers::update() {
    for (Game_Character *follower : _followers) {
        if (follower) {
            // follower->update();
        }
    }
}

void Game_Followers::gatherAroundLeader() {
}

void Game_Followers::awaitPartyFormation() {
}

bool Game_Followers::isMoving() const {
    return false;
}

bool Game_Followers::areGathered() const {
    return true;
}

Game_Character *Game_Followers::follower(int index) {
    if (index >= 0 && index < _followers.size()) {
        return _followers[index];
    }
    return nullptr;
}

int Game_Followers::count() const {
    return _followers.size();
}

void Game_Followers::updateMove() {
}
