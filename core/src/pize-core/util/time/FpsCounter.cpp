#ifndef PIZE_CORE_UTIL_TIME_FPS_COUNTER
#define PIZE_CORE_UTIL_TIME_FPS_COUNTER

#include <pize-core/util/time/Time.cpp>

class FpsCounter{
private:

    double prevTime;
    int counter, fps;

public:
    FpsCounter(){
        prevTime = currentTimeMillis();
        counter = 0;
        fps = 0;
    }

    void count(){
        double currentTime = currentTimeMillis();

        double difference = currentTime - prevTime;
        if(difference > 1000){
            prevTime = currentTime;

            fps = counter;
            counter = 0;
        }else
            counter++;
    }

    int get(){
        return fps;
    }

};

#endif