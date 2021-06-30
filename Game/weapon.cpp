#include "weapon.h"

weapon::weapon()
{
    if (!Texture.loadFromFile("miecz.png"))
    {
        std::cout << "Could not load texture" << std::endl;
    }
    this->setTexture(Texture);
}
