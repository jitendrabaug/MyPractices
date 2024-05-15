#pragma once
#include<chrono>

auto calculateTimeDifference(const std::chrono::time_point<std::chrono::high_resolution_clock>& start,
    const std::chrono::time_point<std::chrono::high_resolution_clock>& end) 
{
    using namespace std::chrono;
   /* duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();*/
    return duration_cast<nanoseconds>(end - start);
}