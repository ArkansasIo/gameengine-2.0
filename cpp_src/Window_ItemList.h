#ifndef WINDOW_ITEMLIST_H
#define WINDOW_ITEMLIST_H

#include "Window_Selectable.h"

class Window_ItemList : public Window_Selectable {
public:
    Window_ItemList(int x, int y, int width, int height);
    ~Window_ItemList();

    void setCategory(const QString &category);
    void refresh();
    
    void *item() const;
    bool includes(void *item) const;
    bool isEnabled(void *item) const;
    
private:
    QString _category;
};

#endif // WINDOW_ITEMLIST_H
