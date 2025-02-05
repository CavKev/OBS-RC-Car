#include <Arduino.h>
//here we define the pins
#define LED_GREEN 23
#define LED_RED 22
#define LED_BLUE 21
void led_blink(int pin);
void setup() {
  // put your setup code here, to run once:
  pinMode (LED_GREEN, OUTPUT);
  pinMode (LED_RED, OUTPUT);
  pinMode (LED_BLUE, OUTPUT);
  void led_blink(int pin);  
}

void loop() {
  // put your main code here, to run repeatedly:
  led_blink(LED_GREEN);
  led_blink(LED_RED);
  led_blink(LED_BLUE); 
}

void led_blink(int pin) {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}