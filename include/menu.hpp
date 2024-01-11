#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include "game.hpp"
#include "achievements.hpp"

/*template <size_t N>
void printAchievements(Achievement (&achievements)[N])
{
    for (const auto &p : achievements)
    {
        std::cout << " ¬ " << p.getName() << ": " << p.getDescription() << '\n';
        if (p.getAchieved())
        {
            std::cout << "   Unlocked" << '\n';
        }
        else
        {
            std::cout << "   Locked" << '\n';
        }
    }
}*/

template <typename Iterator>
void printAchievements(Iterator begin, Iterator end)
{
    for (auto it = begin; it != end; ++it)
    {
        const auto &p = *it;
        std::cout << " ¬ " << p->getName() << ": " << p->getDescription() << '\n';
        if (p->getAchieved())
        {
            std::cout << "   Unlocked" << '\n';
        }
        else
        {
            std::cout << "   Locked" << '\n';
        }
    }
}

class Menu
{
private:
    std::string userInput;
    // sf::RenderWindow &window;
    Menu(const std::string &input = "nope") : userInput(input) {}

public:
    static Menu &getInstance()
    {
        static Menu instance;
        return instance;
    }

    Menu(const Menu &) = delete;
    void operator=(const Menu &) = delete;

    ~Menu(){};

    void draw();
    void drawPlay();
    void drawStats();
    void drawOptions();
    void drawAchievements();
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
    std::cout << "4. Achievements" << '\n';
    std::cout << "5. About" << '\n';
    std::cout << "6. Quit" << '\n';

    std::cout << "'\n\n";

    // std::cout << "Enter your choice: ";

    while (true)
    {
        try
        {
            std::cout << "Enter your choice: ";
            std::cin >> this->userInput;

            if (this->userInput < "1" || this->userInput > "6")
            {
                throw std::out_of_range("Invalid input. Please try again");
            }

            break;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // std::cin >> this->userInput;

    /*while (this->userInput < "1" || this->userInput > "6")
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin >> this->userInput;
    }*/

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
        this->drawAchievements();
        break;
    case 5:
        this->drawAbout();
        break;
    case 6:
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
    std::cout << " ¬ High score: "
              << globals.getHighScore() << " points\n";
    std::cout << " ¬ Decrypted passwords: "
              << globals.getDecryptedWords() << " words\n";
    std::cout << " ¬ Time played: "
              << globals.getTimePlayed() << " seconds\n";

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

    std::cout << "1. Reset stats" << '\n';
    std::cout << "2. Return to main menu" << '\n';

    std::cout << "'\n\n";

    // std::cout << "Enter your choice: ";

    while (true)
    {
        try
        {
            std::cout << "Enter your choice: ";
            std::cin >> this->userInput;

            if (this->userInput < "1" || this->userInput > "2")
            {
                throw std::out_of_range("Invalid input. Please try again");
            }

            break;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // std::cin >> this->userInput;

    /*while (this->userInput < "1" || this->userInput > "2")
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin >> this->userInput;
    }*/

    switch (stoi(this->userInput))
    {
    case 1:
        globals.resetStats();
        std::cout << "Stats reseted.\n";
        this->draw();
        break;

    case 2:
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

void Menu::drawAchievements()
{
    system("clear");
    std::cout << R"(
  ___       _     _                                     _       
 / _ \     | |   (_)                                   | |      
/ /_\ \ ___| |__  _  _____   _____ _ __ ___   ___ _ __ | |_ ___ 
|  _  |/ __| '_ \| |/ _ \ \ / / _ \ '_ ` _ \ / _ \ '_ \| __/ __|
| | | | (__| | | | |  __/\ V /  __/ | | | | |  __/ | | | |_\__ \
\_| |_/\___|_| |_|_|\___| \_/ \___|_| |_| |_|\___|_| |_|\__|___/                   
        )" << '\n';

    std::vector<std::unique_ptr<Achievement>> achievements;

    achievements.push_back(std::make_unique<Achievement>("First time", "Play the game for the first time"));
    achievements.push_back(std::make_unique<RareAchievement>("Ten", "Score at least 10 points in a game"));
    achievements.push_back(std::make_unique<EpicAchievement>("Enjoy the game", "Play for more than one minute"));

    if (globals.getTimePlayed() > 0)
    {
        achievements[0]->setAchieved();
    }
    if (globals.getHighScore() >= 10)
    {
        achievements[1]->setAchieved();
    }
    if (globals.getTimePlayed() >= 60)
    {
        achievements[2]->setAchieved();
    }

    // printAchievements(achievements);
    printAchievements(achievements.begin(), achievements.end());

    std::cin.ignore();
    getline(std::cin, this->userInput);

    this->draw();
}