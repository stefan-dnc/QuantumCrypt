#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color)
        : shape(size), buttonColor(color)
    {
        shape.setPosition(position);
        shape.setFillColor(buttonColor);
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

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Button Example");
    window.setFramerateLimit(144);

    sf::Font font;
    if (!font.loadFromFile("/Users/stefan/Developer/QuantumCrypt/resources/PixelifySans.ttf"))
    {
        std::cerr << "Error loading font\n";
        return 1;
    }

    sf::Text text;
    text.setFont(font);
    text.setPosition(100, 100);
    text.setString("Quantum Crypt");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::Text textButton;
    textButton.setFont(font);
    textButton.setPosition(120, 210);
    textButton.setString("Play");
    textButton.setCharacterSize(24);
    textButton.setFillColor(sf::Color::Black);
    textButton.setStyle(sf::Text::Bold);
    Button myButton(sf::Vector2f(100, 200), sf::Vector2f(100, 50), sf::Color::White);

    sf::Text textButton2;
    textButton2.setFont(font);
    textButton2.setPosition(120, 310);
    textButton2.setString("Options");
    textButton2.setCharacterSize(24);
    textButton2.setFillColor(sf::Color::Black);
    textButton2.setStyle(sf::Text::Bold);
    Button myButton2(sf::Vector2f(100, 300), sf::Vector2f(140, 50), sf::Color::White);

    sf::Text textButton3;
    textButton3.setFont(font);
    textButton3.setPosition(120, 410);
    textButton3.setString("Quit");
    textButton3.setCharacterSize(24);
    textButton3.setFillColor(sf::Color::Black);
    textButton3.setStyle(sf::Text::Bold);
    Button myButton3(sf::Vector2f(100, 400), sf::Vector2f(100, 50), sf::Color::White);

    sf::Mouse mouse;

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
                        std::cout << "Button Clicked!" << std::endl;
                    }
                }
            }

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

    return 0;
}
