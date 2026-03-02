#include "Game_System.h"
#include "Graphics.h"

Game_System::Game_System() 
    : _saveEnabled(true), _menuEnabled(true), 
      _encounterEnabled(true), _formationEnabled(true),
      _battleCount(0), _winCount(0), _escapeCount(0), 
      _saveCount(0), _versionId(0), _framesOnSave(0),
      _bgmOnSave(0), _bgsOnSave(0) {
    _windowTone[0] = 0;
    _windowTone[1] = 0;
    _windowTone[2] = 0;
}

Game_System::~Game_System() {
}

void Game_System::initialize() {
    _saveEnabled = true;
    _menuEnabled = true;
    _encounterEnabled = true;
    _formationEnabled = true;
    _battleCount = 0;
    _winCount = 0;
    _escapeCount = 0;
    _saveCount = 0;
}

bool Game_System::isJapanese() const {
    return false;
}

bool Game_System::isChinese() const {
    return false;
}

bool Game_System::isKorean() const {
    return false;
}

bool Game_System::isCJK() const {
    return isJapanese() || isChinese() || isKorean();
}

bool Game_System::isRussian() const {
    return false;
}

bool Game_System::isSideView() const {
    return false;
}

bool Game_System::isSaveEnabled() const {
    return _saveEnabled;
}

void Game_System::disableSave() {
    _saveEnabled = false;
}

void Game_System::enableSave() {
    _saveEnabled = true;
}

bool Game_System::isMenuEnabled() const {
    return _menuEnabled;
}

void Game_System::disableMenu() {
    _menuEnabled = false;
}

void Game_System::enableMenu() {
    _menuEnabled = true;
}

bool Game_System::isEncounterEnabled() const {
    return _encounterEnabled;
}

void Game_System::disableEncounter() {
    _encounterEnabled = false;
}

void Game_System::enableEncounter() {
    _encounterEnabled = true;
}

bool Game_System::isFormationEnabled() const {
    return _formationEnabled;
}

void Game_System::disableFormation() {
    _formationEnabled = false;
}

void Game_System::enableFormation() {
    _formationEnabled = true;
}

int Game_System::battleCount() const {
    return _battleCount;
}

int Game_System::winCount() const {
    return _winCount;
}

int Game_System::escapeCount() const {
    return _escapeCount;
}

int Game_System::saveCount() const {
    return _saveCount;
}

int Game_System::versionId() const {
    return _versionId;
}

std::string Game_System::windowTone() const {
    return "";
}

void Game_System::setWindowTone(int r, int g, int b) {
    _windowTone[0] = r;
    _windowTone[1] = g;
    _windowTone[2] = b;
}

int Game_System::battleBgm() const {
    return 0;
}

void Game_System::setBattleBgm(const AudioFile& bgm) {
    _battleBgm = bgm;
}

int Game_System::victoryMe() const {
    return 0;
}

void Game_System::setVictoryMe(const AudioFile& me) {
    _victoryMe = me;
}

int Game_System::defeatMe() const {
    return 0;
}

void Game_System::setDefeatMe(const AudioFile& me) {
    _defeatMe = me;
}

void Game_System::onBattleStart() {
    _battleCount++;
}

void Game_System::onBattleWin() {
    _winCount++;
}

void Game_System::onBattleEscape() {
    _escapeCount++;
}

void Game_System::onBeforeSave() {
    _saveCount++;
    _framesOnSave = Graphics::frameCount;
}

void Game_System::onAfterLoad() {
}

int Game_System::playtime() const {
    return Graphics::frameCount - _framesOnSave;
}

std::string Game_System::playtimeText() const {
    int hour = playtime() / 60 / 60;
    int min = playtime() / 60 % 60;
    int sec = playtime() % 60;
    return std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(sec);
}

void Game_System::saveBgm() {
}

void Game_System::replayBgm() {
}

void Game_System::saveBgs() {
}

void Game_System::replayBgs() {
}
