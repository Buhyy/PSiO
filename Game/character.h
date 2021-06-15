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
    virtual void animate();
};

#endif // CHARACTER_H
