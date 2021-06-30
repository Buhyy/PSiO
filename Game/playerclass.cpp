#include "playerclass.h"

PlayerClass::PlayerClass()
{

    if (!Texture.loadFromFile("Patatek.png"))
    {
        std::cout << "Could not load texture" << std::endl;
    }
    this->setTexture(Texture);
    Time_=0;
    dir_x_=0;
    dir_y_=0;
    bound_x_left_=32;
    bound_x_right_=32*31;
    bound_y_top_=32;
    bound_y_bottm_=32*21;
    floor_check_=true;

    health_max_=100;
    health_=health_max_;
    armour_=10;
    speed_=200;
    dmg_=20;

}
void PlayerClass::setDir_x(float D_x)
{
   dir_x_=D_x;
}
void PlayerClass::setDir_y(float D_y)
{
    dir_y_=D_y;
}
void PlayerClass::setObstacleColisions( std::vector<sf::FloatRect> obstacle_colisions)
{
    ObstacleColisions_=obstacle_colisions;
}
void PlayerClass::jump(const sf::Time &elapsed)
{
    Time_+=elapsed.asSeconds();
    if(Time_<0.3)
    {
       this->move(0,(float)-400*elapsed.asSeconds());
        weapon_eq.move(0,(float)-400*elapsed.asSeconds());
    }
    else
    {
        Time_=0;
        dir_y_=0;
    }
}
void PlayerClass::animate(const sf::Time &elapsed){
    sf::FloatRect rectangle_bounds = this->getGlobalBounds();
    float time = elapsed.asSeconds();
    this->move((float)200*dir_x_*time,0);
    weapon_eq.move((float)200*dir_x_*time,0);

    // poruszanie po y
    if(dir_y_==1)
    {
        if(rectangle_bounds.top+rectangle_bounds.height>bound_y_bottm_)
        {
        this->move(0,(float)-400*dir_y_*time);
        weapon_eq.move(0,(float)-400*dir_y_*time);
        dir_y_=0;
       // floor_check_=false;
        }
        for(auto &obstacle : ObstacleColisions_)
        {
            if(rectangle_bounds.top+rectangle_bounds.height>obstacle.top && rectangle_bounds.top+rectangle_bounds.height<obstacle.top+obstacle.height
                    &&(rectangle_bounds.left<obstacle.left||rectangle_bounds.left<obstacle.left+obstacle.width)
                    &&(rectangle_bounds.left+rectangle_bounds.width>obstacle.left+obstacle.width||rectangle_bounds.left+rectangle_bounds.width>obstacle.left))
            {
                this->move(0,(float)-400*dir_y_*time);
                weapon_eq.move(0,(float)-400*dir_y_*time);
                dir_y_=0;
               // floor_check_=false;
            }
        }

    }
    if(dir_y_==-1)
    {
        if(floor_check_)this->jump(elapsed);
        if(rectangle_bounds.top<bound_y_top_)
        {
            this->move(0,(float)-600*dir_y_*time);
            weapon_eq.move(0,(float)-600*dir_y_*time);
            dir_y_=0;
            Time_=0;
        }
        for(auto &obstacle : ObstacleColisions_)
        {
            if(rectangle_bounds.top<obstacle.top+obstacle.height && rectangle_bounds.top>obstacle.top
                    &&(rectangle_bounds.left<obstacle.left||rectangle_bounds.left<obstacle.left+obstacle.width)
                    &&(rectangle_bounds.left+rectangle_bounds.width>obstacle.left+obstacle.width||rectangle_bounds.left+rectangle_bounds.width>obstacle.left))
            {
                this->move(0,(float)-600*dir_y_*time);
                weapon_eq.move(0,(float)-600*dir_y_*time);
                dir_y_=0;
                Time_=0;
            }
        }

    }



    //poruszanie po x
    if(dir_x_==1)
    {
        weapon_place_r();
         if(rectangle_bounds.left+rectangle_bounds.width>bound_x_right_)
        {
        this->move((float)-speed_*dir_x_*time,0);
            weapon_eq.move((float)-speed_*dir_x_*time,0);

        dir_x_=0;
        }
        for(auto &obstacle : ObstacleColisions_)
        {
            if(rectangle_bounds.left+rectangle_bounds.width>obstacle.left && rectangle_bounds.left+rectangle_bounds.width<obstacle.left+obstacle.width
                    &&(rectangle_bounds.top<obstacle.top||rectangle_bounds.top<obstacle.top+obstacle.height)
                    &&(rectangle_bounds.top+rectangle_bounds.height>obstacle.top+obstacle.height||rectangle_bounds.top+rectangle_bounds.height>obstacle.top))
            {
                this->move((float)-speed_*dir_x_*time,0);
                weapon_eq.move((float)-speed_*dir_x_*time,0);
                dir_x_=0;
            }
        }

    }
    if(dir_x_==-1)
    {
        weapon_place_l();
        if(rectangle_bounds.left<bound_x_left_)
        {
            this->move((float)-speed_*dir_x_*time,0);
            weapon_eq.move((float)-speed_*dir_x_*time,0);
            dir_x_=0;
        }
        for(auto &obstacle : ObstacleColisions_)
        {
            if(rectangle_bounds.left<obstacle.left+obstacle.width && rectangle_bounds.left>obstacle.left
                    &&(rectangle_bounds.top<obstacle.top||rectangle_bounds.top<obstacle.top+obstacle.height)
                    &&(rectangle_bounds.top+rectangle_bounds.height>obstacle.top+obstacle.height||rectangle_bounds.top+rectangle_bounds.height>obstacle.top))
            {
                this->move((float)-speed_*dir_x_*time,0);
                weapon_eq.move((float)-speed_*dir_x_*time,0);
                dir_x_=0;
            }
        }

    }

};
void PlayerClass::gravity(const sf::Time &elapsed)
{
    float time = elapsed.asSeconds();
    sf::FloatRect rectangle_bounds = this->getGlobalBounds();

          if(rectangle_bounds.top+rectangle_bounds.height+100*time>(float)32*21)
            {
               this->setPosition(this->getGlobalBounds().left,(float)32*21-this->getGlobalBounds().height);
              weapon_eq.setPosition(weapon_eq.getGlobalBounds().left,this->getGlobalBounds().top-10);
            }
          else
          {
              this->move(0,(float)100*time);
              weapon_eq.move(0,(float)100*time);
          }
            for(auto &obstacle : ObstacleColisions_)
            {
                if(rectangle_bounds.top+rectangle_bounds.height+100*time>obstacle.top && rectangle_bounds.top+rectangle_bounds.height+100*time<obstacle.top+obstacle.height&&(rectangle_bounds.left<obstacle.left||rectangle_bounds.left<obstacle.left+obstacle.width)&&(rectangle_bounds.left+rectangle_bounds.width>obstacle.left+obstacle.width||rectangle_bounds.left+rectangle_bounds.width>obstacle.left))
                {
//                    this->move(0,(float)-200*time);
//                    weapon_eq.move(0,(float)-200*time);
                    this->setPosition(this->getGlobalBounds().left,obstacle.top-this->getGlobalBounds().height);
                   weapon_eq.setPosition(weapon_eq.getGlobalBounds().left,this->getGlobalBounds().top-10);
                }
            }
}
int PlayerClass::health()
{
    return health_;
};
int PlayerClass::health_max()
{
    return health_max_;
}
void PlayerClass::addHp(int bonus)
{
    health_+=bonus;
    health_max_+=bonus;
}
int PlayerClass::dmg()
{
    return dmg_;
};
void PlayerClass::adddmg(int bonus)
{
    dmg_+=bonus;
}
int PlayerClass::speed()
{
    return speed_;
};
void PlayerClass::addspeed(int bonus)
{
    speed_+=bonus;
}
int PlayerClass::armour()
{
    return armour_;
};
void PlayerClass::addarmour(int bonus)
{
    armour_+=bonus;
}
void PlayerClass::heal(int bonus)
{
    if(health_+bonus>=health_max_)
    {
        health_=health_max_;
    }
    else
    {
        health_+=bonus;
    }
}
void PlayerClass::weapon_place_r()
{
    this->weapon_eq.setPosition(this->getGlobalBounds().width+this->getGlobalBounds().left-5,this->getGlobalBounds().top-10);
}
void PlayerClass::weapon_place_l()
{
    this->weapon_eq.setPosition(this->getGlobalBounds().left-10,this->getGlobalBounds().top-10);
}
