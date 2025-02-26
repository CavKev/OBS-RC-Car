#include <Arduino.h>

//Servo
#include <ESP32Servo.h>

//Webserver
#include <WiFi.h>
#include <AsyncTCP.h>
#include <WebServer.h>

//ServoMotor
#define SMOTOR 32
Servo servo;
enum Directions {RIGHT, LEFT, STRAIGHT};
Directions direction = STRAIGHT;

//server
#define HTTP_OKAY 200
#define HTTP_BAD_REQUEST 400
#define HTTP_NOT_FOUND 404

#define TYPE_TEXT "text/plain"
#define TYPE_HTML "text/html"

WebServer server(80);

IPAddress local_ip(192, 168, 0, 1);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

const char* ssid = "RC-Car-Porsche";
const char* password = "Porsche911";
const char* PARAM_MESSAGE = "message";

//allMethods
void setdirection(Directions directionf);
void handle_root();
void send_not_found();
String sendHTML();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  



  //Servomotor
  pinMode(SMOTOR, OUTPUT);

  // Attach the servo motor to the specified pin
  servo.attach(SMOTOR);

  // Set the initial position of the servo motor to 90 degrees
  servo.write(90);

  // Webserver
  WiFi.softAP(ssid, password);
	WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_root);
  server.onNotFound(send_not_found);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly: 
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
void setdirection(Directions directionf) {
  direction = directionf;
}

//Webserver
void handle_root() {
  server.send(HTTP_OKAY, TYPE_HTML, sendHTML());
}

void send_not_found() {
	server.send(HTTP_NOT_FOUND, TYPE_TEXT, "not found");
}

String sendHTML() {
	return "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0, user-scalable=no'><title>ESP32 T1</title><style>html{margin:0px auto; text-align:center;background-color:#000;color:#FFF}.button{min-width:40px; background-color:#000; border:#FF4500 solid 1px; border-radius:4px; padding:13px 30px; font-size:25px; cursor:pointer; transition:background-color 0.2s,color 0.2s;}.button:hover{background-color:#FF4500; color:#000;}.grid{display:grid; row-gap:40px;}.wide-grid{grid-template-columns:auto auto auto; max-width:450px;}.small-grid{grid-template-columns:auto auto; max-width:300px;}.centered{margin:auto; margin-top:20px;}p{margin:0px;}span,p{font-size:30px;}h2{margin-top:60px; margin-bottom:0px;}</style><script>function getRequest(to,target){let req=new XMLHttpRequest();req.open('GET',to,false);req.send(null);if(target!=null){document.getElementById(target).innerHTML=req.responseText;}}</script></head><body><h1>ESP32 T1 control</h1><h2>Lights</h2><div class='centered grid small-grid'><div><span class='button' onclick='getRequest(\"/lights?where=front\",\"lights-front\")'>front</span></div><span id='lights-front'>false</span><div><span class='button' onclick='getRequest(\"/lights?where=back\",\"lights-back\")'>back</span></div><span id='lights-back'>false</span></div><h2>Steering</h1><div><p id='steer'>90</p><div class='centered grid wide-grid'><div><span class='button' onclick='getRequest(\"/steering?angle=30\",\"steer\")'>left</span></div><div><span class='button' onclick='getRequest(\"/steering?angle=0\",\"steer\")'>straight</span></div><div><span class='button' onclick='getRequest(\"/steering?angle=-30\",\"steer\")'>right</span></div></div></div><h2>Motor</h2><div><p id='speed'>0</p><div class='centered grid wide-grid'><div><span class='button' onclick='getRequest(\"/motor?speed=100\",\"speed\")'>forward</span></div><div><span class='button' onclick='getRequest(\"/motor?speed=0\",\"speed\")'>stop</span></div><div><span class='button' onclick='getRequest(\"/motor?speed=-100\",\"speed\")'>backward</span></div></div></div><h2>Autodrive</h2><div><p id=\"autodrive\">false</p><div class='centered'><div><span class='button' onclick='getRequest(\"/toggle_autodrive\", \"autodrive\")'>toggle autodrive</span></div><div></div></body></html>";
}