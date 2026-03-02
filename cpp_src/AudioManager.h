#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <string>

struct AudioFile {
    std::string name;
    int volume;
    int pitch;
    int pan;
    
    AudioFile() : name(""), volume(100), pitch(100), pan(0) {}
    AudioFile(const std::string& n, int v = 100, int p = 100, int pn = 0)
        : name(n), volume(v), pitch(p), pan(pn) {}
};

class AudioManager {
public:
    static int _bgmVolume;
    static int _bgsVolume;
    static int _meVolume;
    static int _seVolume;
    
    static void playBgm(const AudioFile& bgm, int pos = 0);
    static void replayBgm(const AudioFile& bgm);
    static void isCurrentBgm(const AudioFile& bgm);
    static void updateBgmParameters(const AudioFile& bgm);
    static void updateCurrentBgm(const AudioFile& bgm, int pos);
    static void stopBgm();
    static void fadeOutBgm(int duration);
    static void fadeInBgm(int duration);
    
    static void playBgs(const AudioFile& bgs, int pos = 0);
    static void replayBgs(const AudioFile& bgs);
    static void isCurrentBgs(const AudioFile& bgs);
    static void updateBgsParameters(const AudioFile& bgs);
    static void updateCurrentBgs(const AudioFile& bgs, int pos);
    static void stopBgs();
    static void fadeOutBgs(int duration);
    static void fadeInBgs(int duration);
    
    static void playMe(const AudioFile& me);
    static void stopMe();
    
    static void playSe(const AudioFile& se);
    static void stopSe();
    static void stopAllSe();
    
    static void playStaticSe(const AudioFile& se);
    static void loadStaticSe(const AudioFile& se);
    static bool isStaticSe(const AudioFile& se);
    
    static void makeEmptyAudioObject();
    static void createBuffer(const std::string& folder, const std::string& name);
    static void updateBufferParameters(void* buffer, int volume, int pitch, int pan);
    
private:
    AudioManager() = delete;
};

#endif // AUDIO_MANAGER_H
