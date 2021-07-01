#include "item.h"

Item::Item()
{



   std::string descript;
taken_=false;
int type = rand() % 5;
switch(type)
{
case 0:
{
    if (!Texture.loadFromFile("health.png"))
    {
    }
    this->setTexture(Texture);
    hp_=50;
    dmg_=0;
    armour_=0;
    speed_=0;
    heal_=0;
    descript = "Health + "+std::to_string(hp_);
    Description.setString(descript);
    break;
}
case 1:
{
    if (!Texture.loadFromFile("dmg.png"))
    {
    }
    this->setTexture(Texture);
    hp_=0;
    dmg_=15;
    armour_=0;
    speed_=0;
    heal_=0;
    descript = "Damage + "+std::to_string(dmg_);
    Description.setString(descript);
    break;
}
case 2:
{
    if (!Texture.loadFromFile("armour.png"))
    {
    }
    this->setTexture(Texture);
    hp_=0;
    dmg_=0;
    armour_=10;
    speed_=0;
    heal_=0;
    descript = "Armour + "+std::to_string(armour_);
    Description.setString(descript);
    break;
}
case 3:
{
    if (!Texture.loadFromFile("speed.png"))
    {
    }
    this->setTexture(Texture);
    hp_=0;
    dmg_=0;
    armour_=0;
    speed_=20;
    heal_=0;
    descript = "Speed + "+std::to_string(speed_);
    Description.setString(descript);
    break;
}
case 4:
{
    if (!Texture.loadFromFile("heal.png"))
    {
    }
    this->setTexture(Texture);
    hp_=0;
    dmg_=0;
    armour_=0;
    speed_=0;
    heal_=70;
    descript = "Heal + "+std::to_string(heal_);
    Description.setString(descript);
    break;
}
}
this->setScale(0.5,0.5);



}
int Item::hp(){
    return hp_;
}
int Item::heal(){
    return heal_;
}
int Item::dmg(){
    return dmg_;
}
int Item::speed(){
    return speed_;
}
int Item::armour(){
    return armour_;
}
void Item::take()
{
    taken_=!taken_;
}
bool Item::taken()
{
    return taken_;
}
int Item::room_number()
{
    return room_number_;
}
void Item::room_number_set(unsigned long long number)
{
    room_number_=number;
}
