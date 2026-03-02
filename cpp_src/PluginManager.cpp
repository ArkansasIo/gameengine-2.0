#include "PluginManager.h"

PluginManager& PluginManager::instance() {
    static PluginManager instance;
    return instance;
}

PluginManager::PluginManager() {
}

PluginManager::~PluginManager() {
}

void PluginManager::initialize() {
    _plugins.clear();
    _parameters.clear();
    _loadedPlugins.clear();
}

void PluginManager::loadPlugins() {
}

void PluginManager::setup(const QStringList &plugins) {
    for (const QString &plugin : plugins) {
        _loadedPlugins.append(plugin);
    }
}

void PluginManager::callCommand(const QString &command) {
}

void PluginManager::registerCommand(const QString &name, int commandCode) {
    _plugins[name] = QString::number(commandCode);
}

bool PluginManager::isPlugin(const QString &name) const {
    return _plugins.contains(name);
}

QString PluginManager::version(const QString &name) const {
    return "1.0.0";
}

void PluginManager::setParameters(const QString &name, const QMap<QString, QString> &params) {
    _parameters[name] = params;
}

QMap<QString, QString> PluginManager::parameters(const QString &name) const {
    return _parameters.value(name, QMap<QString, QString>());
}
