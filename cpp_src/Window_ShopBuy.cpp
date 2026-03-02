#include "Window_ShopBuy.h"

Window_ShopBuy::Window_ShopBuy(int x, int y, int width, int height) 
    : Window_ItemList(x, y, width, height) {
}

Window_ShopBuy::~Window_ShopBuy() {
}

void Window_ShopBuy::setShopGoods(const QVector<int> &goodsList) {
    _goods = goodsList;
    refresh();
}

void Window_ShopBuy::refresh() {
}

void Window_ShopBuy::drawItem(int index) {
}
