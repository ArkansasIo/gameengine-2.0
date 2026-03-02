#ifndef SPRITE_ANIMATION_H
#define SPRITE_ANIMATION_H

class Sprite_Animation {
public:
    Sprite_Animation();
    ~Sprite_Animation();

    void initialize();
    void update();
    
    void startAnimation(int animationId);
    bool isAnimationPlaying() const;
    void stopAnimation();

private:
    int _animationId;
    bool _isPlaying;
};

#endif // SPRITE_ANIMATION_H
