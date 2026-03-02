#include "../../include/core/GameObject.h"

namespace LunaLite {
namespace Core {

GameObject::GameObject(int id)
    : _id(id), _iconIndex(0) {
}

GameObject::~GameObject() {
}

int GameObject::getId() const {
    return _id;
}

void GameObject::setId(int id) {
    _id = id;
}

QString GameObject::getName() const {
    return _name;
}

void GameObject::setName(const QString &name) {
    _name = name;
}

QString GameObject::getDescription() const {
    return _description;
}

void GameObject::setDescription(const QString &desc) {
    _description = desc;
}

int GameObject::getIconIndex() const {
    return _iconIndex;
}

void GameObject::setIconIndex(int index) {
    _iconIndex = index;
}

} // namespace Core
} // namespace LunaLite
