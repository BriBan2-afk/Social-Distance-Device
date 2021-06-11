#ifndef TIMER_H
#define TIMER_H
    #include <Arduino.h>
#endif

class Timer
{
    unsigned long previousMillis;

    public:
    Timer();
    bool timer (unsigned long interval);
    uint32_t timeIt (uint32_t prev);
};
