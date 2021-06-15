#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.h"
class Enemy : public Character
{
public:
    Enemy();
    void setObstacleColisions( std::vector<sf::FloatRect> obstacle_colisions);
    void jump(const sf::Time &elapsed);
    void setTarget(sf::Vector2f Targ);
    void animate(const sf::Time &elapsed);
    void gravity(const sf::Time &elapsed);
private:
    float Time_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    std::vector<sf::FloatRect> ObstacleColisions_;
    float bound_x_left_;
    float bound_x_right_;
    float bound_y_top_;
    float bound_y_bottm_;
    bool floor_check_;
    sf::Texture Texture;
    sf::Vector2f target;

    int health_;
    int dmg_;
    int speed_;
    int armour_;

};
#endif // PLAYERCLASS_H
