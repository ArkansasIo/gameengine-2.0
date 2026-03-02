#include "Window_Base.h"

Window_Base::Window_Base(const QRect &rect)
    : _rect(rect), _visible(true), _active(false), _padding(12) {
}

Window_Base::~Window_Base() {
}

void Window_Base::initialize() {
    createContents();
}

void Window_Base::update() {
}

void Window_Base::move(int x, int y, int width, int height) {
    _rect.setRect(x, y, width, height);
}

int Window_Base::x() const {
    return _rect.x();
}

int Window_Base::y() const {
    return _rect.y();
}

int Window_Base::width() const {
    return _rect.width();
}

int Window_Base::height() const {
    return _rect.height();
}

void Window_Base::show() {
    _visible = true;
}

void Window_Base::hide() {
    _visible = false;
}

void Window_Base::activate() {
    _active = true;
}

void Window_Base::deactivate() {
    _active = false;
}

bool Window_Base::active() const {
    return _active;
}

bool Window_Base::visible() const {
    return _visible;
}

void Window_Base::setBackgroundType(int type) {
}

void Window_Base::setWindowskin(const QString &filename) {
    _windowskin = filename;
}

void Window_Base::drawText(int x, int y, int width, int height, const QString &text) {
}

void Window_Base::drawActorName(int actorId, int x, int y) {
}

void Window_Base::drawActorClass(int actorId, int x, int y) {
}

void Window_Base::drawActorHp(int actorId, int x, int y, int width) {
}

void Window_Base::drawActorMp(int actorId, int x, int y, int width) {
}

void Window_Base::drawActorTp(int actorId, int x, int y, int width) {
}

void Window_Base::drawActorSimpleStatus(int actorId, int x, int y) {
}

void Window_Base::drawItemName(int itemId, int x, int y, int width) {
}

void Window_Base::drawCurrentAndMax(int current, int max, int x, int y, int width, const QString &color1, const QString &color2) {
}

void Window_Base::drawGauge(int x, int y, int width, double rate, const QString &color1, const QString &color2) {
}

void Window_Base::drawIcon(int iconIndex, int x, int y) {
}

void Window_Base::drawFace(const QString &faceName, int faceIndex, int x, int y, int width, int height) {
}

int Window_Base::textWidth(const QString &text) const {
    return text.length() * 6;
}

int Window_Base::lineHeight() const {
    return 36;
}

int Window_Base::standardPadding() const {
    return _padding;
}

int Window_Base::fittingHeight(int numLines) const {
    return _padding * 2 + lineHeight() * numLines;
}

void Window_Base::createContents() {
}

void Window_Base::contents() const {
}
