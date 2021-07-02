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
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(32*32+300,32*22), "Dungreed--", sf::Style::Titlebar | sf::Style::Close);//sf::Style::Fullscreen
    sf::Image icon;
    icon.loadFromFile("logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    PlayerClass player;
    std::vector<std::unique_ptr<Character>> enemies;
    std::vector<std::unique_ptr<Item>> items;
    std::vector<std::unique_ptr<chest>> chests;

    weapon sword;
    player.weapon_eq=sword;
    player.setPosition(100,window.getSize().y-32-player.getGlobalBounds().height);
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


    for(unsigned long long i=0;i<6;i++)
    {
        if(i==0)
        {
            Room room1(2);
            Rooms.emplace_back(room1);
            Rooms[i].set_is_cleared();
        }
        if(i==5)
        {
            Room room1(7);
            Rooms.emplace_back(room1);

        }
        else
        {
        int variant=rand() % 6+1;
        Room room1(variant);//
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

   for(unsigned long long i = 1;i<=Rooms.size()-1;i++)
   {
       switch(Rooms[i].variant())
       {
       case 1:
       {
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4]->setPosition(32*4,32*7);
           enemies[(i-1)*4]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+1]->setPosition(32*28,32*7);
           enemies[(i-1)*4+1]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+2]->setPosition(32*15,32*4);
           enemies[(i-1)*4+2]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+3]->setPosition(32*15,32*13);
           enemies[(i-1)*4+3]->room_number_set(i);
           break;
       }
       case 2:
       {
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4]->setPosition(32*5,32*4);
           enemies[(i-1)*4]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4+1]->setPosition(32*12,32*4);
           enemies[(i-1)*4+1]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4+2]->setPosition(32*19,32*4);
           enemies[(i-1)*4+2]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4+3]->setPosition(32*27,32*4);
           enemies[(i-1)*4+3]->room_number_set(i);
           break;
       }
       case 3:
       {
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4]->setPosition(32*5,32*4);
           enemies[(i-1)*4]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+1]->setPosition(32*14,32*9);
           enemies[(i-1)*4+1]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+2]->setPosition(32*17,32*9);
           enemies[(i-1)*4+2]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4+3]->setPosition(32*27,32*4);
           enemies[(i-1)*4+3]->room_number_set(i);
           break;
       }
       case 4:
       {
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4]->setPosition(32*5,32*4);
           enemies[(i-1)*4]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4+1]->setPosition(32*12,32*4);
           enemies[(i-1)*4+1]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4+2]->setPosition(32*19,32*4);
           enemies[(i-1)*4+2]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(1));
           enemies[(i-1)*4+3]->setPosition(32*27,32*4);
           enemies[(i-1)*4+3]->room_number_set(i);
           break;
       }
       case 5:
       {
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4]->setPosition(32*4,32*7);
           enemies[(i-1)*4]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+1]->setPosition(400,200);
           enemies[(i-1)*4+1]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+2]->setPosition(300,200);
           enemies[(i-1)*4+2]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+3]->setPosition(200,32*7);
           enemies[(i-1)*4+3]->room_number_set(i);
           break;
       }
       case 6:
       {
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4]->setPosition(32*5,32*14);
           enemies[(i-1)*4]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+1]->setPosition(32*27,32*14);
           enemies[(i-1)*4+1]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+2]->setPosition(32*15,32*4);
           enemies[(i-1)*4+2]->room_number_set(i);
           enemies.emplace_back(std::make_unique<Enemy>(2));
           enemies[(i-1)*4+3]->setPosition(32*15,32*19);
           enemies[(i-1)*4+3]->room_number_set(i);
           break;
       case 7:
       {
           enemies.emplace_back(std::make_unique<Enemy>(3));
           enemies[(i-1)*4]->setPosition(32*15,32*10);
           enemies[(i-1)*4]->room_number_set(i);
           break;
       }
       }
       }

   }
   for(auto &enemy: enemies)
   {
       enemy->setObstacleColisions(ObstacleColisions);
   }
   for(unsigned long long i = 0;i<=Rooms.size()-1;i++)
   {
     chests.emplace_back(std::make_unique<chest>());
     switch(Rooms[i].variant())
     {
     case 1:
     {
         chests[i]->setPosition(15*32,15*32);
         break;
     }
     case 2:
     {
         chests[i]->setPosition(15*32,20*32);
         break;
     }
     case 3:
     {
         chests[i]->setPosition(15*32,10*32);
         break;
     }
     case 4:
     {
         chests[i]->setPosition(17*32,20*32);
         break;
     }
     case 5:
     {
         chests[i]->setPosition(15*32,10*32);
         break;
     }
     case 6:
     {
         chests[i]->setPosition(15*32,6*32);
         break;
     }
     case 7:
     {
         chests[i]->setPosition(15*32,20*32);
         break;
     }
     }


     chests[i]->room_number_set(i);
    }
       sf::Font arial;
       arial.loadFromFile("arial.TTF");

   for(unsigned long long i = 0;i<=Rooms.size()-1;i++)
   {
     items.emplace_back(std::make_unique<Item>());
     items[i]->setPosition(chests[i]->getGlobalBounds().left+chests[i]->getGlobalBounds().width/2-items[i]->getGlobalBounds().width/2,chests[i]->getGlobalBounds().top-items[i]->getGlobalBounds().height*1.5);
     items[i]->room_number_set(i);
     chests[i]->itemik=*items[i];
     chests[i]->itemik.setPosition(chests[i]->getGlobalBounds().left+chests[i]->getGlobalBounds().width/2,chests[i]->getGlobalBounds().top);
     chests[i]->itemik.Description.setPosition(chests[i]->itemik.getGlobalBounds().left+chests[i]->itemik.getGlobalBounds().width/2-chests[i]->itemik.Description.getGlobalBounds().width/2,chests[i]->itemik.getGlobalBounds().top-40);
     chests[i]->itemik.Description.setCharacterSize(10);
     chests[i]->itemik.Description.setColor(sf::Color::Black);
     chests[i]->itemik.Description.setFont(arial);
    }

    sf::Clock clock;
    float timer_atack=0,imune_time=0;


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
                             for(auto &enemy: enemies)
                             {
                                 enemy->setObstacleColisions(ObstacleColisions);
                             }
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
                             for(auto &enemy: enemies)
                             {
                                 enemy->setObstacleColisions(ObstacleColisions);
                             }
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
        if(player.health()>0)
        {
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
            if(imune_time==0 && !enemies[i]->is_dead() &&enemies[i]->room_number()==Curent_Room_Number&&(pow(((player.getGlobalBounds().left+(player.getGlobalBounds().width/2))-(enemies[i]->getGlobalBounds().left+(enemies[i]->getGlobalBounds().width/2))),2)+pow((player.getGlobalBounds().top+(player.getGlobalBounds().height/2))-(enemies[i]->getGlobalBounds().top+(enemies[i]->getGlobalBounds().height/2)),2))<(enemies[i]->getGlobalBounds().width+enemies[i]->getGlobalBounds().height)*7)
            {
                player.get_hurt(enemies[i]->dmg()-enemies[i]->dmg()*player.armour()/100);
                imune_time+=elapsed.asSeconds();
            }
        }
        if(imune_time!=0)
        {
            imune_time+=elapsed.asSeconds();
            if(imune_time>0.5)
            {
                imune_time=0;
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
               enemy->gravity(elapsed);
               window.draw(*enemy);
               }
           }
           for(auto &chest : chests)
           {
               if(chest->room_number()==Curent_Room_Number)
               {
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
            {
                window.draw(*items[i]);
                window.draw(chests[i]->itemik.Description);
            }
           }


           if(Curent_Room_Number==0)
           {
               Tutorial(window);
           }
           hud(window,player);
           window.draw(player);
           window.draw(player.weapon_eq);
           player.weapon_eq.atack(timer_atack,elapsed.asSeconds());
           unsigned long long win_chceck=0;
           if(win_chceck==0)
           {
           for(unsigned long long i=0; i<Rooms.size();i++)
           {
               if(Rooms[i].is_cleared())
               {
                   win_chceck++;
               }
           }
           }
           if(win_chceck==Rooms.size())
           {
               std::string wins="You Won !";
               sf::Text wint;
               wint.setString(wins);
               wint.setPosition(32*8,32*10);
               wint.setFont(arial);
               wint.setCharacterSize(60);
               window.draw(wint);
           }
           else
           {
               win_chceck=0;
           }
        }
        if(player.health()<=0)
        {
            sf::RectangleShape end(sf::Vector2f(window.getSize().x, window.getSize().y));
            end.setPosition(0,0);
            end.setFillColor(sf::Color::Black);
            window.draw(end);
            std::string ends="Game Over !";
            sf::Text endt;
            endt.setString(ends);
            endt.setPosition(32*12,32*10);
            endt.setFont(arial);
            endt.setCharacterSize(60);
            window.draw(endt);

        }
           window.display();


}
    return 0;
}
