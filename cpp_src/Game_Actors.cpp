#include "Game_Actors.h"
#include "Game_Actor.h"

Game_Actors::Game_Actors() {
}

Game_Actors::~Game_Actors() {
    for (Game_Actor *actor : _members) {
        delete actor;
    }
}

void Game_Actors::initialize() {
    _members.clear();
}

Game_Actor *Game_Actors::actor(int actorId) {
    for (Game_Actor *actor : _members) {
        if (actor && actor->actorId() == actorId) {
            return actor;
        }
    }
    return nullptr;
}

void Game_Actors::addActor(int actorId) {
    Game_Actor *actor = new Game_Actor(actorId);
    _members.append(actor);
}

void Game_Actors::removeActor(int actorId) {
    for (int i = 0; i < _members.size(); ++i) {
        if (_members[i]->actorId() == actorId) {
            delete _members[i];
            _members.removeAt(i);
            break;
        }
    }
}

Game_Actor *Game_Actors::leader() const {
    return _members.isEmpty() ? nullptr : _members[0];
}

int Game_Actors::size() const {
    return _members.size();
}

bool Game_Actors::isEmpty() const {
    return _members.isEmpty();
}

QVector<Game_Actor*> Game_Actors::allMembers() const {
    return _members;
}

QVector<Game_Actor*> Game_Actors::aliveMembers() const {
    QVector<Game_Actor*> alive;
    for (Game_Actor *actor : _members) {
        if (actor && actor->isAlive()) {
            alive.append(actor);
        }
    }
    return alive;
}

QVector<Game_Actor*> Game_Actors::deadMembers() const {
    QVector<Game_Actor*> dead;
    for (Game_Actor *actor : _members) {
        if (actor && actor->isDead()) {
            dead.append(actor);
        }
    }
    return dead;
}

QVector<Game_Actor*> Game_Actors::movableMembers() const {
    QVector<Game_Actor*> movable;
    for (Game_Actor *actor : _members) {
        if (actor && actor->isAlive() && !actor->isStateAffected(1)) {
            movable.append(actor);
        }
    }
    return movable;
}
