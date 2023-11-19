#include "../include/globals.hpp"
#include "SFML/Graphics.hpp"
#include "../include/player.hpp"
#include "../include/menu.hpp"
#include <iostream>

sf::Font font;
Player player;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Button Example");
    window.setFramerateLimit(144);

    if (!font.loadFromFile("/Users/stefan/Developer/QuantumCrypt/resources/PixelifySans.ttf"))
    {
        std::cerr << "Error loading font\n";
        return 1;
    }
    player.showScore();

    Menu menu(window);
    menu.draw();
    return 0;
}
