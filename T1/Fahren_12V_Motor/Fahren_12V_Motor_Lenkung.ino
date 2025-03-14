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
  pinMode(PINPWM1, OUTPUT);
  ledcSetup(channel1, frequency, resolution);  // Einstellung des PWM-Kanals
  ledcAttachPin(PINPWM1, channel1);
  pinMode(PINPWM2, OUTPUT);
  ledcSetup(channel2, frequency, resolution);  // Einstellung des PWM-Kanals
  ledcAttachPin(PINPWM2, channel2);
  //Servomotor
  pinMode(SMOTOR, OUTPUT);
  servo.attach(SMOTOR);
  servo.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:
  
// Fahren mit Servo 
  switch(gear) {
   case DRIVE:
     ledcWrite(channel1,dutycycle);
   break;
   case REVERS:
     ledcWrite(channel2,dutycycle);
   break;
   case NUTRAL:
   break;
  }
 
  int angle = 90;
  switch(direction) {
    case RIGHT:
      angle = 60;
      break;
    case LEFT:
      angle = 120;
      break;
  }
  servo.write(angle);

}
