#include "weapon.h"

weapon::weapon()
{
    is_atacking_=false;
    if (!Texture.loadFromFile("miecz.png"))
    {
        std::cout << "something wrong" << std::endl;
    }
    if (!Texture2.loadFromFile("miecz2.png"))
    {
        std::cout << "something wrong" << std::endl;
    }
    this->setTexture(Texture);
}
void weapon::atack(float &timer,const float &elapsed)
{
    if(timer<0.7 && is_atacking_)
    {
    this->setTexture(Texture2);
    timer+=elapsed;
    }
    if(timer>0.7 && is_atacking_)
    {
        timer=0;
        this->setTexture(Texture);
        is_atacking_=false;
    }

}
void weapon::set_atack()
{
    is_atacking_=true;
}
bool weapon::is_atacking()
{
    return is_atacking_;
}
