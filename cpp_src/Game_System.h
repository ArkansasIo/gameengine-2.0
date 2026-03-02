#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

#include <string>
#include "AudioManager.h"

class Game_System {
public:
    Game_System();
    ~Game_System();
    
    void initialize();
    bool isJapanese() const;
    bool isChinese() const;
    bool isKorean() const;
    bool isCJK() const;
    bool isRussian() const;
    bool isSideView() const;
    bool isSaveEnabled() const;
    void disableSave();
    void enableSave();
    bool isMenuEnabled() const;
    void disableMenu();
    void enableMenu();
    bool isEncounterEnabled() const;
    void disableEncounter();
    void enableEncounter();
    bool isFormationEnabled() const;
    void disableFormation();
    void enableFormation();
    int battleCount() const;
    int winCount() const;
    int escapeCount() const;
    int saveCount() const;
    int versionId() const;
    std::string windowTone() const;
    void setWindowTone(int r, int g, int b);
    int battleBgm() const;
    void setBattleBgm(const AudioFile& bgm);
    int victoryMe() const;
    void setVictoryMe(const AudioFile& me);
    int defeatMe() const;
    void setDefeatMe(const AudioFile& me);
    void onBattleStart();
    void onBattleWin();
    void onBattleEscape();
    void onBeforeSave();
    void onAfterLoad();
    int playtime() const;
    std::string playtimeText() const;
    void saveBgm();
    void replayBgm();
    void saveBgs();
    void replayBgs();
    
private:
    bool _saveEnabled;
    bool _menuEnabled;
    bool _encounterEnabled;
    bool _formationEnabled;
    int _battleCount;
    int _winCount;
    int _escapeCount;
    int _saveCount;
    int _versionId;
    int _framesOnSave;
    int _bgmOnSave;
    int _bgsOnSave;
    int _windowTone[3];
    AudioFile _battleBgm;
    AudioFile _victoryMe;
    AudioFile _defeatMe;
};

#endif // GAME_SYSTEM_H
