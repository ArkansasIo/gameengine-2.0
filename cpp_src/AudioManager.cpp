#include "AudioManager.h"

int AudioManager::_bgmVolume = 100;
int AudioManager::_bgsVolume = 100;
int AudioManager::_meVolume = 100;
int AudioManager::_seVolume = 100;

void AudioManager::playBgm(const AudioFile& bgm, int pos) {
}

void AudioManager::replayBgm(const AudioFile& bgm) {
}

void AudioManager::isCurrentBgm(const AudioFile& bgm) {
}

void AudioManager::updateBgmParameters(const AudioFile& bgm) {
}

void AudioManager::updateCurrentBgm(const AudioFile& bgm, int pos) {
}

void AudioManager::stopBgm() {
}

void AudioManager::fadeOutBgm(int duration) {
}

void AudioManager::fadeInBgm(int duration) {
}

void AudioManager::playBgs(const AudioFile& bgs, int pos) {
}

void AudioManager::replayBgs(const AudioFile& bgs) {
}

void AudioManager::isCurrentBgs(const AudioFile& bgs) {
}

void AudioManager::updateBgsParameters(const AudioFile& bgs) {
}

void AudioManager::updateCurrentBgs(const AudioFile& bgs, int pos) {
}

void AudioManager::stopBgs() {
}

void AudioManager::fadeOutBgs(int duration) {
}

void AudioManager::fadeInBgs(int duration) {
}

void AudioManager::playMe(const AudioFile& me) {
}

void AudioManager::stopMe() {
}

void AudioManager::playSe(const AudioFile& se) {
}

void AudioManager::stopSe() {
}

void AudioManager::stopAllSe() {
}

void AudioManager::playStaticSe(const AudioFile& se) {
}

void AudioManager::loadStaticSe(const AudioFile& se) {
}

bool AudioManager::isStaticSe(const AudioFile& se) {
    return false;
}

void AudioManager::makeEmptyAudioObject() {
}

void AudioManager::createBuffer(const std::string& folder, const std::string& name) {
}

void AudioManager::updateBufferParameters(void* buffer, int volume, int pitch, int pan) {
}
