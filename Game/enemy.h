#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.h"
class Enemy : public Character
{
public:
    Enemy(int type);
    void setObstacleColisions( std::vector<sf::FloatRect> obstacle_colisions);
    void jump(const sf::Time &elapsed);
    void setTarget(sf::Vector2f Targ);
    void animate(const sf::Time &elapsed);
    void gravity(const sf::Time &elapsed);
    unsigned long long room_number();
    void room_number_set(unsigned long long number);
    bool is_dead();
    void kill();
    int dmg();
    int health();
    void deal_dmg(int dmg_dealt);
    bool can_fly();
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
    bool fly_;
    sf::Texture Texture,Texture1;
    sf::Vector2f target;

    int health_;
    int dmg_;
    int speed_;
    int armour_;

    bool is_dead_;
    unsigned long long room_number_;
    int variant;

};
#endif // PLAYERCLASS_H
