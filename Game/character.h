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
    virtual void room_number_set(unsigned long long number);
    virtual void setTarget(sf::Vector2f Targ);
    virtual unsigned long long room_number();
    virtual bool is_dead();
    virtual void kill();
    virtual void deal_dmg(int dmg_dealt);
    virtual int health();

};

#endif // CHARACTER_H
