#include "Functions.h"
void hud(sf::RenderWindow &window,PlayerClass &player)
{

    sf::Text playerText;

    playerText.setCharacterSize(30);
    playerText.setColor(sf::Color::Black);
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    playerText.setFont(arial);
    std::string playerhealth="Health " + std::to_string(player.health()) + " | "+std::to_string(player.health_max());
    playerText.setString(playerhealth);
    playerText.setPosition(32*31+50,100);
    window.draw(playerText);
    std::string playerdmg="Damage " + std::to_string(player.dmg());
    playerText.setString(playerdmg);
    playerText.setPosition(32*31+50,140);
    window.draw(playerText);
    std::string playerspeed="Speed " + std::to_string(player.speed());
    playerText.setString(playerspeed);
    playerText.setPosition(32*31+50,180);
    window.draw(playerText);
    std::string playerarmour="Armour " + std::to_string(player.armour());
    playerText.setString(playerarmour);
    playerText.setPosition(32*31+50,220);
    window.draw(playerText);


}
