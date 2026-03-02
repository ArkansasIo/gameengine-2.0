#ifndef SPRITELAYER_H
#define SPRITELAYER_H

class SpriteLayer {
public:
    SpriteLayer();
    ~SpriteLayer();

    void initialize();
    void update();
    void addSprite(void *sprite);
    void removeSprite(void *sprite);
    void sort();

private:
};

#endif // SPRITELAYER_H
