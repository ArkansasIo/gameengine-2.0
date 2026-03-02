#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <map>

class Input {
public:
    static int keyRepeatWait;
    static int keyRepeatInterval;
    static std::map<int, std::string> keyMapper;
    static std::map<int, std::string> gamepadMapper;
    static int dir4;
    static int dir8;
    static long long date;
    
    static void initialize();
    static void clear();
    static void update();
    static bool isPressed(const std::string& keyName);
    static bool isTriggered(const std::string& keyName);
    static bool isRepeated(const std::string& keyName);
    static bool isLongPressed(const std::string& keyName);
    
private:
    Input() = delete;
};

#endif // INPUT_H
