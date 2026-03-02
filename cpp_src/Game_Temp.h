#ifndef GAME_TEMP_H
#define GAME_TEMP_H

#include <string>

class Game_Temp {
public:
    Game_Temp();
    ~Game_Temp();
    
    void initialize();
    bool isPlaytest() const;
    void reserveCommonEvent(int commonEventId);
    void clearCommonEvent();
    bool isCommonEventReserved() const;
    int reservedCommonEvent() const;
    void setDestination(int x, int y);
    void clearDestination();
    bool isDestinationValid() const;
    int destinationX() const;
    int destinationY() const;
    
private:
    bool _isPlaytest;
    int _commonEventId;
    int _destinationX;
    int _destinationY;
};

#endif // GAME_TEMP_H
