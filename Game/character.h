#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Character : public sf::Sprite
{
public:
    Character();
    virtual ~Character();
    virtual void gravity();
    virtual void animate(const sf::Time &elapsed);
    virtual void room_number_set(int number);
    virtual void setTarget(sf::Vector2f Targ);
    virtual int room_number();
    bool is_dead();
    void kill();

};

#endif // CHARACTER_H
