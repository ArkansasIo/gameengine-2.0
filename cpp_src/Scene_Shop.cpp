#include "Scene_Shop.h"

Scene_Shop::Scene_Shop() : _commandWindow(nullptr), _buyWindow(nullptr), 
                            _sellWindow(nullptr), _numberWindow(nullptr), _statusWindow(nullptr) {
}

Scene_Shop::~Scene_Shop() {
}

void Scene_Shop::initialize() {
    Scene_Base::initialize();
}

void Scene_Shop::create() {
    Scene_Base::create();
}

void Scene_Shop::start() {
    Scene_Base::start();
}

void Scene_Shop::update() {
    Scene_Base::update();
}

void Scene_Shop::stop() {
    Scene_Base::stop();
}

void Scene_Shop::terminate() {
    Scene_Base::terminate();
}

void Scene_Shop::commandBuy() {
}

void Scene_Shop::commandSell() {
}

void Scene_Shop::onBuyOk() {
}

void Scene_Shop::onBuyCancel() {
}

void Scene_Shop::onSellOk() {
}

void Scene_Shop::onSellCancel() {
}

void Scene_Shop::onNumberOk() {
}

void Scene_Shop::onNumberCancel() {
}
