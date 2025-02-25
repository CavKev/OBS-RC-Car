#include <Arduino.h>

//Servo
#include <ESP32Servo.h>

//Webserver
#include <WiFi.h>
#include <DNSServer.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"

DNSServer dnsServer;
AsyncWebServer server(80);

class CaptiveRequestHandler : public AsyncWebHandler {
  public:
    CaptiveRequestHandler() {}
    virtual ~CaptiveRequestHandler() {}
  
    /**
     * Determines if this handler should handle the given request.
     * By default, this will return true for all requests and handle them.
     * If you want to handle only specific requests, override this and return false
     * for those that should not be handled.
     * @param request the request to check
     * @return true if the request should be handled, false otherwise
     */
    bool canHandle(AsyncWebServerRequest *request){
      //request->addInterestingHeader("ANY");
      return true;
    }
  
/*************  ✨ Codeium Command ⭐  *************/
    /**
     * Handles incoming web server requests and responds with a captive portal page.
     * 
     * This method creates an HTML response stream that presents a simple web page,
     * informing the user that they have reached the captive portal. It includes the
     * original URL the user attempted to reach and provides a link to the network's
     * access point.
     * 
     * @param request The incoming web request to be handled.
     */

/******  6150e7a6-bbf1-4a91-b17e-0346f578afdd  *******/
    void handleRequest(AsyncWebServerRequest *request) {
      AsyncResponseStream *response = request->beginResponseStream("text/html");
      response->print("<!DOCTYPE html><html><head><title>Captive Portal</title></head><body>");
      response->print("<p>This is out captive portal front page.</p>");
      response->printf("<p>You were trying to reach: http://%s%s</p>", request->host().c_str(), request->url().c_str());
      response->printf("<p>Try opening <a href='http://%s'>this link</a> instead</p>", WiFi.softAPIP().toString().c_str());
      response->print("</body></html>");
      request->send(response);
    }
  };

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

  //Webserver
  WiFi.softAP("esp-captive");
  dnsServer.start(53, "*", WiFi.softAPIP());
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  //more handlers...
  server.begin();

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

/**
 * Main loop to control the motor direction based on the current gear setting.
 * 
 * This function is called repeatedly and checks the current gear state:
 * - If the gear is set to DRIVE, it writes the duty cycle to channel1 for forward motion.
 * - If the gear is set to REVERS, it writes the duty cycle to channel2 for reverse motion.
 * - If the gear is set to NUTRAL, no action is taken.
 */

void loop() {
  // put your main code here, to run repeatedly: 
  //Webserver
  dnsServer.processNextRequest();

  //Fahren mit Servo
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

   
}
