#pragma once

#include <iostream>
#include <random>

class WordGen
{
protected:
    std::string word;
    int wordLength;

public:
    WordGen()
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 10);
        this->wordLength = dist(mt);
        this->word = "";
        this->generate();
    }
    WordGen(int wordLength)
    {
        this->wordLength = wordLength;
        this->word = "";
        this->generate();
    }

    /*WordGen(std::string word)
    {
        this->word = word;
        this->wordLength = word.length();
    }*/

    void generate()
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(97, 122);

        for (int i = 0; i < this->wordLength; i++)
        {
            this->word += dist(mt);
        }
    }

    std::string getWord()
    {
        return this->word;
    }

    int getWordLength()
    {
        return this->wordLength;
    }

    void setWordLength(int wordLength)
    {
        this->wordLength = wordLength;
        this->word = "";
    }
};
class WordCrypt : public WordGen
{
private:
    std::string cryptedWord;
    WordCrypt() : WordGen() // SINGLETON
    {
        cryptedWord = this->word;
        this->crypt();
    }

    WordCrypt(int wordLength) : WordGen(wordLength)
    {
        cryptedWord = this->word;
        this->crypt();
    }
    ~WordCrypt(){};

    WordCrypt(const WordCrypt &) = delete;
    WordCrypt &operator=(const WordCrypt &) = delete;

public:
    /*WordCrypt() : WordGen()
    {
        cryptedWord = this->word;
        this->crypt();
    }
    WordCrypt(int wordLength) : WordGen(wordLength)
    {
        cryptedWord = this->word;
        this->crypt();
    }*/

    static WordCrypt &getInstance()
    {
        static WordCrypt instance;
        return instance;
    }

    static WordCrypt &getInstance(int wordLength)
    {
        static WordCrypt instance(wordLength);
        return instance;
    }

    void destroyInstance()
    {
        this->~WordCrypt();
    }

    void crypt()
    {
        for (int i = 0; i < this->cryptedWord.length(); i++)
        {
            if (this->cryptedWord[i] != 'z')
                this->cryptedWord[i]++;
            else
                this->cryptedWord[i] = 'a';
        }
    }

    /*void decrypt(char c)
    {
        for (int i = 0; i < this->word.length(); i++)
        {
            if (this->word[i] == c)
            {
                this->cryptedWord[i] = c;
            }
        }
    }*/

    std::string getCryptedWord()
    {
        return this->cryptedWord;
    }

    void regenerateWord(int wordLength)
    {
        this->setWordLength(wordLength);
        this->generate();
        this->cryptedWord = this->word;
        this->crypt();
    }
};