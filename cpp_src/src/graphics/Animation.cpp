#include "../../include/graphics/Animation.h"

namespace LunaLite {
namespace Graphics {

Animation::Animation(int id)
    : _id(id), _playing(false), _currentFrame(0), _frameTimer(0) {
}

Animation::~Animation() {
    _frames.clear();
}

int Animation::getId() const {
    return _id;
}

void Animation::addFrame(const AnimationFrame &frame) {
    _frames.append(frame);
}

void Animation::removeFrame(int frameIndex) {
    if (frameIndex >= 0 && frameIndex < _frames.size()) {
        _frames.remove(frameIndex);
    }
}

int Animation::getFrameCount() const {
    return _frames.size();
}

AnimationFrame Animation::getFrame(int index) const {
    if (index >= 0 && index < _frames.size()) {
        return _frames[index];
    }
    return AnimationFrame{0, 0, 1.0f, 1.0f};
}

void Animation::play() {
    _playing = true;
}

void Animation::pause() {
    _playing = false;
}

void Animation::stop() {
    _playing = false;
    _currentFrame = 0;
    _frameTimer = 0;
}

void Animation::reset() {
    _currentFrame = 0;
    _frameTimer = 0;
}

bool Animation::isPlaying() const {
    return _playing;
}

int Animation::getCurrentFrame() const {
    return _currentFrame;
}

float Animation::getProgress() const {
    if (_frames.isEmpty()) return 0.0f;
    return static_cast<float>(_currentFrame) / _frames.size();
}

void Animation::update() {
    if (!_playing || _frames.isEmpty()) return;
    
    AnimationFrame currentFrameData = _frames[_currentFrame];
    _frameTimer++;
    
    if (_frameTimer >= currentFrameData.duration) {
        _frameTimer = 0;
        _currentFrame++;
        
        if (_currentFrame >= _frames.size()) {
            _currentFrame = 0;  // Loop animation
        }
    }
}

} // namespace Graphics
} // namespace LunaLite
