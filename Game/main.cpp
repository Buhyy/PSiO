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
#include "Functions.h"
int main()
{
    // create the window
    srand(time(NULL));
  //  int Sx=1000, Sy=800;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "My window");//sf::Style::Fullscreen

//sf::Clock clock;



    PlayerClass player;
    //Enemy enemy;
    std::vector<std::unique_ptr<Character>> enemies;
    std::vector<std::unique_ptr<Item>> items;
    std::vector<std::unique_ptr<chest>> chests;


    weapon sword;
    player.weapon_eq=sword;
    player.setPosition(100,100);
    player.weapon_place_r();



    sf::Texture SkyTexture;
    if (!SkyTexture.loadFromFile("sky.png")) {
        std::cout << "something wrong" << std::endl;
    }
    sf::Sprite SkySprite;
    SkySprite.setTexture(SkyTexture);
    sf::Texture WallTexture;
    if (!WallTexture.loadFromFile("wall.png")) {
        std::cout << "something wrong" << std::endl;
    }

    sf::Sprite WallSprite;
    WallSprite.setTexture(WallTexture);
    sf::Texture DirtTexture;
    if (!DirtTexture.loadFromFile("dirt.png")) {
        std::cout << "something wrong" << std::endl;
    }

    sf::Sprite DirtSprite;
    DirtSprite.setTexture(DirtTexture);

    sf::Texture PlayerTexture;
    if (!PlayerTexture.loadFromFile("Patatek.png")) {
        std::cout << "something wrong" << std::endl;
    }
    player.setTexture(PlayerTexture);
    sf::Texture DoorTexture;
    if (!DoorTexture.loadFromFile("Doorpng.png")) {
        std::cout << "something wrong" << std::endl;
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
   for(int i = 0;i<=Rooms.size();i++)
   {
     chests.emplace_back(std::make_unique<chest>());
     chests[i]->setPosition(200,200);
     chests[i]->room_number_set(i);
    }//itemik.setPosition(this->getGlobalBounds().left+this->getGlobalBounds().width/2,this->getGlobalBounds().top);
   for(int i = 0;i<=Rooms.size();i++)
   {
     items.emplace_back(std::make_unique<Item>());
     items[i]->setPosition(200,200);
     items[i]->room_number_set(i);
     chests[i]->itemik=*items[i];
     chests[i]->itemik.setPosition(chests[i]->getGlobalBounds().left+chests[i]->getGlobalBounds().width/2,chests[i]->getGlobalBounds().top);
    }
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
                                 player.weapon_place_r();
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
                                 player.weapon_place_l();
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


                                if(chests[Curent_Room_Number]->is_oppened()&& !Rooms[Curent_Room_Number].is_cleared() && (pow(((player.getGlobalBounds().left+(player.getGlobalBounds().width/2))-(chests[Curent_Room_Number]->getGlobalBounds().left+(chests[Curent_Room_Number]->getGlobalBounds().width/2))),2)+pow((player.getGlobalBounds().top+(player.getGlobalBounds().height/2))-(chests[Curent_Room_Number]->getGlobalBounds().top+(chests[Curent_Room_Number]->getGlobalBounds().height/2)),2))<100)
                                {
                                    chests[Curent_Room_Number]->open();
                                    std::cout<<"open";
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
//           for(int i=0; i<Rooms.size(); i++)
//           {
//            if(!chests[i]->is_oppened() && Curent_Room_Number==i &&!items[i]->taken()&&(pow(((player.getGlobalBounds().left+(player.getGlobalBounds().width/2))-(items[i]->getGlobalBounds().left+(items[i]->getGlobalBounds().width/2))),2)+pow((player.getGlobalBounds().top+(player.getGlobalBounds().height/2))-(items[i]->getGlobalBounds().top+(items[i]->getGlobalBounds().height/2)),2))<70)
//            {
//                items[i]->take();
//                player.addHp(items[i]->hp());
//                player.adddmg(items[i]->dmg());
//                player.addarmour(items[i]->armour());
//                player.heal(items[i]->heal());
//                player.addspeed(items[i]->speed());
//            }
//           }
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
           for(auto &chest : chests)
           {
               if(chest->room_number()==Curent_Room_Number)
               {
               //enemy->animate(elapsed);
               window.draw(*chest);
//               if(!chest->is_oppened() && !chest->itemik.taken())
//               {
//                   window.draw(chest->itemik);
//               }
              }
           }
           for(int i=0; i<Rooms.size(); i++)
           {
            if(!chests[i]->is_oppened() && Curent_Room_Number==i &&!items[i]->taken()&&(pow(((player.getGlobalBounds().left+(player.getGlobalBounds().width/2))-(items[i]->getGlobalBounds().left+(items[i]->getGlobalBounds().width/2))),2)+pow((player.getGlobalBounds().top+(player.getGlobalBounds().height/2))-(items[i]->getGlobalBounds().top+(items[i]->getGlobalBounds().height/2)),2))<70)
            {
                items[i]->take();
                player.addHp(items[i]->hp());
                player.adddmg(items[i]->dmg());
                player.addarmour(items[i]->armour());
                player.heal(items[i]->heal());
                player.addspeed(items[i]->speed());
            }
            if(!chests[i]->is_oppened() && Curent_Room_Number==i &&!items[i]->taken())
                window.draw(*items[i]);
           }

           // enemy.gravity(elapsed);
           window.draw(player);
           window.draw(player.weapon_eq);
           hud(window,player);
           window.display();

           //std::cout<<player.getOrigin().x<<std::endl<<player.getOrigin().y<<std::endl;
}
    return 0;
}
