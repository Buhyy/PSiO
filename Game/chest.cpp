#include "chest.h"

chest::chest()
{
    if (!Texture1.loadFromFile("skrzynia1.png"))
    {
    }
    if (!Texture2.loadFromFile("skrzynia2.png"))
    {
    }
    this->setTexture(Texture1);
    clossed_=true;
   //this->setPosition(200,200);

}
int chest::room_number()
{
    return room_number_;
}
void chest::room_number_set(unsigned long long number)
{
    room_number_=number;
}
void chest::open()
{
    clossed_=false;
    this->setTexture(Texture2);

}
bool chest::is_oppened()
{
    return clossed_;
}
