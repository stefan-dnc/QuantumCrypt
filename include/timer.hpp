#pragma once

#include <iostream>
#include <chrono>
#include <thread>

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    int time;

public:
    Timer(){};
    ~Timer(){};

    void start(int time)
    {
        this->time = time;
        startTime = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = currentTime - startTime;
        return duration.count();
    }
    void addTime(int time)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        this->time += time;
    }
};