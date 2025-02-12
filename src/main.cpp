#include <Arduino.h>
#include <ESP32Servo.h>

//here we define the pins
#define LED_GREEN 23
#define LED_RED 22
#define LED_BLUE 21

//here we define the functions
void led_blink(int pin);
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode (LED_GREEN, OUTPUT);
  pinMode (LED_RED, OUTPUT);
  pinMode (LED_BLUE, OUTPUT);
  void led_blink(int pin);  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Blinking green LED");
  led_blink(LED_GREEN);
  Serial.println("Blinking red LED");
  led_blink(LED_RED);
  Serial.println("Blinking blue LED");
  led_blink(LED_BLUE); 
}

/**
 * @brief Blinks an LED connected to the specified pin.
 *
 * This function sets the specified pin to HIGH for 500 milliseconds, 
 * then sets it to LOW for 500 milliseconds, creating a blinking effect. 
 * It assumes the pin has been configured as an OUTPUT.
 *
 * @param pin The pin number connected to the LED.
 */

void led_blink(int pin) {
  Serial.print("Blinking LED connected to pin ");
  Serial.println(pin);
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}
