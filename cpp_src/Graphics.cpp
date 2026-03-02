#include "Graphics.h"
#include <iostream>

int Graphics::frameCount = 0;
int Graphics::width = 816;
int Graphics::height = 624;
int Graphics::boxWidth = 816;
int Graphics::boxHeight = 624;
double Graphics::scale = 1.0;

void Graphics::initialize(int w, int h, const std::string& type) {
    width = w;
    height = h;
    boxWidth = w;
    boxHeight = h;
    frameCount = 0;
}

void Graphics::tickStart() {
}

void Graphics::tickEnd() {
    frameCount++;
}

void Graphics::render() {
}

bool Graphics::isWebGL() {
    return false;
}

bool Graphics::hasWebGL() {
    return false;
}

bool Graphics::canUseDifferenceBlend() {
    return false;
}

bool Graphics::canUseSaturationBlend() {
    return false;
}

void Graphics::setLoadingImage(const std::string& src) {
}

void Graphics::startLoading() {
}

void Graphics::updateLoading() {
}

void Graphics::endLoading() {
}

void Graphics::printError(const std::string& name, const std::string& message) {
    std::cerr << "Error: " << name << " - " << message << std::endl;
}

void Graphics::showFps() {
}

void Graphics::hideFps() {
}

void Graphics::loadFont(const std::string& name, const std::string& url) {
}

bool Graphics::isFontLoaded(const std::string& name) {
    return true;
}

void Graphics::playVideo(const std::string& src) {
}

bool Graphics::isVideoPlaying() {
    return false;
}

bool Graphics::canPlayVideoType(const std::string& type) {
    return false;
}

double Graphics::pageToCanvasX(double x) {
    return x * scale;
}

double Graphics::pageToCanvasY(double y) {
    return y * scale;
}

bool Graphics::isInsideCanvas(double x, double y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void Graphics::callGC() {
}
