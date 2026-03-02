#include "../../include/core/GameParty.h"
#include "../../include/utils/MathUtils.h"

namespace LunaLite {
namespace Core {

GameParty& GameParty::instance() {
    static GameParty party;
    return party;
}

GameParty::GameParty() : GameObject(0), _gold(0) {
    initialize();
}

GameParty::~GameParty() {
    clearActors();
}

void GameParty::addActor(int actorId) {
    auto actor = new GameActorFull(actorId);
    if (!_actors.contains(actor)) {
        _actors.append(actor);
    }
}

void GameParty::removeActor(int actorId) {
    for (int i = 0; i < _actors.size(); ++i) {
        if (_actors[i]->getId() == actorId) {
            delete _actors[i];
            _actors.remove(i);
            break;
        }
    }
}

void GameParty::clearActors() {
    for (auto actor : _actors) {
        delete actor;
    }
    _actors.clear();
}

int GameParty::getActorCount() const {
    return _actors.size();
}

GameActorFull* GameParty::getActor(int index) {
    if (index >= 0 && index < _actors.size()) {
        return _actors[index];
    }
    return nullptr;
}

GameActorFull* GameParty::getActorById(int actorId) {
    for (auto actor : _actors) {
        if (actor->getId() == actorId) {
            return actor;
        }
    }
    return nullptr;
}

QVector<GameActorFull*> GameParty::getActors() const {
    return _actors;
}

GameActorFull* GameParty::getFrontMember() const {
    if (!_actors.isEmpty()) {
        return _actors.first();
    }
    return nullptr;
}

GameActorFull* GameParty::getRandomMember() const {
    if (_actors.isEmpty()) return nullptr;
    int index = Math::Utils::randomInt(0, _actors.size() - 1);
    return _actors[index];
}

int GameParty::getTotalHp() const {
    int total = 0;
    for (auto actor : _actors) {
        total += actor->getHp();
    }
    return total;
}

int GameParty::getTotalMp() const {
    int total = 0;
    for (auto actor : _actors) {
        total += actor->getMp();
    }
    return total;
}

int GameParty::getPartyLevel() const {
    if (_actors.isEmpty()) return 1;
    int maxLevel = 0;
    for (auto actor : _actors) {
        if (actor->getLevel() > maxLevel) {
            maxLevel = actor->getLevel();
        }
    }
    return maxLevel;
}

int GameParty::getAverageLevel() const {
    if (_actors.isEmpty()) return 1;
    int total = 0;
    for (auto actor : _actors) {
        total += actor->getLevel();
    }
    return total / _actors.size();
}

int GameParty::getGold() const {
    return _gold;
}

void GameParty::setGold(int gold) {
    _gold = Math::Utils::clamp(gold, 0, 999999999);
}

void GameParty::gainGold(int amount) {
    setGold(_gold + amount);
}

void GameParty::loseGold(int amount) {
    setGold(_gold - amount);
}

int GameParty::getItemCount(ItemId itemId) const {
    return _items.value(itemId, 0);
}

void GameParty::gainItem(ItemId itemId, int amount) {
    _items[itemId] = Math::Utils::clamp(_items[itemId] + amount, 0, 999);
}

void GameParty::loseItem(ItemId itemId, int amount) {
    _items[itemId] = Math::Utils::clamp(_items[itemId] - amount, 0, 999);
}

bool GameParty::isSkillLearned(SkillId skillId) const {
    for (auto actor : _actors) {
        if (actor->hasSkill(skillId)) {
            return true;
        }
    }
    return false;
}

bool GameParty::isAllDead() const {
    if (_actors.isEmpty()) return false;
    for (auto actor : _actors) {
        if (actor->isAlive()) {
            return false;
        }
    }
    return true;
}

bool GameParty::isMoving() const {
    for (auto actor : _actors) {
        // Placeholder - would check character moving state
    }
    return false;
}

void GameParty::initialize() {
    clearActors();
    _gold = 0;
    _items.clear();
}

void GameParty::update() {
    for (auto actor : _actors) {
        actor->update();
    }
}

} // namespace Core
} // namespace LunaLite
