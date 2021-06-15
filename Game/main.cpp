#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <vector>
#include "playerclass.h"
#include "character.h"
#include "room.h"
#include "enemy.h"
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
    Enemy enemy;
    player.setPosition(100,100);
    enemy.setPosition(200,200);
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
    Room room1(1),room2(2),room3(3);
    std::vector<Room> Rooms;
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
           player.gravity(elapsed);
           enemy.setTarget(sf::Vector2f(player.getGlobalBounds().left+(player.getGlobalBounds().width/2),player.getGlobalBounds().top+(player.getGlobalBounds().height/2)));
           enemy.animate(elapsed);
          // enemy.gravity(elapsed);
           //player.move(0,(float)100*elapsed.asSeconds());
           window.draw(enemy);
           window.draw(player);
           window.display();

           //std::cout<<player.getOrigin().x<<std::endl<<player.getOrigin().y<<std::endl;
}
    return 0;
}
