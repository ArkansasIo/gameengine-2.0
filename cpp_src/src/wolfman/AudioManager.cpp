#include "../../include/wolfman/AudioManager.h"

namespace WolfManAlpha {

AudioSource::AudioSource(const QString &name)
    : _name(name), _volume(1.0f), _pitch(1.0f), _loop(false),
      _playing(false), _playbackTime(0) {
}

AudioSource::~AudioSource() {
}

void AudioSource::play() {
    _playing = true;
    _playbackTime = 0;
}

void AudioSource::pause() {
    _playing = false;
}

void AudioSource::stop() {
    _playing = false;
    _playbackTime = 0;
}

void AudioSource::resume() {
    _playing = true;
}

void AudioSource::setVolume(float volume) {
    _volume = (volume < 0) ? 0 : (volume > 1) ? 1 : volume;
}

void AudioSource::setPitch(float pitch) {
    _pitch = pitch;
}

void AudioSource::setLoop(bool loop) {
    _loop = loop;
}

void AudioSource::setPan(float pan) {
    // Stereo panning: -1 (left) to 1 (right)
}

float AudioSource::getVolume() const {
    return _volume;
}

float AudioSource::getPitch() const {
    return _pitch;
}

bool AudioSource::isLooping() const {
    return _loop;
}

bool AudioSource::isPlaying() const {
    return _playing;
}

void AudioSource::fadeIn(float duration) {
    fadeTo(1.0f, duration);
}

void AudioSource::fadeOut(float duration) {
    fadeTo(0.0f, duration);
}

void AudioSource::fadeTo(float targetVolume, float duration) {
    // Linearly interpolate volume over duration
}

void AudioSource::set3DPosition(float x, float y, float z) {
    // Set 3D positional audio data
}

float AudioSource::getDuration() const {
    return 0.0f;  // Would query audio file
}

float AudioSource::getPlaybackTime() const {
    return _playbackTime;
}

void AudioSource::setPlaybackTime(float time) {
    _playbackTime = time;
}

void AudioSource::update(float deltaTime) {
    if (_playing) {
        _playbackTime += deltaTime;
    }
}

AudioManager& AudioManager::instance() {
    static AudioManager manager;
    return manager;
}

AudioManager::AudioManager() : _masterVolume(1.0f) {
}

AudioManager::~AudioManager() {
    for (auto source : _audioSources) {
        delete source;
    }
    _audioSources.clear();
}

bool AudioManager::loadAudio(const QString &name, const QString &filePath, AudioSourceType type) {
    if (!_audioSources.contains(name)) {
        _audioSources[name] = new AudioSource(name);
        return true;
    }
    return false;
}

void AudioManager::unloadAudio(const QString &name) {
    if (_audioSources.contains(name)) {
        delete _audioSources[name];
        _audioSources.remove(name);
    }
}

AudioSource* AudioManager::playAudio(const QString &name, bool loop) {
    if (_audioSources.contains(name)) {
        AudioSource* source = _audioSources[name];
        source->setLoop(loop);
        source->play();
        return source;
    }
    return nullptr;
}

void AudioManager::stopAudio(const QString &name) {
    if (_audioSources.contains(name)) {
        _audioSources[name]->stop();
    }
}

void AudioManager::setMasterVolume(float volume) {
    _masterVolume = (volume < 0) ? 0 : (volume > 1) ? 1 : volume;
}

void AudioManager::setTypeVolume(AudioSourceType type, float volume) {
    // Set volume for audio of specific type
}

float AudioManager::getMasterVolume() const {
    return _masterVolume;
}

float AudioManager::getTypeVolume(AudioSourceType type) const {
    return 1.0f;
}

bool AudioManager::hasAudio(const QString &name) const {
    return _audioSources.contains(name);
}

int AudioManager::getAudioCount() const {
    return _audioSources.size();
}

int AudioManager::getPlayingAudioCount() const {
    int count = 0;
    for (auto source : _audioSources) {
        if (source && source->isPlaying()) count++;
    }
    return count;
}

void AudioManager::setReverbPreset(int preset) {
    // Set reverb effect based on preset
}

void AudioManager::setEqualizerBand(int band, float gain) {
    // Adjust EQ band gain
}

void AudioManager::update(float deltaTime) {
    for (auto source : _audioSources) {
        if (source) {
            source->update(deltaTime);
        }
    }
}

void AudioManager::stopAll() {
    for (auto source : _audioSources) {
        if (source) {
            source->stop();
        }
    }
}

} // namespace WolfManAlpha
