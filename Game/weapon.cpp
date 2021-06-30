#include "weapon.h"

weapon::weapon()
{
    if (!Texture.loadFromFile("miecz.png"))
    {
        std::cout << "something wrong" << std::endl;
    }
    this->setTexture(Texture);
}
