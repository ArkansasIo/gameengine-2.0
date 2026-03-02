#ifndef GAME_VARIABLES_H
#define GAME_VARIABLES_H

#include <vector>

class Game_Variables {
public:
    Game_Variables();
    ~Game_Variables();
    
    void initialize();
    void clear();
    int value(int variableId) const;
    void setValue(int variableId, int value);
    
private:
    std::vector<int> _data;
};

#endif // GAME_VARIABLES_H
