#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include <QString>

class Game_Weapon {
public:
    Game_Weapon(int weaponId);
    ~Game_Weapon();

    int weaponId() const;
    int weaponType() const;
    int price() const;
    bool canEquip() const;
    
    QString name() const;
    QString description() const;
    QString iconIndex() const;
    
private:
    int _weaponId;
};

#endif // GAME_WEAPON_H
