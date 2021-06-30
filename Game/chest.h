#ifndef CHEST_H
#define CHEST_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "item.h"

class chest
{
public:
    chest();
private:
    sf::Texture Texture1,Texture2;
    int rarity_;
    int type_;
};

#endif // CHEST_H
