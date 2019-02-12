#include "Teleop/DeltaTime.h"

namespace team
{
namespace DeltaTime
{
void InitializeLoop()
{
    time_point_start_ = hr_clock::now();
    std::thread th([&]()
    {
        while(true)
        {
            time_point_end_ = time_point_start_;
            time_point_start_ = hr_clock::now();
            elapsed_ = time_point_end_ - time_point_start_;
        }
    });
    th.detach();
}
}
}