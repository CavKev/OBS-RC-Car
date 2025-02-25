#include <ESP32Servo.h>

#define PINPWM1 27
#define PINPWM2 26

#define channel1 0  // 0 bis 15 PWM-Kanäle stehen zur Auswahl
#define channel2 1  // 0 bis 15 PWM-Kanäle stehen zur Auswahl
#define frequency 1000 
#define resolution 8
#define dutycycle (pow(2,resolution)-1) 
bool VORWAERTS = false;
bool RUECKWAERTS = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(PINPWM1, OUTPUT);
  ledcSetup(channel1, frequency, resolution);  // Einstellung des PWM-Kanals
  ledcAttachPin(PINPWM1, channel1);
  pinMode(PINPWM2, OUTPUT);
  ledcSetup(channel2, frequency, resolution);  // Einstellung des PWM-Kanals
  ledcAttachPin(PINPWM2, channel2);

}

void loop() {
  // put your main code here, to run repeatedly:
  

  if (VORWAERTS){
    ledcWrite(channel1,dutycycle);
  }else if(RUECKWAERTS){
    ledcWrite(channel2,dutycycle);
  }

}
