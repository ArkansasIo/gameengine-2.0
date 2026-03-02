#ifndef GAME_ACTIONRESULT_H
#define GAME_ACTIONRESULT_H

class Game_ActionResult {
public:
    Game_ActionResult();
    ~Game_ActionResult();

    void clear();
    
    bool isHit() const;
    void setHit(bool hit);
    
    bool isCritical() const;
    void setCritical(bool critical);
    
    int damage() const;
    void setDamage(int damage);
    
    bool isSuccessful() const;
    int healEffect() const;
    bool isEvaded() const;
    bool isPhysical() const;

private:
    bool _hit;
    bool _critical;
    int _damage;
    bool _successful;
};

#endif // GAME_ACTIONRESULT_H
