#ifndef WINDOWLAYER_H
#define WINDOWLAYER_H

class WindowLayer {
public:
    WindowLayer();
    ~WindowLayer();

    void initialize();
    void update();
    void addWindow(void *window);
    void removeWindow(void *window);
    void sort();

private:
};

#endif // WINDOWLAYER_H
