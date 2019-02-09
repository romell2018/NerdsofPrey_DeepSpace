#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <atomic>

using namespace std::chrono;

namespace team
{
namespace DeltaTime
{
typedef std::chrono::high_resolution_clock hr_clock;

hr_clock::time_point time_point_start_;
hr_clock::time_point time_point_end_;
duration<double> elapsed_;

void TimeThread();
void InitializeLoop();
duration<double> GetElapsed();
}
}