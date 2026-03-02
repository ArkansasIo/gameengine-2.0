#include "../../include/wolfman/Scripting.h"

namespace WolfManAlpha {

ScriptContext::ScriptContext() {
}

ScriptContext::~ScriptContext() {
    _variables.clear();
    _functions.clear();
}

void ScriptContext::setVariable(const QString &name, const QVariant &value) {
    _variables[name] = value;
}

QVariant ScriptContext::getVariable(const QString &name) {
    return _variables.value(name, QVariant());
}

bool ScriptContext::hasVariable(const QString &name) const {
    return _variables.contains(name);
}

void ScriptContext::removeVariable(const QString &name) {
    _variables.remove(name);
}

void ScriptContext::registerFunction(const QString &name, ScriptFunction func) {
    _functions[name] = func;
}

QVariant ScriptContext::callFunction(const QString &name, const QVector<QVariant> &args) {
    if (_functions.contains(name)) {
        return _functions[name](args);
    }
    return QVariant();
}

bool ScriptContext::hasFunction(const QString &name) const {
    return _functions.contains(name);
}

void ScriptContext::wait(float duration) {
}

void ScriptContext::execute(const QString &script) {
}

EventScript::EventScript(const QString &name)
    : _name(name), _running(false), _timeElapsed(0) {
}

EventScript::~EventScript() {
}

QString EventScript::getName() const {
    return _name;
}

void EventScript::setScript(const QString &script) {
    _script = script;
}

QString EventScript::getScript() const {
    return _script;
}

void EventScript::execute(ScriptContext* context) {
    if (context && !_script.isEmpty()) {
        _running = true;
        context->execute(_script);
        _running = false;
    }
}

bool EventScript::isRunning() const {
    return _running;
}

void EventScript::stop() {
    _running = false;
}

void EventScript::onEventStart(const QString &eventName, std::function<void()> callback) {
}

void EventScript::onEventEnd(const QString &eventName, std::function<void()> callback) {
}

ScriptingSystem& ScriptingSystem::instance() {
    static ScriptingSystem system;
    return system;
}

ScriptingSystem::ScriptingSystem() : _debugMode(false) {
}

ScriptingSystem::~ScriptingSystem() {
    for (auto context : _contexts) {
        delete context;
    }
    for (auto script : _eventScripts) {
        delete script;
    }
    _contexts.clear();
    _eventScripts.clear();
}

ScriptContext* ScriptingSystem::createContext(const QString &name) {
    auto context = new ScriptContext();
    _contexts[name.isEmpty() ? QString::number(_contexts.size()) : name] = context;
    return context;
}

ScriptContext* ScriptingSystem::getContext(const QString &name) {
    return _contexts.value(name, nullptr);
}

void ScriptingSystem::destroyContext(const QString &name) {
    if (_contexts.contains(name)) {
        delete _contexts[name];
        _contexts.remove(name);
    }
}

EventScript* ScriptingSystem::createEventScript(const QString &name) {
    auto script = new EventScript(name);
    _eventScripts[name] = script;
    return script;
}

EventScript* ScriptingSystem::getEventScript(const QString &name) {
    return _eventScripts.value(name, nullptr);
}

void ScriptingSystem::executeEventScript(const QString &scriptName) {
    if (_eventScripts.contains(scriptName)) {
        auto context = createContext("temp_" + scriptName);
        _eventScripts[scriptName]->execute(context);
        destroyContext("temp_" + scriptName);
    }
}

void ScriptingSystem::registerGlobalFunction(const QString &name, ScriptContext::ScriptFunction func) {
    for (auto context : _contexts) {
        if (context) {
            context->registerFunction(name, func);
        }
    }
}

void ScriptingSystem::update(float deltaTime) {
    // Update all running scripts
}

void ScriptingSystem::printDebug(const QString &message) {
    if (_debugMode) {
        // Log message
    }
}

void ScriptingSystem::setDebugMode(bool enabled) {
    _debugMode = enabled;
}

} // namespace WolfManAlpha
