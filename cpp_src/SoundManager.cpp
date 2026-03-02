#include "SoundManager.h"

SoundManager& SoundManager::instance() {
    static SoundManager instance;
    return instance;
}

SoundManager::SoundManager() 
    : _bgmVolume(100), _bgsVolume(100) {
}

SoundManager::~SoundManager() {
}

void SoundManager::initialize() {
}

void SoundManager::playSystemSound(int soundId) {
}

void SoundManager::playSe(const QString &filename, int volume, int pitch) {
}

void SoundManager::playMe(const QString &filename, int volume, int pitch) {
}

void SoundManager::playBgm(const QString &filename, int volume, int pitch) {
    _currentBgm = filename;
    _bgmVolume = volume;
}

void SoundManager::playBgs(const QString &filename, int volume, int pitch) {
    _currentBgs = filename;
    _bgsVolume = volume;
}

void SoundManager::pauseMe() {
}

void SoundManager::resumeMeBgm() {
}

void SoundManager::updateSe() {
}

void SoundManager::updateMe() {
}

void SoundManager::updateBgm() {
}

void SoundManager::updateBgs() {
}

void SoundManager::update() {
    updateBgm();
    updateBgs();
    updateMe();
    updateSe();
}

void SoundManager::fadeOutBgm(int duration) {
}

void SoundManager::fadeOutBgs(int duration) {
}

void SoundManager::fadeInBgm(int duration) {
}

void SoundManager::fadeInBgs(int duration) {
}

void SoundManager::stopBgm() {
    _currentBgm.clear();
}

void SoundManager::stopBgs() {
    _currentBgs.clear();
}

void SoundManager::stopMe() {
}

void SoundManager::stopSe() {
}
