// #include "../include/globals.hpp"
#include "../include/player.hpp"
// #include "../include/menu.hpp"
#include <iostream>
#include <chrono>
#include <thread>

Player player;

int main()
{
    // player.showScore();

    constexpr int framesPerSecond = 60;
    constexpr std::chrono::duration<double> frameDuration(1.0 / framesPerSecond);

    while (true)
    {
        // Clear the screen escape sequence
        std::cout << "\033[2J\033[H";

        // Your rendering or refreshing logic goes here
        std::cout << "Frame rendered at " << framesPerSecond << "fps" << std::endl;

        // Sleep for the remaining time to achieve the desired frame rate
        std::this_thread::sleep_for(frameDuration);
    }

    // Menu menu(window);
    // menu.draw();
    return 0;
}
