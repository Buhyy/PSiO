#ifndef WEAPON_H
#define WEAPON_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
class weapon : public sf::Sprite
{
public:
    weapon();
    void atack(float &timer,const float &elapsed);
    bool is_atacking();
    void set_atack();
private:
    bool is_atacking_;
    int dmg_;
    sf::Texture Texture,Texture2;
};

#endif // WEAPON_H
