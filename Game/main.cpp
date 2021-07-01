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
    sf::RenderWindow window(sf::VideoMode(32*32+300,32*22), "Dungreed--", sf::Style::Titlebar | sf::Style::Close);//sf::Style::Fullscreen
    sf::Image icon;
    icon.loadFromFile("logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
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

    for(unsigned long long i=0;i<11;i++)
    {
        if(i==0)
        {
            Room room1(3);
            Rooms.emplace_back(room1);
            Rooms[i].set_is_cleared();
        }
        else
        {
        int variant=rand() % 3+1;
        Room room1(variant);
        Rooms.emplace_back(room1);
        }
    }

    unsigned long long Curent_Room_Number=0;
    for(unsigned long long i=1;i<Rooms[Curent_Room_Number].layout().size()-1;i++)
    {
            for(unsigned long long j =1; j<Rooms[Curent_Room_Number].layout()[i].size()-1;j++)
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

   for(unsigned long long i = 0;i<=Rooms.size()-1;i++)
   {
     enemies.emplace_back(std::make_unique<Enemy>());
     enemies[i*3]->setPosition(200,200);
     enemies[i*3]->room_number_set(i+1);
     enemies.emplace_back(std::make_unique<Enemy>());
     enemies[i*3+1]->setPosition(400,200);
     enemies[i*3+1]->room_number_set(i+1);
     enemies.emplace_back(std::make_unique<Enemy>());
     enemies[i*3+2]->setPosition(300,200);
     enemies[i*3+2]->room_number_set(i+1);
   }
   for(unsigned long long i = 0;i<=Rooms.size()-1;i++)
   {
     chests.emplace_back(std::make_unique<chest>());
     chests[i]->setPosition(15*32,20*32);
     chests[i]->room_number_set(i);
    }
   for(unsigned long long i = 0;i<=Rooms.size()-1;i++)
   {
     items.emplace_back(std::make_unique<Item>());
     items[i]->setPosition(15*32,18*32);
     items[i]->room_number_set(i);
     chests[i]->itemik=*items[i];
     chests[i]->itemik.setPosition(chests[i]->getGlobalBounds().left+chests[i]->getGlobalBounds().width/2,chests[i]->getGlobalBounds().top);
    }
    sf::Clock clock;
    float timer_atack=0;
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
                    if (event.key.code == sf::Keyboard::Left) {
                               player.setDir_x(-1);
                    }
                    if (event.key.code == sf::Keyboard::Right) {
                               player.setDir_x(1);
                           }
                    if (event.key.code == sf::Keyboard::E) {
                               if(Rooms[Curent_Room_Number].is_cleared())
                               {
                               if(player.getGlobalBounds().left+player.getGlobalBounds().width>900)
                               {
                                   if(Curent_Room_Number<Rooms.size()-1)
                                   {
                                 Curent_Room_Number++; 
                                 player.setPosition(70,610);
                                 player.weapon_place_r();
                                 ObstacleColisions.clear();
                                 ObstaclesPositions.clear();
                                 for(unsigned long long i=1;i<Rooms[Curent_Room_Number].layout().size()-1;i++)
                                 {
                                         for(unsigned long long j =1; j<Rooms[Curent_Room_Number].layout()[i].size()-1;j++)
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
                                 player.weapon_place_l();
                                 ObstacleColisions.clear();
                                 ObstaclesPositions.clear();
                                 for(unsigned long long i=1;i<Rooms[Curent_Room_Number].layout().size()-1;i++)
                                 {
                                         for(unsigned long long j =1; j<Rooms[Curent_Room_Number].layout()[i].size()-1;j++)
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
                                if(chests[Curent_Room_Number]->is_oppened()&& (pow(((player.getGlobalBounds().left+(player.getGlobalBounds().width/2))-(chests[Curent_Room_Number]->getGlobalBounds().left+(chests[Curent_Room_Number]->getGlobalBounds().width/2))),2)+pow((player.getGlobalBounds().top+(player.getGlobalBounds().height/2))-(chests[Curent_Room_Number]->getGlobalBounds().top+(chests[Curent_Room_Number]->getGlobalBounds().height/2)),2))<100)
                                {
                                    chests[Curent_Room_Number]->open();
                                }
                            }
                       }
                    if (event.key.code == sf::Keyboard::A) {
                        if(!player.weapon_eq.is_atacking())
                        {
                            player.weapon_eq.set_atack();
                        for(unsigned long long i =0 ; i<enemies.size();i++)
                        {
                            if(player.getDix_x()== -1)
                            {
                            if(enemies[i]->room_number()==Curent_Room_Number)
                            {
                            if(enemies[i]->getGlobalBounds().left+enemies[i]->getGlobalBounds().width/2>player.getGlobalBounds().left-75 && (enemies[i]->getGlobalBounds().top+enemies[i]->getGlobalBounds().height/2>player.getGlobalBounds().top-50 &&enemies[i]->getGlobalBounds().top+enemies[i]->getGlobalBounds().height/2<player.getGlobalBounds().top+player.getGlobalBounds().height+50))
                            {
                                enemies[i]->deal_dmg(player.dmg());
                                if(enemies[i]->health()<=0)
                                       {
                                    enemies[i]->kill();
                                }
                            }
                            }
                            }
                            else
                            {
                                if(enemies[i]->room_number()==Curent_Room_Number)
                                {
                                if(enemies[i]->getGlobalBounds().left+enemies[i]->getGlobalBounds().width/2<player.getGlobalBounds().left+player.getGlobalBounds().width+75 && (enemies[i]->getGlobalBounds().top+enemies[i]->getGlobalBounds().height/2>player.getGlobalBounds().top-50 &&enemies[i]->getGlobalBounds().top+enemies[i]->getGlobalBounds().height/2<player.getGlobalBounds().top+player.getGlobalBounds().height+50))
                                {
                                    enemies[i]->deal_dmg(player.dmg());
                                    if(enemies[i]->health()<=0)
                                           {
                                        enemies[i]->kill();
                                    }
                                }
                                }
                            }
                        }
                    }
                    }
                }
            if (event.type == sf::Event::KeyReleased) {

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

        for(unsigned long long i =0;i<enemies.size();i++)
        {
            unsigned long long alive= 0;
            if(Curent_Room_Number == enemies[i]->room_number() && enemies[i]->is_dead())
            {
                alive++;
            }
            if(alive!=0)
            {
                Rooms[Curent_Room_Number].set_is_cleared();
            }
        }
        window.clear(sf::Color::White);

           for(unsigned long long i=0;i<Rooms[Curent_Room_Number].layout().size();i++)
           {
                   for(unsigned long long j =0; j<Rooms[Curent_Room_Number].layout()[i].size();j++)
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
               if(enemy->room_number()==Curent_Room_Number && !enemy->is_dead())
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

              }
           }
           for(unsigned long long i=0; i<Rooms.size(); i++)
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
           player.weapon_eq.atack(timer_atack,elapsed.asSeconds());
           std::cout<<timer_atack<<std::endl;
           if(Curent_Room_Number==0)
           {
               Tutorial(window);
           }
           hud(window,player);
           window.display();


}
    return 0;
}
