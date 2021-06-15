#ifndef ITEM_H
#define ITEM_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Item : public sf::Sprite
{
public:
    Item();
    int hp();
    void take();
    bool taken();
private:
    int heal;
    int hp_;
    int dmg;
    int speed;
    sf::Texture Texture;
    bool taken_;
};

#endif // ITEM_H
