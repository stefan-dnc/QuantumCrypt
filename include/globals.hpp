#pragma once

#include <iostream>

class Globals
{
private:
    int highScore = 2;

public:
    Globals(){};
    ~Globals(){};

    int getHighScore()
    {
        return highScore;
    };

    void setHighScore(int score)
    {
        highScore = score;
    };
};

extern Globals globals;