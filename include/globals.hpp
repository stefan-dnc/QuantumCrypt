#pragma once

#include <iostream>

class Globals
{
private:
    int highScore = 0;
    int decryptedWords = 0;
    int timePlayed = 0;

public:
    Globals(){};
    ~Globals(){};

    void setHighScore(int score)
    {
        highScore = score;
    };

    int getHighScore() const
    {
        return highScore;
    };

    void increaseDecryptedWords()
    {
        decryptedWords++;
    }

    int getDecryptedWords() const
    {
        return decryptedWords;
    };

    int getTimePlayed() const
    {
        return timePlayed;
    };

    void addTimePlayed(int time)
    {
        timePlayed += time;
    };

    void resetStats()
    {
        highScore = 0;
        decryptedWords = 0;
        timePlayed = 0;
    };
};

extern Globals globals;