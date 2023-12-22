#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include "game.hpp"

class Menu
{
private:
    std::string userInput;
    // sf::RenderWindow &window;

public:
    Menu(const std::string &input = "nope") : userInput(input) {}
    ~Menu(){};

    void draw();
    void drawPlay();
    void drawStats();
    void drawOptions();
    void drawAbout();
    void drawQuit();
};

void Menu::draw()
{
    system("clear");
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

    switch (stoi(this->userInput))
    {
    case 1:
        this->drawPlay();
        break;
    case 2:
        this->drawStats();
        break;
    case 3:
        this->drawOptions();
        break;
    case 4:
        this->drawAbout();
        break;
    case 5:
        this->drawQuit();
        break;
    }
}

void Menu::drawStats()
{
    system("clear");
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

    std::cin.ignore();
    getline(std::cin, this->userInput);

    this->draw();
}

void Menu::drawPlay()
{
    system("clear");
    Game *game = new Game();
    system("clear");
    delete game;

    this->draw();
}

void Menu::drawOptions()
{
    system("clear");
    std::cout << R"(
 _____       _   _                 
|  _  |     | | (_)                
| | | |_ __ | |_ _  ___  _ __  ___ 
| | | | '_ \| __| |/ _ \| '_ \/ __|
\ \_/ / |_) | |_| | (_) | | | \__ \
 \___/| .__/ \__|_|\___/|_| |_|___/
      | |                          
      |_|                          
      )" << '\n';

    std::cout << "1. Change username    ?????" << '\n';
    std::cout << "2. Reset stats        ?????" << '\n';
    std::cout << "3. Return to main menu" << '\n';

    std::cout << "'\n\n";

    std::cout << "Enter your choice: ";

    std::cin >> this->userInput;

    while (this->userInput < "1" || this->userInput > "3")
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin >> this->userInput;
    }

    switch (stoi(this->userInput))
    {
    case 1:
        // Change username
        break;
    case 2:
        // Reset stats
        break;
    case 3:
        this->draw();
        break;
    }
}

void Menu::drawAbout()
{
    system("clear");
    std::cout << R"(
  ___  _                 _   
 / _ \| |               | |  
/ /_\ \ |__   ___  _   _| |_ 
|  _  | '_ \ / _ \| | | | __|
| | | | |_) | (_) | |_| | |_ 
\_| |_/_.__/ \___/ \__,_|\__|
        )" << '\n';
    std::cout << " ¬ Version: "
              << "1.0.0" << '\n';
    std::cout << " ¬ Author: "
              << "Stefan Dinca" << '\n';
    std::cout << " ¬ Github: "
              << " https://github.com/stefan-dnc/QuantumCrypt" << '\n';
    std::cout << " ¬ License: "
              << "Open source" << '\n';
    std::cout << " ¬ Description: "
              << "A simple game of decrypting passwords." << '\n';
    std::cout << " ¬ Dependencies: "
              << "C++ 2b" << '\n';

    std::cout << "\n\n";

    std::cout << "Press enter to return to main menu. ";

    std::cin.ignore();
    getline(std::cin, this->userInput);

    this->draw();
}

void Menu::drawQuit()
{
    system("clear");
}