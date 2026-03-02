#include "StorageManager.h"
#include <QFile>
#include <QDir>

StorageManager& StorageManager::instance() {
    static StorageManager instance;
    return instance;
}

StorageManager::StorageManager() {
}

StorageManager::~StorageManager() {
}

void StorageManager::initialize() {
}

bool StorageManager::saveToLocalFile(const QString &filename, const QByteArray &data) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(data);
        file.close();
        return true;
    }
    return false;
}

QByteArray StorageManager::loadFromLocalFile(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();
        return data;
    }
    return QByteArray();
}

bool StorageManager::fileExists(const QString &filename) const {
    return QFile::exists(filename);
}

void StorageManager::deleteFile(const QString &filename) {
    QFile::remove(filename);
}

bool StorageManager::saveToCloud(const QString &key, const QByteArray &data) {
    return false;
}

QByteArray StorageManager::loadFromCloud(const QString &key) {
    return QByteArray();
}
