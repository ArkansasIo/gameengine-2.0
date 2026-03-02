#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "Game_BattlerBase.h"

class Game_Enemy : public Game_BattlerBase {
public:
    Game_Enemy(int enemyId, int x, int y);
    ~Game_Enemy();

    void setup(int enemyId, int x, int y);
    void initialize();
    int enemyId() const;
    QString name() const;
    int level() const;
    int maxHp() const;
    int maxMp() const;
    int exp() const;
    int gold() const;
    QList<int> makeDropItems();
    int battlerName() const;
    int battlerHue() const;
    int param() const;
    double paramBase(int paramId) const;
    int isSpriteVisible() const;
    int shouldPopupDamage() const;
    bool escapeRate() const;
    bool canDropLoot() const;
    int corpseX() const;
    int corpseY() const;
    
private:
    int _enemyId;
    int _screenX;
    int _screenY;
};

#endif // GAME_ENEMY_H
