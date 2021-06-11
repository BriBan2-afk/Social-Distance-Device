//Includes
//#include <Arduino.h>
#include "Toggle.h"
//#include "Timer.h"
#include <NewPing.h>
#include <PirSensor.h>

//Constants
#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define BUZZER_PIN   10
#define LED_PIN   LED_BUILTIN
#define PIR_PIN       5

//Globals & Variables
uint32_t distance;
uint32_t pirStat;
//uint32_t buzzerPinState = LOW;

//Prototypes
void getDistance();
void detectHuman();
//void smartBlink(unsigned long interval);
//void smartBeep(unsigned long onTime, unsigned long offTime);

//Instanciations
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Toggle beep(BUZZER_PIN, 50, 1000);
Toggle led(LED_BUILTIN, 50, 50);
//Timer beepTime;
//Timer ledTime;
PirSensor motion = PirSensor(PIR_PIN, 2, false, false);



void setup() {
  // put your setup code here, to run once
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  // Timer0 is already used for millis() - we'll just interrupt somewhere
  // in the middle and call the "Compare A" function below
  //OCR0A = 0xAF;
  //TIMSK0 |= _BV(OCIE0A);
  //init pir
  motion.begin();
}

// Interrupt is called once a millisecond
/*SIGNAL(TIMER0_COMPA_vect) 
{
  if (distance <= 40) 
  {
    beep.Update();
    led.Update();
  }
  else 
  {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }
}*/

void loop() 
{
  //uint32_t prev = millis();
  //delay(1000);
  //getDistance();
  detectHuman();
  /*if (distance <= 40) 
  {
    beep.Update();
    led.Update();
  }
  else 
  {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }*/
}


//Custom Functions
/*void smartBlink(unsigned long interval)
{
  if (ledTime.timer(interval))
  {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle the buzzer.
  }

}

void smartBeep(unsigned long onTime, unsigned long offTime) 
{
  if (buzzerPinState == HIGH && beepTime.timer(onTime))
  {
    buzzerPinState = LOW;
    digitalWrite(BUZZER_PIN, buzzerPinState); // Toggle the buzzer.
  }
  else if (buzzerPinState == LOW && beepTime.timer(offTime))
  {
    buzzerPinState = HIGH;
    digitalWrite(BUZZER_PIN, buzzerPinState); // Toggle the buzzer.
  }
}*/

void getDistance()
{
  distance = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}

void detectHuman()
{
  pirStat = digitalRead(PIR_PIN); 
  if (pirStat == HIGH) // if motion detected
  {            
    Serial.println("Hey I got you!!!");
  } 
}


