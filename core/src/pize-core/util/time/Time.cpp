#ifndef PIZE_CORE_UTIL_TIME_TIME
#define PIZE_CORE_UTIL_TIME_TIME

#include <chrono>

using namespace std::chrono;

static double currentTimeMicro(){
    time_point<system_clock, microseconds> tp = time_point_cast<microseconds>(high_resolution_clock::now());
    duration tmp = duration_cast<microseconds>(tp.time_since_epoch());
    return tmp.count();
}

static double currentTimeMillis(){
    return currentTimeMicro() / 1000.0;
}

static double currentTimeSeconds(){
    return currentTimeMicro() / 1000000.0;
}

#endif