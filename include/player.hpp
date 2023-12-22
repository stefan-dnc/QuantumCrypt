#pragma once

#include <iostream>

class Player
{
private:
    int score = 0;

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
};