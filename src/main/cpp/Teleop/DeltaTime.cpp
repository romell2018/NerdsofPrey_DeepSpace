#include "Teleop/DeltaTime.h"

namespace team
{
void DeltaTime::Init()
{
    time_point_end_ = s_clock::now();
}

double DeltaTime::GetElapsed()
{
    return elapsed_.count();
}

void DeltaTime::UpdateElapsed()
{
    time_point_start_ = time_point_end_;
    time_point_end_ = s_clock::now();
    elapsed_ = time_point_end_ - time_point_start_;
}
} // namespace team