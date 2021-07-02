#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include "character.h"
#include "enemy.h"
#include "weapon.h"

class PlayerClass : public Character
{
public:
    PlayerClass();
    void setDir_x(float D_x);
    void setDir_y(float D_y);
    float getDix_x();
    void setObstacleColisions( std::vector<sf::FloatRect> obstacle_colisions);
    void jump(const sf::Time &elapsed);
    void animate(const sf::Time &elapsed);
    void gravity(const sf::Time &elapsed);
    int health();
    int health_max();
    void addHp(int bonus);
    int dmg();
    void adddmg(int bonus);
    int armour();
    void addarmour(int bonus);
    int speed();
    void addspeed(int bonus);
    void heal(int bonus);
    void weapon_place_r();
    void weapon_place_l();
    void get_hurt(int ammount);
    weapon weapon_eq;
private:
    float Time_;
    float dir_x_;
    float dir_y_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    std::vector<sf::FloatRect> ObstacleColisions_;
    float bound_x_left_;
    float bound_x_right_;
    float bound_y_top_;
    float bound_y_bottm_;
    bool floor_check_;
    sf::Texture Texture,Texture1;

    int health_;
    int health_max_;
    int dmg_;
    int speed_;
    int armour_;
    int jumps_;

};
#endif // PLAYERCLASS_H
