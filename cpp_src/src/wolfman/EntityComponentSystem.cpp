#include "../../include/wolfman/EntityComponentSystem.h"

namespace WolfManAlpha {

int Entity::_nextId = 0;

Entity::Entity(const QString &name)
    : _id(++_nextId), _name(name), _active(true) {
}

Entity::~Entity() {
    _components.clear();
    _children.clear();
}

int Entity::getId() const {
    return _id;
}

QString Entity::getName() const {
    return _name;
}

void Entity::setName(const QString &name) {
    _name = name;
}

void Entity::addChild(std::shared_ptr<Entity> child) {
    if (child) {
        _children.append(child);
    }
}

void Entity::removeChild(std::shared_ptr<Entity> child) {
    _children.removeAll(child);
}

int Entity::getChildCount() const {
    return _children.size();
}

std::shared_ptr<Entity> Entity::getChild(int index) {
    if (index >= 0 && index < _children.size()) {
        return _children[index];
    }
    return nullptr;
}

void Entity::initialize() {
    for (auto& component : _components) {
        if (component) {
            component->initialize();
        }
    }
    for (auto& child : _children) {
        if (child) {
            child->initialize();
        }
    }
}

void Entity::update(float deltaTime) {
    if (!_active) return;
    
    for (auto& component : _components) {
        if (component && component->isEnabled()) {
            component->update(deltaTime);
        }
    }
    for (auto& child : _children) {
        if (child) {
            child->update(deltaTime);
        }
    }
}

bool Entity::isActive() const {
    return _active;
}

void Entity::setActive(bool active) {
    _active = active;
}

EntityManager& EntityManager::instance() {
    static EntityManager manager;
    return manager;
}

EntityManager::EntityManager() : _nextEntityId(0) {
}

EntityManager::~EntityManager() {
    destroyAllEntities();
}

std::shared_ptr<Entity> EntityManager::createEntity(const QString &name) {
    auto entity = std::make_shared<Entity>(name);
    _entities[entity->getId()] = entity;
    return entity;
}

void EntityManager::destroyEntity(int entityId) {
    _entities.remove(entityId);
    _entityLayers.remove(entityId);
}

void EntityManager::destroyAllEntities() {
    _entities.clear();
    _entityLayers.clear();
}

std::shared_ptr<Entity> EntityManager::getEntity(int id) {
    return _entities.value(id, nullptr);
}

std::shared_ptr<Entity> EntityManager::findEntityByName(const QString &name) {
    for (auto& entity : _entities) {
        if (entity && entity->getName() == name) {
            return entity;
        }
    }
    return nullptr;
}

QVector<std::shared_ptr<Entity>> EntityManager::getAllEntities() {
    return _entities.values().toVector();
}

int EntityManager::getEntityCount() const {
    return _entities.size();
}

void EntityManager::updateAll(float deltaTime) {
    for (auto& entity : _entities) {
        if (entity) {
            entity->update(deltaTime);
        }
    }
}

void EntityManager::renderAll() {
    for (auto& entity : _entities) {
        // Render entity
    }
}

void EntityManager::setEntityLayer(int entityId, int layer) {
    _entityLayers[entityId] = layer;
}

int EntityManager::getEntityLayer(int entityId) const {
    return _entityLayers.value(entityId, 0);
}

} // namespace WolfManAlpha
