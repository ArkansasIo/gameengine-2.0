#include "Sprite_Animation.h"

Sprite_Animation::Sprite_Animation() : _animationId(0), _isPlaying(false) {
}

Sprite_Animation::~Sprite_Animation() {
}

void Sprite_Animation::initialize() {
}

void Sprite_Animation::update() {
}

void Sprite_Animation::startAnimation(int animationId) {
    _animationId = animationId;
    _isPlaying = true;
}

bool Sprite_Animation::isAnimationPlaying() const {
    return _isPlaying;
}

void Sprite_Animation::stopAnimation() {
    _isPlaying = false;
}
