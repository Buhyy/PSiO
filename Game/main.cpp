#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <vector>
//#include "playerclass.h"

class PlayerClass : public sf::Sprite
{
public:
    PlayerClass(){


    };
    void setDir_x(float D_x){dir_x_=D_x;}
    void setDir_y(float D_y){dir_y_=D_y;}
    void setObstacleColisions( std::vector<sf::FloatRect> obstacle_colisions){ObstacleColisions_=obstacle_colisions;}
    void jump(const sf::Time &elapsed)
    {
        Time_+=elapsed.asSeconds();
        if(Time_<0.3)
        {
           this->move(0,(float)-400*elapsed.asSeconds());
        }
        else
        {
            Time_=0;
            dir_y_=0;
        }
    }
    void animate(const sf::Time &elapsed){
        sf::FloatRect rectangle_bounds = this->getGlobalBounds();
        float time = elapsed.asSeconds();
        this->move((float)200*dir_x_*time,0);


        // poruszanie po y
        if(dir_y_==1)
        {
            if(rectangle_bounds.top+rectangle_bounds.height>bound_y_bottm_)
            {
            this->move(0,(float)-400*dir_y_*time);
           // dir_y_=0;
            }
            for(auto &obstacle : ObstacleColisions_)
            {
                if(rectangle_bounds.top+rectangle_bounds.height>obstacle.top && rectangle_bounds.top+rectangle_bounds.height<obstacle.top+obstacle.height
                        &&(rectangle_bounds.left<obstacle.left||rectangle_bounds.left<obstacle.left+obstacle.width)
                        &&(rectangle_bounds.left+rectangle_bounds.width>obstacle.left+obstacle.width||rectangle_bounds.left+rectangle_bounds.width>obstacle.left))
                {
                    this->move(0,(float)-400*dir_y_*time);
                   // dir_y_=0;
                }
            }

        }
        if(dir_y_==-1)
        {
            if(floor_check_)this->jump(elapsed);
            if(rectangle_bounds.top<bound_y_top_)
            {
                this->move(0,(float)-600*dir_y_*time);
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
                    dir_y_=0;
                    Time_=0;
                }
            }

        }



        //poruszanie po x
        if(dir_x_==1)
        {   if(rectangle_bounds.left+rectangle_bounds.width>bound_x_right_)
            {
            this->move((float)-250*dir_x_*time,0);

           // dir_x_=0;
            }
            for(auto &obstacle : ObstacleColisions_)
            {
                if(rectangle_bounds.left+rectangle_bounds.width>obstacle.left && rectangle_bounds.left+rectangle_bounds.width<obstacle.left+obstacle.width
                        &&(rectangle_bounds.top<obstacle.top||rectangle_bounds.top<obstacle.top+obstacle.height)
                        &&(rectangle_bounds.top+rectangle_bounds.height>obstacle.top+obstacle.height||rectangle_bounds.top+rectangle_bounds.height>obstacle.top))
                {
                    this->move((float)-250*dir_x_*time,0);

                   // dir_x_=0;
                }
            }

        }
        if(dir_x_==-1)
        {
            if(rectangle_bounds.left<bound_x_left_)
            {
                this->move((float)-250*dir_x_*time,0);
               // dir_x_=0;
            }
            for(auto &obstacle : ObstacleColisions_)
            {
                if(rectangle_bounds.left<obstacle.left+obstacle.width && rectangle_bounds.left>obstacle.left
                        &&(rectangle_bounds.top<obstacle.top||rectangle_bounds.top<obstacle.top+obstacle.height)
                        &&(rectangle_bounds.top+rectangle_bounds.height>obstacle.top+obstacle.height||rectangle_bounds.top+rectangle_bounds.height>obstacle.top))
                {
                    this->move((float)-250*dir_x_*time,0);
                  //  dir_x_=0;
                }
            }

        }

    };
private:
    float Time_=0;
    float dir_x_=0;
    float dir_y_=0;
    sf::Vector2f position_;
    sf::Vector2f size_;
    std::vector<sf::FloatRect> ObstacleColisions_;
    float bound_x_left_=32;
    float bound_x_right_=32*31;
    float bound_y_top_=32;
    float bound_y_bottm_=32*21;
    bool floor_check_=true;

};
void gravity( PlayerClass &player,const sf::Time &elapsed,std::vector<sf::FloatRect> ObstacleColisions)
{
    float time = elapsed.asSeconds();
    sf::FloatRect rectangle_bounds = player.getGlobalBounds();
        player.move(0,(float)100*time);
          if(rectangle_bounds.top+rectangle_bounds.height>(float)32*21)
            {
            player.move(0,(float)-200*time);
            }
            for(auto &obstacle : ObstacleColisions)
            {
                if(rectangle_bounds.top+rectangle_bounds.height>obstacle.top && rectangle_bounds.top+rectangle_bounds.height<obstacle.top+obstacle.height
                        &&(rectangle_bounds.left<obstacle.left||rectangle_bounds.left<obstacle.left+obstacle.width)
                        &&(rectangle_bounds.left+rectangle_bounds.width>obstacle.left+obstacle.width||rectangle_bounds.left+rectangle_bounds.width>obstacle.left))
                {
                    player.move(0,(float)-200*time);
                }
            }
}
class RoomClass
{
public:
    RoomClass(int type){
        switch(type)
        {
        case 1:
        {
            std::vector<int> layer = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,3,3};
            std::vector<int> layer2 = {3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,3};
            std::vector<int> layer3 = {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3};
            layout_.emplace_back(layer);
            for(int i=0;i<10;i++)//
            {
                layout_.emplace_back(layer3);
            }
            for(int i=0;i<1;i++)//
            {

               layout_.emplace_back(layer2);
            }
            for(int i=0;i<19;i++)//
            {

               layout_.emplace_back(layer3);
            }
            layout_.emplace_back(layer);
            break;
        }

        case 2:
        {
             std::vector<int>layer = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
             std::vector<int>layer3 = {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3};
            layout_.emplace_back(layer);
            for(int i=0;i<30;i++)//
            {
                layout_.emplace_back(layer3);
            }
            layout_.emplace_back(layer);
            break;
        }
        case 3:
        {
             std::vector<int>layer = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
             std::vector<int>layer2 = {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3};
             std::vector<int>layer3 = {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3};
            layout_.emplace_back(layer);
            for(int i=0;i<10;i++)//
            {
                layout_.emplace_back(layer3);
            }
            for(int i=0;i<10;i++)//
            {
                layout_.emplace_back(layer2);
            }
            for(int i=0;i<10;i++)//
            {
                layout_.emplace_back(layer3);
            }
            layout_.emplace_back(layer);
            break;
        }
        }
    }
    std::vector<std::vector<int>> layout(){return layout_;}
    bool is_cleared(){return is_cleared_;}
    void set_is_cleared(){is_cleared_=true;}
private:
    std::vector<std::vector<int>> layout_;
    bool is_cleared_=false;

};
int main()
{
    // create the window
    srand(time(NULL));
  //  int Sx=1000, Sy=800;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "My window");//sf::Style::Fullscreen

//sf::Clock clock;
//sf::String playerInput="dziala";
//sf::Text playerText;
//playerText.setString(playerInput);
//playerText.setPosition(100,100);
//playerText.setCharacterSize(10);
//playerText.setColor(sf::Color::Black);
//sf::Font arial;
//arial.loadFromFile("arial.ttf");
//playerText.setFont(arial);
//sf::Font font;

    PlayerClass player;
    player.setPosition(100,600);
    sf::Texture SkyTexture;
    if (!SkyTexture.loadFromFile("sky.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite SkySprite;
    SkySprite.setTexture(SkyTexture);
    sf::Texture WallTexture;
    if (!WallTexture.loadFromFile("wall.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite WallSprite;
    WallSprite.setTexture(WallTexture);
    sf::Texture DirtTexture;
    if (!DirtTexture.loadFromFile("dirt.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite DirtSprite;
    DirtSprite.setTexture(DirtTexture);

    sf::Texture PlayerTexture;
    if (!PlayerTexture.loadFromFile("Patatek.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    player.setTexture(PlayerTexture);
    sf::Texture DoorTexture;
    if (!DoorTexture.loadFromFile("Doorpng.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite DoorSprite;
    DoorSprite.setTexture(DoorTexture);


    std::vector<sf::Vector2f> ObstaclesPositions;
    std::vector<sf::FloatRect> ObstacleColisions;
    RoomClass room1(1),room2(2),room3(3);
    std::vector<RoomClass> Rooms;
    Rooms.emplace_back(room1);
    Rooms.emplace_back(room2);
    Rooms.emplace_back(room3);
    int Curent_Room_Number=0;
    for(int i=1;i<Rooms[Curent_Room_Number].layout().size()-1;i++)
    {

            for(int j =1; j<Rooms[Curent_Room_Number].layout()[i].size()-1;j++)
            {
                sf::Vector2f obstacle_position = {float(i*32) ,float(j*32)};
                if(Rooms[Curent_Room_Number].layout()[i][j]==3)
                {
                    ObstaclesPositions.emplace_back(obstacle_position);
                    sf::FloatRect PositionRect(obstacle_position.x,obstacle_position.y,32,32);
                    ObstacleColisions.emplace_back(PositionRect);
                }


            }
     }
player.setObstacleColisions(ObstacleColisions);
          sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        sf::Event event;


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                               player.setDir_y(-1);
                            }
                    if (event.key.code == sf::Keyboard::Down) {
                             //  player.setDir_y(1);
                           }
                    if (event.key.code == sf::Keyboard::Left) {
                               player.setDir_x(-1);
                    }
                    if (event.key.code == sf::Keyboard::Right) {
                               player.setDir_x(1);
                           }
                    if (event.key.code == sf::Keyboard::E) {
                               if(player.getGlobalBounds().left+player.getGlobalBounds().width>900)
                               {
                                   if(Curent_Room_Number<Rooms.size()-1)
                                   {
                                 Curent_Room_Number++;
                                 player.setPosition(70,610);
                                 ObstacleColisions.clear();
                                 ObstaclesPositions.clear();
                                 for(int i=1;i<Rooms[Curent_Room_Number].layout().size()-1;i++)
                                 {

                                         for(int j =1; j<Rooms[Curent_Room_Number].layout()[i].size()-1;j++)
                                         {
                                             sf::Vector2f obstacle_position = {float(i*32) ,float(j*32)};
                                             if(Rooms[Curent_Room_Number].layout()[i][j]==3)
                                             {
                                                 ObstaclesPositions.emplace_back(obstacle_position);
                                                 sf::FloatRect PositionRect(obstacle_position.x,obstacle_position.y,32,32);
                                                 ObstacleColisions.emplace_back(PositionRect);
                                             }


                                         }
                                  }
                             player.setObstacleColisions(ObstacleColisions);
                                   }
                                }
                               if(player.getGlobalBounds().left<60)
                               {
                                   if(Curent_Room_Number>0)
                                   {
                                 Curent_Room_Number--;
                                 player.setPosition(980,610);
                                 ObstacleColisions.clear();
                                 ObstaclesPositions.clear();
                                 for(int i=1;i<Rooms[Curent_Room_Number].layout().size()-1;i++)
                                 {

                                         for(int j =1; j<Rooms[Curent_Room_Number].layout()[i].size()-1;j++)
                                         {
                                             sf::Vector2f obstacle_position = {float(i*32) ,float(j*32)};
                                             if(Rooms[Curent_Room_Number].layout()[i][j]==3)
                                             {
                                                 ObstaclesPositions.emplace_back(obstacle_position);
                                                 sf::FloatRect PositionRect(obstacle_position.x,obstacle_position.y,32,32);
                                                 ObstacleColisions.emplace_back(PositionRect);
                                             }


                                         }
                                  }
                             player.setObstacleColisions(ObstacleColisions);
                                   }
                                }
                            }
                }
            if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Up) {

                               //player.setDir_y(0);
                       }

                    if (event.key.code == sf::Keyboard::Down) {
                              player.setDir_y(0);
                    }
                    if (event.key.code == sf::Keyboard::Left) {
                                player.setDir_x(0);
                           }

                    if (event.key.code == sf::Keyboard::Right) {
                               player.setDir_x(0);

                    }
                }
        }


        window.clear(sf::Color::White);
        //   window.draw(playerText);
           for(int i=0;i<Rooms[Curent_Room_Number].layout().size();i++)
           {
                   for(int j =0; j<Rooms[Curent_Room_Number].layout()[i].size();j++)
                   {
                       if(i==0 || i==Rooms[Curent_Room_Number].layout().size()-1 || j==0 || j==Rooms[Curent_Room_Number].layout()[i].size()-1)
                       {
                           WallSprite.setPosition(float(i*32) ,float(j*32));
                           WallSprite.setScale(0.5,0.5);
                           window.draw(WallSprite);
                       }
                       else
                       {
                       SkySprite.setPosition(float(i*32) ,float(j*32));
                       SkySprite.setScale(0.5,0.5);
                       window.draw(SkySprite);
                       }
                   }
            }
           for(auto &obstacle : ObstaclesPositions)
           {
               WallSprite.setPosition(obstacle);
               WallSprite.setScale(0.5,0.5);
               window.draw(WallSprite);
           }

           DoorSprite.setPosition(992,608);
           window.draw(DoorSprite);
           DoorSprite.setPosition(0,608);
           window.draw(DoorSprite);
           player.animate(elapsed);
           gravity(player,elapsed,ObstacleColisions);
           //player.move(0,(float)100*elapsed.asSeconds());
           window.draw(player);
           window.display();
}
    return 0;
}