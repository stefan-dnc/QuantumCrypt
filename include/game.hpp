#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <ncurses.h>
#include <mutex>
#include "globals.hpp"
#include "timer.hpp"
#include "wordcrypt.hpp"

class Game
{
private:
    int gameScore = 0;
    const int defaultTime = 35;
    std::string word;
    std::string cryptedWord;
    std::string decryptedWord;
    char currentChar;
    char lastChar;
    std::mutex mtx;
    Timer timer;
    bool isFinished = false;

    void endGame()
    {
        endwin();
        system("clear");
        std::cout << "Game ended" << '\n';

        std::this_thread::sleep_for(std::chrono::seconds(1));

        system("clear");

        // std::cout << "\033[1;1H";

        globals.addTimePlayed(defaultTime);

        if (gameScore > globals.getHighScore())
        {
            globals.setHighScore(gameScore);
            std::cout << "New high score: " << gameScore << '\n';
            // std::cout << "\033[2;1H";
        }
        else
        {
            std::cout << "Your score: " << gameScore << '\n';
            // std::cout << "\033[2;1H";
            std::cout << "High score: " << globals.getHighScore() << '\n';
            // std::cout << "\033[3;1H";
        }

        std::cout << "Press enter to continue...\n";
        // std::cout << "\033[4;1H";

        std::string *getStarted = new std::string;

        std::cin.ignore();
        std::getline(std::cin, *getStarted);

        delete getStarted;

        isFinished = true;
    }

    void outputThread()
    {
        while (timer.elapsed() < defaultTime && !isFinished)
        {
            // std::cout << "\033[1;1H\033[K";
            /*std::cout << "\033[1;11H" << int(defaultTime - timer.elapsed()) << std::flush;
            std::cout << "\033[2;8H" << gameScore << std::flush;
            std::cout << "\033[3;" << (6 + word.length()) << "H" << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            std::cout << "\033[1;11H"
                      << "\033[K";
            std::cout << "\033[2;8H"
                      << "\033[K";

            std::cout << "\033[3;" << (6 + word.length()) << "H" << std::flush;*/

            {
                std::lock_guard<std::mutex> lock(mtx);

                erase();

                mvprintw(1, 0, "Time left: %d", static_cast<int>(defaultTime - timer.elapsed()));
                mvprintw(2, 0, "Score: %d", gameScore);
                mvprintw(3, 0, "Word: %s", decryptedWord.c_str());
                mvprintw(4, 0, "Word: %s", word.c_str());

                refresh();
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    void inputThread()
    {
        WordCrypt &cryptInstance = WordCrypt::getInstance(1);
        cryptedWord = cryptInstance.getCryptedWord();
        decryptedWord = cryptInstance.getWord();

        while (timer.elapsed() < defaultTime && !isFinished)
        {
            {
                std::lock_guard<std::mutex> lock(mtx);
                currentChar = getch();

                if (currentChar != ERR && currentChar != '\n')
                {
                    word += currentChar;
                }
                else if (currentChar == '\n')
                {
                    if (word == cryptedWord)
                    {
                        // gameScore = 1;

                        /*isFinished = true;
                        clear();
                        system("clear");
                        endGame();*/
                        increaseScore(cryptedWord.size());
                        globals.increaseDecryptedWords();
                        cryptInstance.regenerateWord(word.size() + 1);
                        word = "";

                        // cryptInstance.destroyInstance();
                        // WordCrypt &cryptInstance = WordCrypt::getInstance(8);

                        // cryptInstance.regenerateWord(cryptedWord.size());

                        cryptedWord = cryptInstance.getCryptedWord();
                        decryptedWord = cryptInstance.getWord();
                    }
                    else
                    {
                        word = "";
                    }
                }
            }

            /*if (currentChar != ERR && currentChar != '\n')
            {
                word += currentChar;
            }
            else if (currentChar == '\n')
            {
            if (word == "exit")
            {
                clear();
                std::cout << "Game ended" << '\n';
                break;
            }
            else
            {
                word = "";
            }*/

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //}

            // refresh();

            /*if (currentChar > 'a' && currentChar < 'z' || currentChar > 'A' && currentChar < 'Z')
            {
                word += currentChar;
                std::cout << "\033[3;6H" << word << std::flush;
            }
            * /
            if (getch() > 'a' && getch() < 'z' || getch() > 'A' && getch() < 'Z')
            {
                std::cout << "AAAAAAA\n\n\nBBBBBB\n\n\n";
            }

            {
                system("clear");
                std::cout << "Game ended" << '\n';
                break;
            }
            std::cout << "\033[3;" << (6 + word.length()) << "H" << std::flush;

            // std::getline(std::cin, word);

            if (std::cin.get(currentChar) && currentChar != '\n')
            {
                word += currentChar;
                std::cout << "\033[3;6H" << word << std::flush;
            }

            if (!word.empty())
            {
                lastChar = word.back();
            }
            else
            {
                lastChar = '\0';
            }

            if (lastChar == '\0')
            {
                system("clear");
                std::cout << "Game ended" << '\n';
                // timer.start(defaultTime);
                break;
            }*/

            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

public:
    Game()
    {
        system("clear");
        if (globals.getHighScore() == 0)
        {
            std::cout << R"(
This game is based on Caesar's crypting algorithm.

For each letter in a word, the letter is replaced with the letter that is
one position after it.

For example: abc -> bcd
             def -> efg
For 'z' the next letter is 'a'.
                    )" << '\n';

            std::cout << "Press enter to start ";
            std::string *getStarted = new std::string;
            std::cin.ignore();
            std::getline(std::cin, *getStarted);
            delete getStarted;
        }
        else
        {
            system("clear");
        }
        this->start(defaultTime);
        // std::cout << "Game started" << '\n';
        // std::cout << "GAME CONSTRUCTOR" << '\n';
    };
    ~Game()
    {
        system("clear");
        // std::cout << "\n\n\nthe final word is " << word << "with the length of " << word.length() << '\n';
        std::cout << "DELETE JOC" << '\n';
        endwin();

        // mainmenu->draw();
    };

    bool checkIfFinished() const
    {
        return isFinished;
    };

    int getScore() const
    {
        return gameScore;
    };

    void increaseScore(int score)
    {
        gameScore += score;
    };

    void start(int time)
    {
        system("clear");

        initscr();
        timeout(0);

        move(0, 0);

        timer.start(time);

        /*std::cout << "Time left: " << '\n';
        std::cout << "Score: " << '\n';
        std::cout << "Word: ";*/

        // mvprintw(0, 0, "Time left: ");
        //  mvprintw(1, 0, "Score: \n");
        //  mvprintw(2, 0, "Word: ");

        /*WordCrypt &cryptInstance = WordCrypt::getInstance(1);
        cryptedWord = cryptInstance.getCryptedWord();
        decryptedWord = cryptInstance.getWord();*/

        std::thread output(&Game::outputThread, this);
        std::thread input(&Game::inputThread, this);
        // std::thread input(&Game::inputThread, this, std::ref(cryptInstance));

        output.join();
        input.join();

        endGame();

        // std::cout << "\n\n\nthe final word is " << word << "with the length of " << word.length() << '\n';
        // std::cout << "FUNCTIA START" << '\n';

        /*timer.start(time);

        while (timer.elapsed() < defaultTime)
        {
            std::cout << "Time left: " << defaultTime - timer.elapsed() << '\n';

            std::cout << "Score: " << gameScore << '\n';

            std::cout << "Word: ";

            std::cin.ignore();
            std::getline(std::cin, word);

            if (word == "exit")
            {
                system("clear");
                std::cout << "Game ended" << '\n';
                break;
            }

            std::cout << "\033[1;11H"
                      << "\033[K";
            std::cout << "\033[2;8H"
                      << "\033[K";
            std::cout << "\033[3;7H";
        }*/
    };
};