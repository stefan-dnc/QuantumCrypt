#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Button
{
public:
    Button(){};
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color)
        : shape(size), buttonColor(color)
    {
        shape.setPosition(position);
        shape.setFillColor(buttonColor);
    }

    void setPosition(sf::Vector2f position)
    {
        shape.setPosition(position);
    }

    void setSize(sf::Vector2f size)
    {
        shape.setSize(size);
    }

    void setColor(sf::Color color)
    {
        shape.setFillColor(color);
    }

    void draw(sf::RenderWindow &window) const
    {
        window.draw(shape);
    }

    bool isClicked(const sf::Vector2f &mousePosition) const
    {
        return shape.getGlobalBounds().contains(mousePosition);
    }

private:
    sf::RectangleShape shape;
    sf::Color buttonColor;
};