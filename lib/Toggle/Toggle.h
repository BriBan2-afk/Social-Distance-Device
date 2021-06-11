#ifndef TOGGLE_H
#define TOGGLE_H
    #include <Arduino.h>
#endif


class Toggle
{
	// Class Member Variables
	// These are initialized at startup
	uint32_t hwPin;      // the number of the LED pin
	unsigned long OnTime;     // milliseconds of on-time
	unsigned long OffTime;    // milliseconds of off-time
 
	// These maintain the current state
	uint32_t hwState;             		// ledState used to set the LED
	unsigned long previousMillis;  	// will store last time LED was updated
 
  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  public:
  Toggle(uint32_t pin, unsigned long on, unsigned long off);
  void Update();
};