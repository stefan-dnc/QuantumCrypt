#pragma once

#include <iostream>
#include <string>

class Menu
{
protected:
    std::string userInput;
    // sf::RenderWindow &window;

public:
    Menu(const std::string &input = "nope") : userInput(input) {}
    virtual ~Menu(){};

    virtual void draw();
    /*Menu(sf::RenderWindow &window);
    void handleEvent(const sf::Event &event);
    void draw();

    sf::Text text;
    sf::Text textButton;
    sf::Text textButton2;
    sf::Text textButton3;
    Button myButton;
    Button myButton2;
    Button myButton3;*/
};

class StatsMenu : public Menu
{
public:
    StatsMenu() {}
    virtual ~StatsMenu() {}

    virtual void draw() override;
};

void Menu::draw()
{
    std::cout << R"(
 _____                   _                     _____                  _   
|  _  |                 | |                   /  __ \                | |  
| | | |_   _  __ _ _ __ | |_ _   _ _ __ ___   | /  \/_ __ _   _ _ __ | |_ 
| | | | | | |/ _` | '_ \| __| | | | '_ ` _ \  | |   | '__| | | | '_ \| __|
\ \/' / |_| | (_| | | | | |_| |_| | | | | | | | \__/\ |  | |_| | |_) | |_ 
 \_/\_\\__,_|\__,_|_| |_|\__|\__,_|_| |_| |_|  \____/_|   \__, | .__/ \__|
                                                           __/ | |        
                                                          |___/|_|        
    )" << '\n';
    std::cout << "1. Play" << '\n';
    std::cout << "2. Stats" << '\n';
    std::cout << "3. Options" << '\n';
    std::cout << "4. About" << '\n';
    std::cout << "5. Quit" << '\n';

    std::cout << "'\n\n";

    std::cout << "Enter your choice: ";

    std::cin >> this->userInput;

    while (this->userInput < "1" || this->userInput > "5")
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin >> this->userInput;
    }

    StatsMenu &statsMenu = dynamic_cast<StatsMenu &>(*this);

    std::cout << " AICI 1\n";
    switch (stoi(this->userInput))
    {
    case 1:
        // Play
        break;
    case 2:
        std::cout << " AICI 2\n";
        // if (statsMenu)
        //{
        std::cout << " AICI 3\n";
        statsMenu.draw();
        //}
        break;
    case 3:
        // Options
        break;
    case 4:
        // About
        break;
    case 5:
        // Quit
        break;
    }
}

void StatsMenu::draw()
{
    std::cout << R"(
 _____ _        _       
/  ___| |      | |      
\ `--.| |_ __ _| |_ ___ 
 `--. \ __/ _` | __/ __|
/\__/ / || (_| | |_\__ \
\____/ \__\__,_|\__|___/                    
        )" << '\n';
    std::cout << " ¬ Decrypted passwords: "
              << "9999999" << '\n';
    std::cout << " ¬ Max score: "
              << "9999999" << '\n';
    std::cout << " ¬ Total games played: "
              << "9999999" << '\n';
    std::cout << " ¬ Total time played: "
              << "9999999" << '\n';

    std::cout << "Press enter to return to main menu. ";

    std::cin >> this->userInput;

    Menu menu;
    Menu *baseMenu = dynamic_cast<Menu *>(this);
    if (baseMenu)
    {
        // Call the draw function of the Menu base class
        baseMenu->draw();
    }
}