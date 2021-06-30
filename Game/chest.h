#ifndef CHEST_H
#define CHEST_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "item.h"

class chest : public sf::Sprite
{
public:
    chest();
    int room_number();
    void room_number_set(int number);
    void open();
    bool is_oppened();
    Item itemik;
private:
    sf::Texture Texture1,Texture2;
    int rarity_;
    bool clossed_;
    int room_number_;
};

#endif // CHEST_H
