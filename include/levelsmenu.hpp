#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../include/button.hpp"

class LevelsMenu
{
public:
    LevelsMenu(sf::RenderWindow &window);
    void handleEvent(const sf::Event &event);
    void draw();

    sf::Text text;
    sf::Text textButton;
    sf::Text textButton2;
    sf::Text textButton3;
    Button myButton;
    Button myButton2;
    Button myButton3;

private:
    sf::RenderWindow &window;
};