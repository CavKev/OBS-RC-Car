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
  Serial.begin(115200); // set up a serial connection

  // Set the PWM pin for channel 1 as an output
  pinMode(PINPWM1, OUTPUT);
  // Configure PWM settings for channel 1
  ledcSetup(channel1, frequency, resolution);
  // Attach PWM channel 1 to the specified pin
  ledcAttachPin(PINPWM1, channel1);

  // Set the PWM pin for channel 2 as an output
  pinMode(PINPWM2, OUTPUT);
  // Configure PWM settings for channel 2
  ledcSetup(channel2, frequency, resolution);
  // Attach PWM channel 2 to the specified pin
  ledcAttachPin(PINPWM2, channel2);


//Servomotor
// Set the servo motor pin mode to output
pinMode(SMOTOR, OUTPUT);

// Attach the servo motor to the specified pin
servo.attach(SMOTOR);

// Set the initial position of the servo motor to 90 degrees
servo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly: 
}
