// #include "../include/globals.hpp"
#include "../include/player.hpp"
#include "../include/menu.hpp"
#include "../include/timer.hpp"
#include "../include/game.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

Player player;
Globals globals;

int main()
{
    // player.showScore();

    constexpr int framesPerSecond = 60;
    constexpr std::chrono::duration<double> frameDuration(1.0 / framesPerSecond);
    // int i = 1;

    system("clear");

    // mainmenu.draw();

    Menu *mainmenu = new Menu();
    mainmenu->draw();

    /*while (true)
    {
        if (i % framesPerSecond != 0)
        {
            std::cout << "\033[" << (i / framesPerSecond) + 1 << ";1H";
            std::cout << "\033[K";
            // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        // std::cout << "\033[2J\033[H";

        std::cout << "Frame rendered at " << i << "fps" << '\n';
        i++;

        std::this_thread::sleep_for(frameDuration);
    }*/
    /*std::cout << "abcdef";
    std::cout << "\033[" << (i / 60) << ";0H";
    std::cout << "\033[K";
    std::cout << "exemplu";*/

    // Menu menu(window);
    // menu.draw();
    return 0;
}
