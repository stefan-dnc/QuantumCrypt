#pragma once

#include <iostream>

class Player
{
public:
    Player(){};

    void showScore()
    {
        std::cout << score << std::endl;
    };
    void increaseScore()
    {
        score++;
    };

private:
    int score = 0;
};