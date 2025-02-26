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
  
    void handleRequest(AsyncWebServerRequest *request) {
      AsyncResponseStream *response = request->beginResponseStream("text/html");
      response->print("<!DOCTYPE html><html><head><title>Captive Portal</title></head><body>");
      response->print("<p>This is out captive portal front page.</p>");
      response->printf("<p>You were trying to reach: http://%s%s</p>", request->host().c_str(), request->url().c_str());
      response->printf("<p>Try opening <a href='http://%s'>this link</a> instead</p>", WiFi.softAPIP().toString().c_str());
      response->printf("<html><body><button onclick=\"location.href='/setdirection?direction=RIGHT'\">Rechts</button></body></html>");
      request->send(response);
    }
    
    // Add a new handler for the /setdirection request
    void handleSetDirection(AsyncWebServerRequest *request) {
      String direction = request->getParam("direction")->value();
      if (direction == "RIGHT") {
        setdirection(RIGHT);
      } else if (direction == "LEFT") {
        setdirection(LEFT);
      } else if (direction == "STRAIGHT") {
        setdirection(STRAIGHT);
      }
      request->send(200, "text/plain", "Direction set");
    }
    
    // Add the new handler to the server
    server.addHandler(new AsyncCallbackWebHandler("/setdirection", [](AsyncWebServerRequest *request) {
      handleSetDirection(request);
    }));
  };

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
void setdirection(Directions directionf) {
  direction = directionf;
}

void loop() {
  // put your main code here, to run repeatedly: 
  //Webserver
  dnsServer.processNextRequest();

  //Fahren mit Servo
  switch(direction) {
    case RIGHT:
      servo.write(60);
      break;
    case LEFT:
      servo.write(120);
      break;
    case STRAIGHT:
      servo.write(90);
      break;
  }

   
}
