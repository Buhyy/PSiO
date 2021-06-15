#include "item.h"

Item::Item()
{
hp_ = 10;
taken_=false;
if (!Texture.loadFromFile("health.png"))
{
   // std::cout << "Could not load texture" << std::endl;
}
this->setTexture(Texture);
this->setScale(0.2,0.2);
}
int Item::hp(){
    return hp_;
}
void Item::take()
{
    taken_=!taken_;
}
bool Item::taken()
{
    return taken_;
}
