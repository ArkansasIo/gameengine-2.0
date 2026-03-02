#ifndef SPRITE_CHARACTER_H
#define SPRITE_CHARACTER_H

class Sprite_Character {
public:
    Sprite_Character();
    ~Sprite_Character();

    void initialize();
    void update();
    void setCharacter(void *character);
    void updateCharacterFrame();

private:
};

#endif // SPRITE_CHARACTER_H
