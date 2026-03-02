#ifndef GAME_TIMER_H
#define GAME_TIMER_H

class Game_Timer {
public:
    Game_Timer();
    ~Game_Timer();
    
    void initialize();
    void update();
    void start(int count);
    void stop();
    bool isWorking() const;
    int seconds() const;
    
private:
    bool _working;
    int _frames;
};

#endif // GAME_TIMER_H
