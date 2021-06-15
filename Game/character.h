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
};

#endif // CHARACTER_H
