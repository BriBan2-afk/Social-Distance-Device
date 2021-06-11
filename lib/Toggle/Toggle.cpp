#include "Toggle.h"

Toggle::Toggle(uint32_t pin, unsigned long on, unsigned long off)
  {
    hwPin = pin;
    pinMode(hwPin, OUTPUT);     
      
    OnTime = on;
    OffTime = off;
    
    hwState = LOW; 
    previousMillis = 0;
  }
 
  void Toggle::Update()
  {
    unsigned long currentMillis = millis();
    if((hwState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      hwState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(hwPin, hwState);  // Update the actual LED
    }
    else if ((hwState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      hwState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(hwPin, hwState);	  // Update the actual LED
    }
  }