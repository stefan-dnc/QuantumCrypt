#include <iostream>

class WordCrypt
{
private:
    std::string word;
    std::string cryptedWord;

public:
    WordCrypt(std::string word)
    {
        this->word = word;
        this->cryptedWord = word;
        this->crypt();
    }
};