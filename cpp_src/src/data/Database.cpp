#include "../../include/data/Database.h"

namespace LunaLite {
namespace Data {

Database& Database::instance() {
    static Database db;
    return db;
}

Database::Database() {
}

Database::~Database() {
    for (auto actor : _actors) {
        delete actor;
    }
    _actors.clear();
}

bool Database::loadActors(const QString &filePath) {
    // TODO: Implement JSON loading
    return true;
}

bool Database::loadItems(const QString &filePath) {
    return true;
}

bool Database::loadSkills(const QString &filePath) {
    return true;
}

bool Database::loadWeapons(const QString &filePath) {
    return true;
}

bool Database::loadArmors(const QString &filePath) {
    return true;
}

bool Database::loadEnemies(const QString &filePath) {
    return true;
}

bool Database::loadTroops(const QString &filePath) {
    return true;
}

bool Database::loadMaps(const QString &filePath) {
    return true;
}

bool Database::loadStates(const QString &filePath) {
    return true;
}

Database::ActorData* Database::getActor(ActorId id) {
    return _actors.value(id, nullptr);
}

int Database::getActorCount() const {
    return _actors.size();
}

int Database::getMaxActorId() const {
    if (_actors.isEmpty()) return 0;
    return _actors.keys().last();
}

bool Database::hasActor(ActorId id) const {
    return _actors.contains(id);
}

} // namespace Data
} // namespace LunaLite
