#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <vector>
//nie u¿ywabe narazie nie dzia³a
class PlayerClass : public sf::RectangleShape
{
public:
    PlayerClass(sf::Vector2f);
    void setDir_x(float);
    void setDir_y(float);
    void setObstacleColisions( std::vector<sf::FloatRect>);
    void jump(const sf::Time);
    void animate(const sf::Time);
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
};

#endif // PLAYERCLASS_H
