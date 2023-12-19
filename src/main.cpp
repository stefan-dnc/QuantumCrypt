// #include "../include/globals.hpp"
#include "../include/player.hpp"
// #include "../include/menu.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

Player player;

int main()
{
    // player.showScore();

    constexpr int framesPerSecond = 60;
    constexpr std::chrono::duration<double> frameDuration(1.0 / framesPerSecond);
    int i = 1;

    system("clear");

    while (true)
    {
        // Clear the screen escape sequence
        if (i % framesPerSecond != 0)
        {
            std::cout << "\033[" << (i / framesPerSecond) + 1 << ";1H";
            std::cout << "\033[K";
            // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        // std::cout << "\033[2J\033[H";

        // Your rendering or refreshing logic goes here
        std::cout << "Frame rendered at " << i << "fps" << '\n';
        i++;

        // Sleep for the remaining time to achieve the desired frame rate
        std::this_thread::sleep_for(frameDuration);
    }
    /*std::cout << "abcdef";
    std::cout << "\033[" << (i / 60) << ";0H";
    std::cout << "\033[K";
    std::cout << "exemplu";*/

    // Menu menu(window);
    // menu.draw();
    return 0;
}
