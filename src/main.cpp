#include <Arduino.h>
#include <ESP32Servo.h>

//12V Motor
#define PINPWM1 27
#define PINPWM2 26

#define channel1 0  // 0 bis 15 PWM-Kanäle stehen zur Auswahl
#define channel2 1  // 0 bis 15 PWM-Kanäle stehen zur Auswahl
#define frequency 1000 
#define resolution 8
#define dutycycle (pow(2,resolution)-1) 
enum Gear {REVERS, DRIVE, NUTRAL};
Gear gear = NUTRAL;
//ServoMotor
#define SMOTOR 32
Servo servo;
enum Directions {RIGHT, LEFT, STRAIGHT};
Directions direction = STRAIGHT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly: 
}
