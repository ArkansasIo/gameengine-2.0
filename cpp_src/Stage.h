#ifndef STAGE_H
#define STAGE_H

#include <vector>

class Sprite;

class Stage {
public:
    Stage();
    ~Stage();
    
    void addChild(Sprite* child);
    void removeChild(Sprite* child);
    void update();
    void render();
    
    std::vector<Sprite*> children;
    
private:
    void updateChildren();
};

#endif // STAGE_H
