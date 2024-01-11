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
};
class WordCrypt : public WordGen
{
private:
    std::string cryptedWord;

public:
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
};

int main()
{
    WordGen cuvant(5), cuvant2(12), cuvant3(1);
    std::cout << cuvant.getWord() << std::endl;
    std::cout << cuvant2.getWord() << std::endl;
    std::cout << cuvant3.getWord() << std::endl;

    std::cout << std::endl
              << std::endl
              << std::endl;

    WordCrypt cuvantCriptat(5), cuvantCriptat2(12), cuvantCriptat3(1);
    std::cout << cuvantCriptat.getCryptedWord() << " si " << cuvantCriptat.getWord() << std::endl;
    std::cout << cuvantCriptat2.getCryptedWord() << " si " << cuvantCriptat2.getWord() << std::endl;
    std::cout << cuvantCriptat3.getCryptedWord() << " si " << cuvantCriptat3.getWord() << std::endl;
}