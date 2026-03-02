#ifndef GAME_SWITCHES_H
#define GAME_SWITCHES_H

#include <vector>

class Game_Switches {
public:
    Game_Switches();
    ~Game_Switches();
    
    void initialize();
    void clear();
    bool value(int switchId) const;
    void setValue(int switchId, bool value);
    
private:
    std::vector<bool> _data;
};

#endif // GAME_SWITCHES_H
