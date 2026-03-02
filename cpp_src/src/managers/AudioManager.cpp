#include "../../include/managers/AudioManager.h"

namespace LunaLite {
namespace Managers {

AudioManager& AudioManager::instance() {
    static AudioManager manager;
    return manager;
}

AudioManager::AudioManager()
    : _masterVolume(100), _bgmVolume(100), _bgsVolume(100), _seVolume(100),
      _bgmPlaying(false), _bgsPlaying(false), _mePlaying(false) {
}

AudioManager::~AudioManager() {
    clear();
}

void AudioManager::playBgm(const QString &filename, int volume, float pitch) {
    _currentBgm = filename;
    _bgmVolume = volume;
    _bgmPlaying = true;
}

void AudioManager::pauseBgm() {
    _bgmPlaying = false;
}

void AudioManager::resumeBgm() {
    if (!_currentBgm.isEmpty()) {
        _bgmPlaying = true;
    }
}

void AudioManager::stopBgm(float fadeTime) {
    _currentBgm.clear();
    _bgmPlaying = false;
}

void AudioManager::playBgs(const QString &filename, int volume, float pitch) {
    _currentBgs = filename;
    _bgsVolume = volume;
    _bgsPlaying = true;
}

void AudioManager::pauseBgs() {
    _bgsPlaying = false;
}

void AudioManager::resumeBgs() {
    if (!_currentBgs.isEmpty()) {
        _bgsPlaying = true;
    }
}

void AudioManager::stopBgs(float fadeTime) {
    _currentBgs.clear();
    _bgsPlaying = false;
}

void AudioManager::playMe(const QString &filename, int volume, float pitch) {
    _mePlaying = true;
}

void AudioManager::stopMe() {
    _mePlaying = false;
}

void AudioManager::playSe(const QString &filename, int volume, float pitch) {
    // Would play sound effect
}

void AudioManager::stopSe(int seId) {
    // Would stop specific SE
}

void AudioManager::stopAllSe() {
    // Would stop all SEs
}

void AudioManager::setMasterVolume(int volume) {
    _masterVolume = (volume < 0) ? 0 : (volume > 100) ? 100 : volume;
}

void AudioManager::setBgmVolume(int volume) {
    _bgmVolume = (volume < 0) ? 0 : (volume > 100) ? 100 : volume;
}

void AudioManager::setBgsVolume(int volume) {
    _bgsVolume = (volume < 0) ? 0 : (volume > 100) ? 100 : volume;
}

void AudioManager::setSeVolume(int volume) {
    _seVolume = (volume < 0) ? 0 : (volume > 100) ? 100 : volume;
}

int AudioManager::getMasterVolume() const {
    return _masterVolume;
}

int AudioManager::getBgmVolume() const {
    return _bgmVolume;
}

int AudioManager::getBgsVolume() const {
    return _bgsVolume;
}

int AudioManager::getSeVolume() const {
    return _seVolume;
}

bool AudioManager::isBgmPlaying() const {
    return _bgmPlaying;
}

bool AudioManager::isBgsPlaying() const {
    return _bgsPlaying;
}

bool AudioManager::isMePlaying() const {
    return _mePlaying;
}

void AudioManager::fadeBgm(float time) {
    // Would fade BGM over time
}

void AudioManager::fadeBgs(float time) {
    // Would fade BGS over time
}

void AudioManager::clear() {
    _currentBgm.clear();
    _currentBgs.clear();
    _bgmPlaying = false;
    _bgsPlaying = false;
    _mePlaying = false;
}

} // namespace Managers
} // namespace LunaLite
