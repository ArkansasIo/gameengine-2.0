#ifndef WINDOW_SHOPPINGGOLD_H
#define WINDOW_SHOPPINGGOLD_H

#include "Window_Gold.h"

class Window_ShopBuy : public Window_ItemList {
public:
    Window_ShopBuy(int x, int y, int width, int height);
    ~Window_ShopBuy();

    void setShopGoods(const QVector<int> &goodsList);
    void refresh();
    void drawItem(int index);

private:
    QVector<int> _goods;
};

#endif // WINDOW_SHOPPINGGOLD_H
