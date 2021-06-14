#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class PlayerClass : public sf::Sprite
{
public:
    PlayerClass();
    void setDir_x(float D_x);
    void setDir_y(float D_y);
    void setObstacleColisions( std::vector<sf::FloatRect> obstacle_colisions);
    void jump(const sf::Time &elapsed);
    void animate(const sf::Time &elapsed);
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

};
#endif // PLAYERCLASS_H
