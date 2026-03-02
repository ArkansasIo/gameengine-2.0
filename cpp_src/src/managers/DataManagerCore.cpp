#include "../../include/managers/DataManagerCore.h"

namespace LunaLite {
namespace Managers {

DataManager& DataManager::instance() {
    static DataManager manager;
    return manager;
}

DataManager::DataManager()
    : _loaded(false), _maxActorId(0), _maxItemId(0), _maxSkillId(0),
      _maxWeaponId(0), _maxArmorId(0), _maxEnemyId(0) {
}

DataManager::~DataManager() {
    clear();
}

bool DataManager::loadAllData(const QString &dataPath) {
    bool success = true;
    success &= loadActorsData(dataPath + "/Actors.json");
    success &= loadItemsData(dataPath + "/Items.json");
    success &= loadSkillsData(dataPath + "/Skills.json");
    success &= loadWeaponsData(dataPath + "/Weapons.json");
    success &= loadArmorsData(dataPath + "/Armors.json");
    success &= loadEnemiesData(dataPath + "/Enemies.json");
    success &= loadTroopsData(dataPath + "/Troops.json");
    success &= loadMapsData(dataPath + "/Maps.json");
    success &= loadStatesData(dataPath + "/States.json");
    
    _loaded = success;
    return success;
}

bool DataManager::loadActorsData(const QString &filePath) {
    // TODO: Load from JSON
    _maxActorId = 1;
    return true;
}

bool DataManager::loadItemsData(const QString &filePath) {
    // TODO: Load from JSON
    _maxItemId = 1;
    return true;
}

bool DataManager::loadSkillsData(const QString &filePath) {
    // TODO: Load from JSON
    _maxSkillId = 1;
    return true;
}

bool DataManager::loadWeaponsData(const QString &filePath) {
    // TODO: Load from JSON
    _maxWeaponId = 1;
    return true;
}

bool DataManager::loadArmorsData(const QString &filePath) {
    // TODO: Load from JSON
    _maxArmorId = 1;
    return true;
}

bool DataManager::loadEnemiesData(const QString &filePath) {
    // TODO: Load from JSON
    _maxEnemyId = 1;
    return true;
}

bool DataManager::loadTroopsData(const QString &filePath) {
    // TODO: Load from JSON
    return true;
}

bool DataManager::loadMapsData(const QString &filePath) {
    // TODO: Load from JSON
    return true;
}

bool DataManager::loadStatesData(const QString &filePath) {
    // TODO: Load from JSON
    return true;
}

int DataManager::getMaxActorId() const {
    return _maxActorId;
}

int DataManager::getMaxItemId() const {
    return _maxItemId;
}

int DataManager::getMaxSkillId() const {
    return _maxSkillId;
}

int DataManager::getMaxWeaponId() const {
    return _maxWeaponId;
}

int DataManager::getMaxArmorId() const {
    return _maxArmorId;
}

int DataManager::getMaxEnemyId() const {
    return _maxEnemyId;
}

bool DataManager::hasActor(int id) const {
    return _actors.contains(id);
}

bool DataManager::hasItem(int id) const {
    return _items.contains(id);
}

bool DataManager::hasSkill(int id) const {
    return _skills.contains(id);
}

bool DataManager::hasWeapon(int id) const {
    return _weapons.contains(id);
}

bool DataManager::hasArmor(int id) const {
    return _armors.contains(id);
}

bool DataManager::hasEnemy(int id) const {
    return _enemies.contains(id);
}

bool DataManager::isLoaded() const {
    return _loaded;
}

void DataManager::clear() {
    for (auto actor : _actors) delete actor;
    for (auto item : _items) delete item;
    for (auto skill : _skills) delete skill;
    for (auto weapon : _weapons) delete weapon;
    for (auto armor : _armors) delete armor;
    for (auto enemy : _enemies) delete enemy;
    
    _actors.clear();
    _items.clear();
    _skills.clear();
    _weapons.clear();
    _armors.clear();
    _enemies.clear();
    
    _loaded = false;
}

bool DataManager::saveGame(const QString &filePath) {
    // TODO: Save game state to JSON
    return true;
}

bool DataManager::loadGame(const QString &filePath) {
    // TODO: Load game state from JSON
    return true;
}

} // namespace Managers
} // namespace LunaLite
