#include "../include/globals.hpp"
#include "SFML/Graphics.hpp"
#include "../include/menu.hpp"
#include "../include/player.hpp"
#include "../include/levelsmenu.hpp"

LevelsMenu::LevelsMenu(sf::RenderWindow &window) : window(window)
{

    // sf::Text text;
    text.setFont(font);
    text.setPosition(100, 100);
    text.setString("Quantum Crypt");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    // sf::Text textButton;
    textButton.setFont(font);
    textButton.setPosition(120, 210);
    textButton.setString("LEVEL 1");
    textButton.setCharacterSize(24);
    textButton.setFillColor(sf::Color::Black);
    textButton.setStyle(sf::Text::Bold);

    // myButton(sf::Vector2f(100, 200), sf::Vector2f(100, 50), sf::Color::White);
    myButton.setPosition(sf::Vector2f(100, 200));
    myButton.setSize(sf::Vector2f(140, 50));
    myButton.setColor(sf::Color::White);

    // sf::Text textButton2;
    textButton2.setFont(font);
    textButton2.setPosition(120, 310);
    textButton2.setString("LEVEL 2");
    textButton2.setCharacterSize(24);
    textButton2.setFillColor(sf::Color::Black);
    textButton2.setStyle(sf::Text::Bold);

    // Button myButton2(sf::Vector2f(100, 300), sf::Vector2f(140, 50), sf::Color::White);
    myButton2.setPosition(sf::Vector2f(100, 300));
    myButton2.setSize(sf::Vector2f(140, 50));
    myButton2.setColor(sf::Color::White);

    // sf::Text textButton3;
    textButton3.setFont(font);
    textButton3.setPosition(120, 410);
    textButton3.setString("LEVEL 3");
    textButton3.setCharacterSize(24);
    textButton3.setFillColor(sf::Color::Black);
    textButton3.setStyle(sf::Text::Bold);

    // Button myButton3(sf::Vector2f(100, 400), sf::Vector2f(100, 50), sf::Color::White);
    myButton3.setPosition(sf::Vector2f(100, 400));
    myButton3.setSize(sf::Vector2f(140, 50));
    myButton3.setColor(sf::Color::White);
}

void LevelsMenu::handleEvent(const sf::Event &event)
{
    sf::Mouse mouse;
    if (event.type == sf::Event::MouseMoved)
    {
        if (mouse.getPosition(window).x >= 100 && mouse.getPosition(window).x <= 200 &&
            mouse.getPosition(window).y >= 200 && mouse.getPosition(window).y <= 250)
        {
            textButton.setStyle(sf::Text::Bold | sf::Text::Underlined);
        }
        else
        {
            textButton.setStyle(sf::Text::Bold);
        }
        if (mouse.getPosition(window).x >= 100 && mouse.getPosition(window).x <= 200 &&
            mouse.getPosition(window).y >= 300 && mouse.getPosition(window).y <= 350)
        {
            textButton2.setStyle(sf::Text::Bold | sf::Text::Underlined);
        }
        else
        {
            textButton2.setStyle(sf::Text::Bold);
        }
        if (mouse.getPosition(window).x >= 100 && mouse.getPosition(window).x <= 200 &&
            mouse.getPosition(window).y >= 400 && mouse.getPosition(window).y <= 450)
        {
            textButton3.setStyle(sf::Text::Bold | sf::Text::Underlined);
        }
        else
        {
            textButton3.setStyle(sf::Text::Bold);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (mouse.getPosition(window).x >= 100 && mouse.getPosition(window).x <= 200 &&
            mouse.getPosition(window).y >= 200 && mouse.getPosition(window).y <= 250)
        {
            std::cout << "Play" << std::endl;
        }
        if (mouse.getPosition(window).x >= 100 && mouse.getPosition(window).x <= 200 &&
            mouse.getPosition(window).y >= 300 && mouse.getPosition(window).y <= 350)
        {
            std::cout << "Options" << std::endl;
        }
        if (mouse.getPosition(window).x >= 100 && mouse.getPosition(window).x <= 200 &&
            mouse.getPosition(window).y >= 400 && mouse.getPosition(window).y <= 450)
        {
            std::cout << "Quit" << std::endl;
            window.close();
        }
    }
}

void LevelsMenu::draw()
{
    while (window.isOpen())
    {
        for (sf::Event event; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
                    if (myButton.isClicked(mousePosition))
                    {
                        // std::cout << "Button Clicked!" << std::endl;
                        player.increaseScore();
                        player.showScore();
                    }
                }
            }

            handleEvent(event);
        }

        window.clear();
        window.draw(text);
        myButton.draw(window);
        window.draw(textButton);
        myButton2.draw(window);
        window.draw(textButton2);
        myButton3.draw(window);
        window.draw(textButton3);
        window.display();
    }
}