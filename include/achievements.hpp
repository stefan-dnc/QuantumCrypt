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

    /*friend std::ostream &operator<<(std::ostream &os, const Achievement &obj)
    {
        os << " ¬ " << obj.getName() << '\n'
           << obj.getDescription() << '\n';
        if (obj.getAchieved())
        {
            os << "--- Unlocked" << '\n';
        }
        else
        {
            os << "--- Locked" << '\n';
        }
        return os;
    }*/

    virtual void print(std::ostream &os) const
    {
        os << " ¬ " << getName() << '\n'
           << getDescription() << '\n';
        if (getAchieved())
        {
            os << "--- Unlocked" << '\n';
        }
        else
        {
            os << "--- Locked" << '\n';
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Achievement &obj)
    {
        obj.print(os);
        return os;
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

    /*friend std::ostream &operator<<(std::ostream &os, const RareAchievement &obj)
    {
        os << " ¬ " << obj.getName() << " [RARE]" << '\n'
           << obj.getDescription() << '\n';
        if (obj.getAchieved())
        {
            os << "--- Unlocked" << '\n';
        }
        else
        {
            os << "--- Locked" << '\n';
        }
        return os;
    }*/

    void print(std::ostream &os) const override
    {
        os << " ¬ " << getName() << " [RARE]" << '\n'
           << getDescription() << '\n';
        if (getAchieved())
        {
            os << "--- Unlocked" << '\n';
        }
        else
        {
            os << "--- Locked" << '\n';
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const RareAchievement &obj)
    {
        obj.print(os);
        return os;
    }
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

    /*friend std::ostream &operator<<(std::ostream &os, const EpicAchievement &obj)
    {
        os << " ¬ " << obj.getName() << " [EPIC]" << '\n'
           << obj.getDescription() << '\n';
        if (obj.getAchieved())
        {
            os << "--- Unlocked" << '\n';
        }
        else
        {
            os << "--- Locked" << '\n';
        }
        return os;
    }*/

    void print(std::ostream &os) const override
    {
        os << " ¬ " << getName() << " [EPIC]" << '\n'
           << getDescription() << '\n';
        if (getAchieved())
        {
            os << "--- Unlocked" << '\n';
        }
        else
        {
            os << "--- Locked" << '\n';
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const EpicAchievement &obj)
    {
        obj.print(os);
        return os;
    }
};