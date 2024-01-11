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
        try
        {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(1, 10);
            this->wordLength = dist(mt);

            if (this->wordLength <= 0)
            {
                throw std::invalid_argument("Invalid word length.");
            }

            this->word = "";
            this->generate();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    WordGen(int wordLength)
    {
        try
        {
            this->wordLength = wordLength;

            if (this->wordLength <= 0)
            {
                throw std::invalid_argument("Invalid word length.");
            }

            this->word = "";
            this->generate();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
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

    virtual std::string getWordDifficulty() const
    {
        return "uncrypted";
    }
};
class WordCrypt : public WordGen
{
private:
    std::string cryptedWord;
    WordCrypt() : WordGen()
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

    virtual std::string getWordDifficulty() const override
    {
        return std::to_string(this->wordLength);
    }
};