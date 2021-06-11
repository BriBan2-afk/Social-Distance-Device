//Includes
//#include <Arduino.h>
#include "Timer.h"
#include "Toggle.h"
#include <NewPing.h>
//#include <PirSensor.h>

//Constants
#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define BUZZER_PIN   10
#define LED_PIN   LED_BUILTIN
#define PIR_PIN       2
#define SOCIAL_DISTANCE 183 //cm //6ft

//Globals & Variables
int distance;
int PirStat;

//Prototypes
void getDistance();
void detectHuman();

//Instanciations
Toggle beep(BUZZER_PIN, 50, 1000);
Toggle led(LED_BUILTIN, 50, 50);
Timer  uSensor;
Timer  pSensor;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
//PirSensor motion = PirSensor(PIR_PIN, 2, false, false);



void setup() {
  // put your setup code here, to run once
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.S
  pinMode(PIR_PIN, INPUT);
}

void loop() 
{
  getDistance();
  detectHuman();
  if (PirStat == HIGH && distance <= SOCIAL_DISTANCE) 
  {
    beep.Update();
    led.Update();
  }
  else 
  {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }
}

void getDistance()
{
  if (uSensor.timer(500))
  {
    distance = sonar.ping_cm();
    Serial.print("Ping: ");
    Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
  }
  
}

void detectHuman()
{
  if (pSensor.timer(500))
  {
    PirStat = digitalRead(PIR_PIN);
    if (PirStat == HIGH)
    {
      Serial.println("motion detected.");
    }
    else if (PirStat == LOW)
    {
      Serial.println("motion not detected.");
    }
  }
  
}


