#include "Timer.h"

Timer::Timer()
{
    previousMillis = 0;
}

bool Timer::timer (unsigned long interval)
{
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= interval) 
    {
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        return true;
    }
    
    return false;
}

uint32_t Timer::timeIt (uint32_t prev)
{
    uint32_t curr = millis();
    uint32_t diff = curr - prev;
    Serial.println(diff);
    return diff;
}



