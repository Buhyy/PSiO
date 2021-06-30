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
#include "item.h"
#include "chest.h"
#include "weapon.h"
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
    //Enemy enemy;
    std::vector<std::unique_ptr<Character>> enemies;
    std::vector<std::unique_ptr<Item>> items;
    Item health;
    health.setPosition(400,400);
    items.emplace_back(std::make_unique<Item>(health));

    //enemy.setPosition(200,200);


    weapon sword;
    player.weapon_eq=sword;
    player.setPosition(100,100);
    player.weapon_place_r();
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
     std::vector<Room> Rooms;

    for(int i=0;i<10;i++)
    {
        int variant=rand() % 3+1;
        Room room1(variant);
        Rooms.emplace_back(room1);
    }

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

   for(int i = 0;i<=Rooms.size();i++)
   {
     enemies.emplace_back(std::make_unique<Enemy>());
     enemies[i*3]->setPosition(200,200);
     enemies[i*3]->room_number_set(i);
     enemies.emplace_back(std::make_unique<Enemy>());
     enemies[i*3+1]->setPosition(400,200);
     enemies[i*3+1]->room_number_set(i);
     enemies.emplace_back(std::make_unique<Enemy>());
     enemies[i*3+2]->setPosition(300,200);
     enemies[i*3+2]->room_number_set(i);
   }



          sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        sf::Event event;
    std::cout<<player.health()<<std::endl;

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
            if(!health.taken()&&(pow(((player.getGlobalBounds().left+(player.getGlobalBounds().width/2))-(health.getGlobalBounds().left+(health.getGlobalBounds().width/2))),2)+pow((player.getGlobalBounds().top+(player.getGlobalBounds().height/2))-(health.getGlobalBounds().top+(health.getGlobalBounds().height/2)),2))<70)
            {
                health.take();
                player.addHp(health.hp());
            }
           DoorSprite.setPosition(992,608);
           if(Curent_Room_Number!=Rooms.size()-1)
           window.draw(DoorSprite);
           DoorSprite.setPosition(0,608);
           if(Curent_Room_Number!=0)
           window.draw(DoorSprite);
           player.animate(elapsed);
           player.gravity(elapsed);
           for(auto &enemy : enemies)
           {
               enemy->setTarget(sf::Vector2f(player.getGlobalBounds().left+(player.getGlobalBounds().width/2),player.getGlobalBounds().top+(player.getGlobalBounds().height/2)));
               if(enemy->room_number()==Curent_Room_Number && enemy->is_dead()==false)
               {
               enemy->animate(elapsed);
               window.draw(*enemy);
               }
           }

           // window.draw(playerText);
           // enemy.gravity(elapsed);
           //player.move(0,(float)100*elapsed.asSeconds());

           if(!health.taken())
           window.draw(health);

           window.draw(player);
           window.draw(player.weapon_eq);
           window.display();

           //std::cout<<player.getOrigin().x<<std::endl<<player.getOrigin().y<<std::endl;
}
    return 0;
}
