#include "enemy.h"

Enemy::Enemy()
{

    if (!Texture.loadFromFile("enemy.png"))
    {
        std::cout << "Could not load texture" << std::endl;
    }
    this->setTexture(Texture);
    this->setScale(0.2,0.2);
    Time_=0;
    bound_x_left_=32;
    bound_x_right_=32*31;
    bound_y_top_=32;
    bound_y_bottm_=32*21;
    floor_check_=true;
}
void Enemy::setObstacleColisions( std::vector<sf::FloatRect> obstacle_colisions)
{
    ObstacleColisions_=obstacle_colisions;
}
void Enemy::jump(const sf::Time &elapsed)
{
    Time_+=elapsed.asSeconds();
    if(Time_<0.3)
    {
       this->move(0,(float)-400*elapsed.asSeconds());
    }
    else
    {
        Time_=0;

    }
}
void Enemy::animate(const sf::Time &elapsed){

        this->move(((target.x)-(this->getGlobalBounds().left+this->getGlobalBounds().width/2))*0.01,((target.y)-(this->getGlobalBounds().top+this->getGlobalBounds().height/2))*0.01);

}
void Enemy::gravity(const sf::Time &elapsed)
{
    float time = elapsed.asSeconds();
    sf::FloatRect rectangle_bounds = this->getGlobalBounds();
        this->move(0,(float)100*time);
          if(rectangle_bounds.top+rectangle_bounds.height>(float)32*21)
            {
            this->move(0,(float)-200*time);
            }
            for(auto &obstacle : ObstacleColisions_)
            {
                if(rectangle_bounds.top+rectangle_bounds.height>obstacle.top && rectangle_bounds.top+rectangle_bounds.height<obstacle.top+obstacle.height&&(rectangle_bounds.left<obstacle.left||rectangle_bounds.left<obstacle.left+obstacle.width)&&(rectangle_bounds.left+rectangle_bounds.width>obstacle.left+obstacle.width||rectangle_bounds.left+rectangle_bounds.width>obstacle.left))
                {
                    this->move(0,(float)-200*time);
                }
            }
}
void Enemy::setTarget(sf::Vector2f Targ){target=Targ;}
int Enemy::room_number()
{
    return room_number_;
}
void Enemy::room_number_set(int number)
{
    room_number_=number;
}
bool Enemy::is_dead()
{
    return is_dead_;
}
void Enemy::kill(){
    is_dead_=true;
}
