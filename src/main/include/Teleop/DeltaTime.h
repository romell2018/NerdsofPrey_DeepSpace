#pragma once

#include <chrono>
#include <iostream>

using namespace std::chrono;

class DeltaTime
{
typedef std::chrono::steady_clock s_clock;
private:
    s_clock::time_point time_point_start_;
    s_clock::time_point time_point_end_;
    duration<double> elapsed_;
public:
    void InitializeLoop();
    void UpdateElapsed();
    double GetElapsed();
};