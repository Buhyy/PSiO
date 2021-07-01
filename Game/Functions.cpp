#include "Functions.h"
void hud(sf::RenderWindow &window,PlayerClass &player)
{

    sf::Text playerText;

    playerText.setCharacterSize(30);
    playerText.setColor(sf::Color::Black);
    sf::Font arial;
    arial.loadFromFile("arial.TTF");
    playerText.setFont(arial);
    std::string dungreed="Statystyki";
    playerText.setString(dungreed);
    playerText.setPosition(32*31+50,100);
    window.draw(playerText);
    std::string playerhealth="Health " + std::to_string(player.health()) ;//+ " | "+std::to_string(player.health_max());
    playerText.setString(playerhealth);
    playerText.setPosition(32*31+50,140);
    window.draw(playerText);
    std::string playerdmg="Damage " + std::to_string(player.dmg());
    playerText.setString(playerdmg);
    playerText.setPosition(32*31+50,180);
    window.draw(playerText);
    std::string playerspeed="Speed " + std::to_string(player.speed());
    playerText.setString(playerspeed);
    playerText.setPosition(32*31+50,220);
    window.draw(playerText);
    std::string playerarmour="Armour " + std::to_string(player.armour());
    playerText.setString(playerarmour);
    playerText.setPosition(32*31+50,260);
    window.draw(playerText);


}
void Tutorial(sf::RenderWindow &window)
{
    sf::Text playerText;

    playerText.setCharacterSize(30);
    playerText.setColor(sf::Color::Black);
    sf::Font arial;
    arial.loadFromFile("arial.TTF");
    playerText.setFont(arial);
    std::string dungreed="Witaj w Dungreed--";
    playerText.setString(dungreed);
    playerText.setPosition(32*9,100);
    window.draw(playerText);
    std::string sterowanie="Sterowanie";
    playerText.setString(sterowanie);
    playerText.setPosition(32*11,180);
    window.draw(playerText);
    std::string lp="Ruch w lewo : Arrow Left";
    playerText.setString(lp);
    playerText.setPosition(32*8,220);
    window.draw(playerText);
    std::string rp="Ruch w prawo : Arrow Right";
    playerText.setString(rp);
    playerText.setPosition(32*8,260);
    window.draw(playerText);
    std::string skok="Skok : Arrow Up ";
    playerText.setString(skok);
    playerText.setPosition(32*8,300);
    window.draw(playerText);
    std::string Atak="Atak : A";
    playerText.setString(Atak);
    playerText.setPosition(32*8,340);
    window.draw(playerText);
    std::string E="Otwieranie skrzynek : E";
    playerText.setString(E);
    playerText.setPosition(32*8,380);
    window.draw(playerText);
    std::string EE="Przechodzie przez drzwi : E";
    playerText.setString(EE);
    playerText.setPosition(32*8,420);
    window.draw(playerText);



}
