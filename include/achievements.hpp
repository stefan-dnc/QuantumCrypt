#pragma once

#include <iostream>

class Achievement
{
private:
    bool isAchieved = false;
    std::string name;
    std::string description;

public:
    Achievement()
    {
        this->name = "Hidden achievement";
        this->description = "No description available.";
    }

    Achievement(std::string name, std::string description)
    {
        this->name = name;
        this->description = description;
    }

    ~Achievement() {}

    void setAchieved(bool isAchieved)
    {
        this->isAchieved = isAchieved;
    }

    bool getAchieved() const
    {
        return this->isAchieved;
    }

    std::string getName() const
    {
        return this->name;
    }

    std::string getDescription() const
    {
        return this->description;
    }

    void setAchieved()
    {
        this->isAchieved = true;
    }
};

class RareAchievement : public Achievement
{

public:
    RareAchievement() : Achievement()
    {
    }

    RareAchievement(std::string name, std::string description) : Achievement(name, description)
    {
    }

    ~RareAchievement() {}
};

class EpicAchievement : public Achievement
{

public:
    EpicAchievement() : Achievement()
    {
    }

    EpicAchievement(std::string name, std::string description) : Achievement(name, description)
    {
    }

    ~EpicAchievement() {}
};