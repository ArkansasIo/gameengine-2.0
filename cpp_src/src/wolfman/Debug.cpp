#include "../../include/wolfman/Debug.h"

namespace WolfManAlpha {

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}

Logger::Logger() : _consoleOutput(true) {
}

Logger::~Logger() {
}

void Logger::log(LogLevel level, const QString &message) {
    QString levelStr;
    switch (level) {
        case LogLevel::Debug: levelStr = "[DEBUG]"; break;
        case LogLevel::Info: levelStr = "[INFO]"; break;
        case LogLevel::Warning: levelStr = "[WARN]"; break;
        case LogLevel::Error: levelStr = "[ERROR]"; break;
        case LogLevel::Critical: levelStr = "[CRITICAL]"; break;
    }
    
    QString logMessage = levelStr + " " + message;
    _history.append(logMessage);
    
    if (_consoleOutput) {
        // Output to console
    }
}

void Logger::debug(const QString &message) {
    log(LogLevel::Debug, message);
}

void Logger::info(const QString &message) {
    log(LogLevel::Info, message);
}

void Logger::warning(const QString &message) {
    log(LogLevel::Warning, message);
}

void Logger::error(const QString &message) {
    log(LogLevel::Error, message);
}

void Logger::critical(const QString &message) {
    log(LogLevel::Critical, message);
}

void Logger::onLog(std::function<void(LogLevel, const QString&)> callback) {
}

void Logger::setOutputFile(const QString &filePath) {
    _outputFile = filePath;
}

void Logger::setConsoleOutput(bool enabled) {
    _consoleOutput = enabled;
}

QVector<QString> Logger::getLogHistory(int maxLines) const {
    if (_history.size() <= maxLines) {
        return _history;
    }
    return _history.mid(_history.size() - maxLines);
}

void Logger::clearHistory() {
    _history.clear();
}

DebugOverlay& DebugOverlay::instance() {
    static DebugOverlay overlay;
    return overlay;
}

DebugOverlay::DebugOverlay()
    : _enabled(false), _showFps(true), _showMemory(false),
      _showEntityCount(false), _showDebugInfo(false) {
}

DebugOverlay::~DebugOverlay() {
}

bool DebugOverlay::isEnabled() const {
    return _enabled;
}

void DebugOverlay::setEnabled(bool enabled) {
    _enabled = enabled;
}

void DebugOverlay::showFps(bool show) {
    _showFps = show;
}

void DebugOverlay::showMemory(bool show) {
    _showMemory = show;
}

void DebugOverlay::showEntityCount(bool show) {
    _showEntityCount = show;
}

void DebugOverlay::showDebugInfo(bool show) {
    _showDebugInfo = show;
}

void DebugOverlay::drawLine(float x1, float y1, float x2, float y2, int color) {
    if (_enabled) {
        // Draw debug line
    }
}

void DebugOverlay::drawCircle(float x, float y, float radius, int color) {
    if (_enabled) {
        // Draw debug circle
    }
}

void DebugOverlay::drawText(float x, float y, const QString &text, int color) {
    if (_enabled) {
        // Draw debug text
    }
}

void DebugOverlay::update() {
}

void DebugOverlay::render() {
}

Profiler& Profiler::instance() {
    static Profiler profiler;
    return profiler;
}

Profiler::Profiler() : _enabled(false) {
}

Profiler::~Profiler() {
}

void Profiler::beginProfile(const QString &label) {
    if (_enabled) {
        // Start profiling
    }
}

void Profiler::endProfile(const QString &label) {
    if (_enabled) {
        // End profiling
    }
}

float Profiler::getProfileTime(const QString &label) const {
    return _profiles.value(label, 0.0f);
}

QVector<QString> Profiler::getProfileSummary() const {
    QVector<QString> summary;
    for (auto it = _profiles.constBegin(); it != _profiles.constEnd(); ++it) {
        summary.append(it.key() + ": " + QString::number(it.value()) + "ms");
    }
    return summary;
}

void Profiler::reset() {
    _profiles.clear();
}

void Profiler::setEnabled(bool enabled) {
    _enabled = enabled;
}

} // namespace WolfManAlpha
