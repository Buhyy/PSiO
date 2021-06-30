#ifndef ITEM_H
#define ITEM_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Item : public sf::Sprite
{
public:
    Item();
    int hp();
    int dmg();
    int speed();
    int heal();
    int armour();
    void take();
    bool taken();
    int room_number();
    void room_number_set(int number);
private:
    int heal_;
    int hp_;
    int dmg_;
    int speed_;
    int armour_;
    sf::Texture Texture;
    bool taken_;
    int room_number_;
};

#endif // ITEM_H
