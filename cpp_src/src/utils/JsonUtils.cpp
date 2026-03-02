#include "../../include/utils/JsonUtils.h"
#include <QFile>
#include <QDir>

namespace LunaLite {
namespace Serialization {

QJsonDocument JsonUtils::loadJson(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        return QJsonDocument();
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    return QJsonDocument::fromJson(data);
}

bool JsonUtils::saveJson(const QString &filePath, const QJsonDocument &doc) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    
    file.write(doc.toJson());
    file.close();
    return true;
}

QJsonObject JsonUtils::parseJson(const QString &jsonString) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    if (doc.isObject()) {
        return doc.object();
    }
    return QJsonObject();
}

QString JsonUtils::jsonToString(const QJsonObject &obj) {
    QJsonDocument doc(obj);
    return QString::fromUtf8(doc.toJson(QJsonDocument::Compact));
}

QString JsonUtils::getString(const QJsonObject &obj, const QString &key, const QString &defaultValue) {
    return obj.value(key).toString(defaultValue);
}

int JsonUtils::getInt(const QJsonObject &obj, const QString &key, int defaultValue) {
    return obj.value(key).toInt(defaultValue);
}

double JsonUtils::getDouble(const QJsonObject &obj, const QString &key, double defaultValue) {
    return obj.value(key).toDouble(defaultValue);
}

bool JsonUtils::getBool(const QJsonObject &obj, const QString &key, bool defaultValue) {
    return obj.value(key).toBool(defaultValue);
}

QJsonArray JsonUtils::getArray(const QJsonObject &obj, const QString &key) {
    return obj.value(key).toArray();
}

QJsonObject JsonUtils::getObject(const QJsonObject &obj, const QString &key) {
    return obj.value(key).toObject();
}

bool JsonUtils::hasKey(const QJsonObject &obj, const QString &key) {
    return obj.contains(key);
}

bool JsonUtils::isValidJson(const QString &jsonString) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    return !doc.isNull();
}

} // namespace Serialization
} // namespace LunaLite
