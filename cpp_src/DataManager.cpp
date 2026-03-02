#include "DataManager.h"

const QString DataManager::DATABASE_PATH = "data/";

DataManager& DataManager::instance() {
    static DataManager instance;
    return instance;
}

DataManager::DataManager()
    : _actorsLoaded(false), _itemsLoaded(false), _systemLoaded(false) {
}

DataManager::~DataManager() {
}

void DataManager::initialize() {
}

void DataManager::loadDatabase() {
    loadActors();
    loadClasses();
    loadSkills();
    loadItems();
    loadWeapons();
    loadArmors();
    loadEnemies();
    loadTroops();
    loadStates();
    loadAnimations();
    loadTilesets();
    loadSystem();
}

void DataManager::loadActors() {
    _actorsLoaded = true;
}

void DataManager::loadClasses() {
}

void DataManager::loadSkills() {
}

void DataManager::loadItems() {
    _itemsLoaded = true;
}

void DataManager::loadWeapons() {
}

void DataManager::loadArmors() {
}

void DataManager::loadEnemies() {
}

void DataManager::loadTroops() {
}

void DataManager::loadStates() {
}

void DataManager::loadAnimations() {
}

void DataManager::loadTilesets() {
}

void DataManager::loadSystem() {
    _systemLoaded = true;
}

void DataManager::loadMap(int mapId) {
    loadMapData(mapId);
}

void DataManager::loadMapData(int mapId) {
}

void DataManager::setupNewGame() {
    loadDatabase();
}

void DataManager::setupBattleTest() {
    loadDatabase();
}

void DataManager::importDatabase() {
}

void DataManager::extractMetadata(const QJsonObject &obj) {
}

bool DataManager::isActorsLoaded() const {
    return _actorsLoaded;
}

bool DataManager::isItemsLoaded() const {
    return _itemsLoaded;
}

bool DataManager::isSystemLoaded() const {
    return _systemLoaded;
}
