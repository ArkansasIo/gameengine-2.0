#include "../../include/core/EventSystem.h"

namespace LunaLite {
namespace Events {

Event::Event(const QString &name) : _name(name) {
}

QString Event::getName() const {
    return _name;
}

void Event::addListener(EventCallback callback) {
    _listeners.append(callback);
}

void Event::dispatch(const QMap<QString, QVariant> &data) {
    for (const auto &callback : _listeners) {
        callback(_name, data);
    }
}

EventManager& EventManager::instance() {
    static EventManager manager;
    return manager;
}

EventManager::EventManager() {
}

EventManager::~EventManager() {
    clear();
}

void EventManager::registerEvent(const QString &eventName) {
    if (!_events.contains(eventName)) {
        _events[eventName] = new Event(eventName);
    }
}

void EventManager::subscribe(const QString &eventName, EventCallback callback) {
    registerEvent(eventName);
    _events[eventName]->addListener(callback);
}

void EventManager::dispatch(const QString &eventName, const QMap<QString, QVariant> &data) {
    if (_events.contains(eventName)) {
        _events[eventName]->dispatch(data);
    }
}

void EventManager::clear() {
    for (auto event : _events) {
        delete event;
    }
    _events.clear();
}

} // namespace Events
} // namespace LunaLite
