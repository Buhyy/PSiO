#ifndef WEAPON_H
#define WEAPON_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
class weapon : public sf::Sprite
{
public:
    weapon();
private:
    int dmg_;
    sf::Texture Texture;
};

#endif // WEAPON_H
