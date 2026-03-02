#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "Game_CharacterBase.h"

class Game_Character : public Game_CharacterBase {
public:
    Game_Character();
    ~Game_Character();

    void initialize() override;
    void update() override;
    
    void setMovementRoute(const QVector<int> &route);
    void setWalkerImage(const QString &name);
    void setProfile(int characterId, int characterIndex);
    
    void moveRandom();
    void moveTowardActor(int actorId);
    void moveAwayFromActor(int actorId);
    void moveForward();
    void moveBackward();
    
    int direction() const;
    void setDirection(int direction);
    bool isTurning() const;

private:
    int _characterIndex;
    QString _characterName;
};

#endif // GAME_CHARACTER_H
