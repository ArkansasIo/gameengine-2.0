#include "../../include/wolfman/Renderer.h"

namespace WolfManAlpha {

Renderer& Renderer::instance() {
    static Renderer renderer;
    return renderer;
}

Renderer::Renderer()
    : _width(816), _height(624), _drawCallCount(0) {
}

Renderer::~Renderer() {
}

bool Renderer::initialize(int width, int height) {
    _width = width;
    _height = height;
    return true;
}

void Renderer::beginFrame() {
    _drawCallCount = 0;
    _commandBuffer.clear();
}

void Renderer::endFrame() {
    // Process all draw commands
}

void Renderer::present() {
    // Display rendered frame
}

void Renderer::drawSprite(const QString &name, float x, float y, float scaleX,
                          float scaleY, float rotation, int color, int layer) {
    DrawCommand cmd;
    cmd.type = DrawCommand::Sprite;
    cmd.resourceName = name;
    cmd.x = x;
    cmd.y = y;
    cmd.scaleX = scaleX;
    cmd.scaleY = scaleY;
    cmd.rotation = rotation;
    cmd.color = color;
    cmd.layer = layer;
    _commandBuffer.append(cmd);
    _drawCallCount++;
}

void Renderer::drawText(const QString &text, float x, float y, int fontSize,
                        const QString &fontName, int color, int layer) {
    DrawCommand cmd;
    cmd.type = DrawCommand::Text;
    cmd.resourceName = text;
    cmd.x = x;
    cmd.y = y;
    cmd.color = color;
    cmd.layer = layer;
    _commandBuffer.append(cmd);
    _drawCallCount++;
}

void Renderer::drawRectangle(float x, float y, float width, float height,
                             int fillColor, int outlineColor, int layer) {
    DrawCommand cmd;
    cmd.type = DrawCommand::Shape;
    cmd.x = x;
    cmd.y = y;
    cmd.scaleX = width;
    cmd.scaleY = height;
    cmd.color = fillColor;
    cmd.layer = layer;
    _commandBuffer.append(cmd);
    _drawCallCount++;
}

void Renderer::drawCircle(float x, float y, float radius,
                          int fillColor, int outlineColor, int layer) {
    DrawCommand cmd;
    cmd.type = DrawCommand::Shape;
    cmd.x = x;
    cmd.y = y;
    cmd.scaleX = radius;
    cmd.color = fillColor;
    cmd.layer = layer;
    _commandBuffer.append(cmd);
    _drawCallCount++;
}

void Renderer::drawLine(float x1, float y1, float x2, float y2,
                        int color, float thickness, int layer) {
    DrawCommand cmd;
    cmd.type = DrawCommand::Line;
    cmd.x = x1;
    cmd.y = y1;
    cmd.scaleX = x2;
    cmd.scaleY = y2;
    cmd.color = color;
    cmd.layer = layer;
    _commandBuffer.append(cmd);
    _drawCallCount++;
}

void Renderer::drawPolygon(const QVector<float> &vertices, int color, int layer) {
    // Draw polygon with given vertices
}

void Renderer::setBlendMode(int mode) {
    // Set rendering blend mode
}

void Renderer::setClippingRegion(float x, float y, float width, float height) {
    // Set scissor test region
}

void Renderer::clearClippingRegion() {
    // Disable scissor test
}

void Renderer::setCameraPosition(float x, float y) {
    // Update camera view matrix
}

void Renderer::setCameraZoom(float zoom) {
    // Update camera zoom matrix
}

void Renderer::setCameraRotation(float rotation) {
    // Update camera rotation matrix
}

int Renderer::getScreenWidth() const {
    return _width;
}

int Renderer::getScreenHeight() const {
    return _height;
}

void Renderer::setScreenSize(int width, int height) {
    _width = width;
    _height = height;
}

int Renderer::getDrawCallCount() const {
    return _drawCallCount;
}

int Renderer::getVisibleObjectCount() const {
    return _commandBuffer.size();
}

void Renderer::clear(int color) {
    _commandBuffer.clear();
}

} // namespace WolfManAlpha
